#include "tree.h"
#include "token_info.h"
#include "symbol_table.h"
#include "stack.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//verifies if list of global var is not declared nor a string vector and adds them to hashtable
int add_var(STACK *stack, char *type, node_t *nodo1, node_t *nodo2, TOKEN_INFO *valor1, TOKEN_INFO *valor2)
{
    node_t *nodo;
    node_t *aux;
    HASH_TBL *entry;

    if ((strcmp(type, "global_static") == 0) || (strcmp(type, "global_non_static") == 0))
    {

        int tipo = atoi(nodo1->label);
        libera_nodo(nodo1);

        nodo = nodo2;
        do
        {
            entry = lookup_declaration(stack, nodo->label);
            if (entry != NULL)
            {
                printf("ERROR: Variable redefinition %s in line %d. Already declared in line %d \n", nodo->label, nodo->value->linha, entry->content->linha);

                return ERR_DECLARED;
            }
            else
            {
                CONTEUDO *conteudo = malloc(sizeof(CONTEUDO));

                conteudo->linha = nodo->value->linha;
                if (nodo->tam == -1)
                {
                    conteudo->natureza = 1; // 1 = C_VAR
                }
                else
                {
                    conteudo->natureza = 3; // 3 = C_VET
                }
                conteudo->tipo = tipo;
                if (strcmp(type, "global_static") == 0)
                {
                    conteudo->static_var = 1;
                }
                else
                {
                    conteudo->static_var = 0;
                }
                conteudo->const_var = 0;
                int vec_tam = 1;
                if (nodo->tam != -1)
                    vec_tam = nodo->tam;
                conteudo->tamanho = get_var_size_by_type(tipo) * vec_tam;
                conteudo->argumentos = NULL;
                conteudo->valor = nodo->value;

                if (conteudo->natureza == 3 && conteudo->tipo == 4)
                {

                    printf("ERROR: Cannot declare a string vector! Variable %s in line %d \n", nodo->label, nodo->value->linha);

                    return ERR_STRING_VECTOR;
                }

                add_entry(stack, nodo->label, conteudo); // faz stdup no label
            }
            aux = nodo;
            nodo = nodo->next_cmd;
            free(aux->label);
            free(aux);

        } while (nodo != NULL);

    } 

    return 0;
}

// checks if an identifier in an expression is a declared variable and sets node->tipo to its correct type
int verify_exp_ident(STACK *stack, char *type, node_t *nodo)
{

    HASH_TBL *entry = lookup_stack(stack, nodo->label);

    if (entry == NULL)
    {
        if (strcmp(type, "var") == 0)
        {
            printf("ERROR: Variable %s undeclared in line %d \n", nodo->label, nodo->value->linha);
        }
        else if (strcmp(type, "vector") == 0)
        {
            printf("ERROR: Vector %s undeclared in line %d \n", nodo->label, nodo->value->linha);
        }
        else if (strcmp(type, "function") == 0)
        {
            printf("ERROR: Function %s undeclared in line %d \n", nodo->label, nodo->value->linha);
        }

        return ERR_UNDECLARED;
    }
    else
    {

        if (strcmp(type, "var") == 0)
        {

            if (entry->content->natureza == C_FUNC)
            {

                printf("ERROR: Function %s is used as variable in line %d \n", nodo->label, nodo->value->linha);

                return ERR_FUNCTION;
            }
            else if (entry->content->natureza == C_VET)
            {

                printf("ERROR:Vector %s is used as variable in line %d \n", nodo->label, nodo->value->linha);

                return ERR_VECTOR;
            }
        }
        else if (strcmp(type, "vector") == 0)
        {

            if (entry->content->natureza == C_FUNC)
            {

                printf("ERROR: Function %s is used as vector in line %d \n", nodo->label, nodo->value->linha);

                return ERR_FUNCTION;
            }
            else if (entry->content->natureza == C_VAR)
            {

                printf("ERROR:Variable %s is used as vector in line %d \n", nodo->label, nodo->value->linha);

                return ERR_VARIABLE;
            }
        }
        else if (strcmp(type, "function") == 0)
        {

            if (entry->content->natureza == C_VET)
            {

                printf("ERROR: Vector %s is used as function in line %d \n", nodo->label, nodo->value->linha);

                return ERR_VECTOR;
            }
            else if (entry->content->natureza == C_VAR)
            {

                printf("ERROR: Variable %s is used as function in line %d \n", nodo->label, nodo->value->linha);

                return ERR_VARIABLE;
            }
        }

        nodo->tipo = entry->content->tipo;
    }

    return 0;
}

// sets parent->tipo according to the type conversions
int binary_type_inference(node_t *parent, node_t *left, node_t *right)
{

    int tipoL = left->tipo;
    int tipoR = right->tipo;
    //int int = int
    // float float = float
    // bool bool = bool
    // float int = float
    // bool float = float
    // bool int = int

    if (tipoL == N_INT && tipoR == N_INT)
    {

        parent->tipo = N_INT;
    }
    else if (tipoL == N_FLOAT && tipoR == N_FLOAT)
    {

        parent->tipo = N_FLOAT;
    }
    else if (tipoL == N_BOOLEAN && tipoR == N_BOOLEAN)
    {

        parent->tipo = N_BOOLEAN;
    }
    else if (tipoL == N_CHAR && tipoR == N_CHAR)
    {

        parent->tipo = N_CHAR;
    }
    else if (tipoL == N_STRING && tipoR == N_STRING)
    {

        parent->tipo = N_STRING;
    }
    else if ((tipoL == N_FLOAT && tipoR == N_INT) || (tipoL == N_INT && tipoR == N_FLOAT))
    {

        parent->tipo = N_FLOAT;
    }
    else if ((tipoL == N_FLOAT && tipoR == N_BOOLEAN) || (tipoL == N_BOOLEAN && tipoR == N_FLOAT))
    {

        parent->tipo = N_FLOAT;
    }
    else if ((tipoL == N_BOOLEAN && tipoR == N_INT) || (tipoL == N_INT && tipoR == N_BOOLEAN))
    {

        parent->tipo = N_INT;
    }
    else if ((tipoL == N_STRING && tipoR != N_STRING) || (tipoL != N_STRING && tipoR == N_STRING))
    {

        printf("ERROR: Operation %s in line %d, String cannot be converted to other data types. \n", parent->label, parent->value->linha);

        return ERR_STRING_TO_X;
    }
    else if ((tipoL == N_CHAR && tipoR != N_CHAR) || (tipoL != N_CHAR && tipoR == N_CHAR))
    {

        printf("ERROR: Operation %s in line %d, Char cannot be converted to other data types. \n", parent->label, parent->value->linha);

        return ERR_CHAR_TO_X;
    }

    return 0;
}

// sets parent->tipo according to the type conversions
int unary_type_inference(node_t *parent, node_t *son)
{
    

    if ((strcmp(parent->label, "?") == 0) || (strcmp(parent->label, "!") == 0))
    {

        if (son->tipo == N_CHAR)
        {
            printf("ERROR: Operation %s in line %d, Char cannot be converted to boolean \n", parent->label, parent->value->linha);

            return ERR_CHAR_TO_X;
        }
        else if (son->tipo == N_STRING)
        {
            printf("ERROR: Operation %s in line %d, String cannot be converted to boolean \n", parent->label, parent->value->linha);

            return ERR_STRING_TO_X;
        }
    }

    parent->tipo = son->tipo;

    return 0;
}
int verify_shift_size(TOKEN_INFO *token){
    if(token->valor.i > 16){
        printf("ERROR: In line %d, cannot shift with value higher than 16. \n", token->linha);

        return ERR_WRONG_PAR_SHIFT;
    }
    return 0;
}

// verify the tipe of the identifier before the input and output commands.
int verify_type_io(STACK *stack, TOKEN_INFO *token, char *type, int is_lit)
{
    if (!is_lit) // se o io tem um identificador
    {

        HASH_TBL *entry = lookup_stack(stack, token->valor.s);
        if (entry == NULL)
        {
            printf("ERR: Undeclared identifier %s on line %d.\n", token->valor.s, token->linha);
            return ERR_UNDECLARED;
        }
        if (entry->content->tipo > 1)
        {
            if (strcmp(type, "input") == 0){
                printf("ERROR: Command input in line %d can only be of type INT or FLOAT.\n", token->linha);
                return ERR_WRONG_PAR_INPUT;
            }
            else{
                printf("ERROR: Command output in line %d can only be of type INT or FLOAT.\n", token->linha);
                return ERR_WRONG_PAR_OUTPUT;
            }
        }
    }
    else
    {
        if (token->tipo_lit != FLOAT && token->tipo_lit != INT)
        {   
            printf("ERROR: Command output in line %d can only be of type INT or FLOAT.\n", token->linha);
            return ERR_WRONG_PAR_OUTPUT;
        }
    }
    return 0;
}

// function to add function declaration to hash table. Assumes the top of the stack is the scope of the function. identificador: name of the function, node: tipo on parser
int add_function_to_table(STACK *stack, TOKEN_INFO *indentificador, node_t *node, int static_func, node_t *func_params)
{ 
    int tipo = atoi(node->label);
    libera_nodo(node);

    if (tipo == N_STRING)
    {
        printf("ERR: Function %s cannot return string\n", indentificador->valor.s);
        return ERR_FUNCTION_STRING;
    }
    // função não pode retornar string

    CONTEUDO *conteudo = malloc(sizeof(CONTEUDO));
    conteudo->tipo = tipo;
    conteudo->natureza = C_FUNC;
    conteudo->static_var = static_func;
    conteudo->const_var = 0;
    conteudo->linha = indentificador->linha;
    conteudo->valor = NULL; 
    conteudo->tamanho = 0;  

    node_t *param = func_params;
    LIST *params_list = create_list();

    node_t *aux;

    while (param != NULL)
    {
        
        HASH_TBL *entry = lookup_declaration(stack, param->label);
        int param_type = entry->content->tipo;
      
        if (param_type == N_STRING)
            return ERR_FUNCTION_STRING; // argumento de função não pode ser string
        add_to_list(&params_list, param->label, param_type);

        aux = param;
        param = param->next_cmd;
        libera_nodo(aux);

    }

    conteudo->argumentos = params_list;

    add_entry(stack->next, indentificador->valor.s, conteudo);
    return 0;
}

// function to variable declaration. ident is the identifier, var_value is the value used to initialize the variable in its declaration
int verify_var_declaration(STACK *stack, TOKEN_INFO *ident, int type, node_t *var_value, int is_static, int is_const)
{
    HASH_TBL *entry = lookup_declaration(stack, ident->valor.s); // pode dar override em escopos maiores, mas não no atual
    if (entry != NULL)                                           // redeclaração de variável
    {
        printf("ERR: In line %d, variable %s already declared on line %d\n", ident->linha, ident->valor.s, entry->content->linha);
        return ERR_DECLARED;
    }
    else
    {
        int tipo = type;

        CONTEUDO *content = malloc(sizeof(CONTEUDO));
        content->tipo = tipo;
        content->natureza = C_VAR;
        content->static_var = is_static;
        content->const_var = is_const;
        content->linha = ident->linha;
        content->valor = ident; // verificar se isso for um identificador se isso já tá declarado
        if (var_value != NULL && var_value->value->tipo == IDENT)
        {
            HASH_TBL *initial_ident;
            int used = verify_used_ident(stack, var_value->value, &initial_ident, 0, 0);
            if (used != 0)
            {
                return ERR_UNDECLARED;
            } // se to inicializando uma variavel com outra variavel precisa verificar se são tipos compativeis
            if (!check_type_compatibility(initial_ident->content->tipo, tipo))
            {
                printf("ERR: Assigning incompatible types from %s to %s on line %d.\n", print_type(initial_ident->content->tipo), print_type(tipo), ident->linha);
                return ERR_WRONG_TYPE; // não tenho certeza se esse é o erro certo
            };
        }
        else if (var_value != NULL && var_value->value->tipo == LIT)
        {
            if ((var_value->value->tipo_lit == CHAR && tipo != N_CHAR) || (var_value->value->tipo_lit != CHAR && tipo == N_CHAR))
            {

                printf("ERROR: In line %d, incompatible types between variable %s and literal %s \n", ident->linha, ident->valor.s, var_value->label);
                return ERR_CHAR_TO_X; 
            }
            else if ((var_value->value->tipo_lit == STRING && tipo != N_STRING) || (var_value->value->tipo_lit != STRING && tipo == N_STRING))
            {

                printf("ERROR: In line %d, incompatible types between variable %s and literal %s \n", ident->linha, ident->valor.s, var_value->label);

                return ERR_STRING_TO_X;

            } 
        }
        content->argumentos = NULL;
        
        content->tamanho = get_var_size_by_type(tipo);
        if ( tipo == 4 && var_value != NULL){ //caso de strings
            content->tamanho = strlen(var_value->label); // "All string literals have an implicit null-terminator"
        }
        
        add_entry(stack, ident->valor.s, content);
    }
    return 0;
}

// function to test if a used identifier is declared in the scope. returns the entry in the entry field
int verify_used_ident(STACK *stack, TOKEN_INFO *ident, HASH_TBL **entry, int used_as_vector, int used_as_function)
{
    *entry = lookup_stack(stack, ident->valor.s);
    if (*entry == NULL)
    {
        printf("ERROR: Identifier %s undeclared in line %d.\n", ident->valor.s, ident->linha);
        return ERR_UNDECLARED;
    }
    if (used_as_vector)
    { // se é vetor e tá sendo usado como variavel
        if ((*entry)->content->natureza == C_VET)
            return 0;
        else
        {
            printf("ERROR: %s in line %d is a %s, not a VECTOR.\n", (*entry)->name, ident->linha, print_natureza((*entry)->content->natureza));
            return ERR_VECTOR;
        }
    }
    else if (used_as_function)
    {
        if ((*entry)->content->natureza == C_FUNC)
            return 0;
        else
        {
            printf("ERROR: %s in line %d is a %s, not of type FUNCTION.\n", (*entry)->name, ident->linha, print_natureza((*entry)->content->natureza));
            return ERR_FUNCTION;
        }
    }
    else
    {
        if ((*entry)->content->natureza == C_VAR)
            return 0;
        else
        {
            printf("ERROR: %s in line %d is a %s, not of type VARIABLE.\n", (*entry)->name, ident->linha, print_natureza((*entry)->content->natureza));
            return ERR_VARIABLE;
        }
    }
    return 0;
}

// get the size of a ver for type
int get_var_size_by_type(int type)
{
    switch (type)
    {
    case N_INT:
        return 4;
    case N_FLOAT:
        return 8;
    case N_BOOLEAN:
        return 1;
    case N_CHAR:
        return 1;
    case N_STRING:
        return 0; // uma string não inicializada ocupa 0 bytes
    }
}

// add to hash table function arguments
int add_func_arg_to_table(STACK *stack, TOKEN_INFO *identificador, node_t *type, int is_const)
{
    int tipo = atoi(type->label);
    libera_nodo(type);

    CONTEUDO *content = malloc(sizeof(CONTEUDO));
    content->argumentos = NULL;
    content->const_var = is_const;
    content->linha = identificador->linha;
    content->natureza = C_VAR;
    content->static_var = 0;
    content->tamanho = get_var_size_by_type(tipo);
    content->tipo = tipo;
    content->valor = NULL; // argumento de função não tem valor ainda
    if (tipo == N_STRING)
    {
        free(content);
        printf("ERROR: function argument %s in line %d cannot be of type STRING.\n", identificador->valor.s, identificador->linha);
        return ERR_FUNCTION_STRING;
    }
    add_entry(stack, identificador->valor.s, content);
    return 0;
}

// check if an attribution is possible
int cmd_attrib(STACK *stack, TOKEN_INFO *ident, node_t *exp_value, int is_vector)
{
    int exp_type = exp_value->tipo;

    HASH_TBL *id_entry;
    int id_valid = verify_used_ident(stack, ident, &id_entry, is_vector, 0);
    if (id_valid > 0)
    {
        return id_valid;
    }

    int var_type = id_entry->content->tipo;

    if (var_type != exp_type)
    {
        if (!check_type_compatibility(var_type, exp_type))
        {
            printf("ERROR: cannot assign type %s to type %s in line %d.\n", print_type(exp_type), print_type(var_type), ident->linha);
            return ERR_WRONG_TYPE;
        }
    }
    if (exp_type == N_STRING)
    {
      
        if( strlen(exp_value->label) > id_entry->content->tamanho ){ // only works if exp_value is literal
            printf("ERROR: string reassignment cannot excede size of %d \n", id_entry->content->tamanho);

            return ERR_STRING_MAX;
        }
    }
    return 0;
}

// check if a for loop is valid (not used yet)
int check_for_loop(STACK *stack, node_t *node)
{
    if (node->n_child < 3)
    {
        printf("ERR: Invalid for in line %d.\n", node->value->linha);
        return 99;
    }
    node_t *attrib = node->children[0];
    node_t *condition = node->children[1];
    node_t *increment = node->children[2];

    // checa atribuição
    int attrib_valid = cmd_attrib(stack, attrib->children[0]->value, attrib->children[1], 0);
    if (attrib_valid != 0)
    {
        return attrib_valid;
    }

    int condition_valid = condition->tipo;
    if (condition_valid != BOOLEAN)
    {
        printf("ERR: for condition does not evaluate to boolean in line %d.\n", node->value->linha);
    }

    int increment_valid = cmd_attrib(stack, increment->children[0]->value, attrib->children[1], 0);
    if (increment_valid != 0)
    {
        return increment_valid;
    }

    return 0;
}

// check if a while loop is valid (not used yet)
int check_while(STACK *stack, node_t *node)
{
    node_t *while_exp = node->children[0];
    int exp_type = while_exp->tipo;
    if (exp_type != BOOLEAN)
    {
        printf("ERR: while-do condition does not evaluate to boolean in line %d.\n", node->value->linha);
    }
}

// check if function call is correct
int function_call(STACK *stack, node_t *node)
{
    // o primeiro filho é os args, pra cada arg pode ter next_cmd arg
    HASH_TBL *func_entry;
    int func_identifier_valid = verify_used_ident(stack, node->value, &func_entry, 0, 1);

    if (func_identifier_valid != 0)
        return func_identifier_valid;
    node_t *func_called_param = NULL;
    if (node != NULL && node->n_child > 0)
        func_called_param = node->children[0];
    LIST *func_params = func_entry->content->argumentos;
    if (func_params == NULL)
    {
        printf("func params é null\n");
    }
    while (func_params != NULL && func_called_param != NULL)
    {
        if (!check_type_compatibility(func_called_param->tipo, func_params->type))
        {
            printf("ERR: Wrong parameter on function call on line %d, expected %s but %s is of type %s.\n", node->value->linha, print_type(func_params->type), func_called_param->label, print_type(func_called_param->tipo));
            return ERR_WRONG_TYPE_ARGS;
        }
        func_params = func_params->next;
        func_called_param = func_called_param->next_cmd;
    }
    if (func_params == NULL && func_called_param == NULL)
    {
        return 0;
    }
    else if (func_params != NULL)
    {
        printf("ERR: Too few arguments in function call on line %d.\n", node->value->linha);
        return ERR_MISSING_ARGS;
    }
    else
    {
        printf("ERR: Too much arguments in function call on line %d.\n", node->value->linha);
        return ERR_EXCESS_ARGS;
    }
    return 0;
}

int verify_function_return(STACK *stack, node_t *exp, int f_type)
{
    int return_type = exp->tipo;

    if (!check_type_compatibility(return_type, f_type))
    {
        printf("ERR: Wrong return type, expected %s but the return is of type %s.\n", print_type(f_type), print_type(return_type));
        return ERR_WRONG_PAR_RETURN;
    }

    return 0;
}

// check if two types are compatible
int check_type_compatibility(int type1, int type2)
{
    // N_INT, N_FLOAT,N_BOOLEAN, N_CHAR, N_STRING, N_UNDEFINED
    if (type1 < 3)
    {
        if (type2 < 3)
            return 1;
    }
    else if (type1 == N_STRING && type2 == N_STRING)
        return 1;
    else if (type1 == N_CHAR && type2 == N_CHAR)
        return 1;
    return 0;
}

char *print_type(int type)
{
    switch (type)
    {
    case N_INT:
        return "INT";
    case N_FLOAT:
        return "FLOAT";
    case N_BOOLEAN:
        return "BOOLEAN";
    case N_CHAR:
        return "CHAR";
    case N_STRING:
        return "STRING";
    case N_UNDEFINED:
        return "UNDEFINED";
    default:
        return "unknown";
    }
}

char *print_natureza(int type)
{
    switch (type)
    {
    case C_LIT:
        return "LITERAL";
    case C_VAR:
        return "VARIABLE";
    case C_FUNC:
        return "FUNCTION";
    case C_VET:
        return "VECTOR";
    default:
        return "unkwnown";
    }
}