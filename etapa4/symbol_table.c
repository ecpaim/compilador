#include "tree.h"
#include "token_info.h"
#include "symbol_table.h"
#include "stack.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
                printf("ERRO: Redeclaracao de variavel %s na linha %d ja declarada na linha %d", nodo->label, nodo->value->linha, entry->content->linha);

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
                switch (tipo)
                {
                case N_INT:
                    conteudo->tamanho = 4 * vec_tam; // em bytes
                    break;
                case N_FLOAT:
                    conteudo->tamanho = 8 * vec_tam;
                    break;
                case N_BOOLEAN:
                    conteudo->tamanho = 1 * vec_tam;
                    break;
                case N_CHAR:
                    conteudo->tamanho = 1 * vec_tam;
                    break;
                case N_STRING:
                    conteudo->tamanho = 1 * vec_tam;
                    break;
                }
                conteudo->argumentos = NULL;
                conteudo->valor = nodo->value;

                add_entry(stack, nodo->label, conteudo); // faz stdup no label
            }
            aux = nodo;
            nodo = nodo->next_cmd;
            free(aux->label);
            free(aux);

        } while (nodo != NULL);

    } // aqui da pra colocar outros ifs pra outras regras do parser.y

    return 0;
}

// verify the tipe of the identifier before the input and output commands.
int verify_type_io(STACK *stack, TOKEN_INFO *token, char *type, int is_lit)
{
    if (is_lit)
    {

        HASH_TBL *entry = lookup_stack(stack, token->valor.s);
        if (entry->content->tipo > 1)
        {
            if (strcmp(type, "input") == 0)
                return ERR_WRONG_PAR_INPUT;
            else
                return ERR_WRONG_PAR_OUTPUT;
        }
    }
    else
    {
        if (token->tipo_lit != FLOAT && token->tipo_lit != INT)
        {
            return ERR_WRONG_PAR_OUTPUT;
        }
    }
    return 0;
}

// function to add function declaration to hash table. Assumes the top of the stack is the scope of the function
int add_function_to_table(STACK *stack, TOKEN_INFO *indentificador, node_t *node, int static_func, node_t *func_params)
{
    int tipo = atoi(node->tipo);
    if (tipo == N_STRING)
        return ERR_FUNCTION_STRING;
    // função não pode retornar string

    CONTEUDO *conteudo = malloc(sizeof(CONTEUDO));
    conteudo->tipo = tipo;
    conteudo->natureza = C_FUNC;
    conteudo->static_var = static_func;
    conteudo->const_var = 0;
    conteudo->linha = indentificador->linha;
    conteudo->valor = NULL; // qual o valor de uma função?
    conteudo->tamanho = 0;  // qual o tamanho da função?
    node_t *param = func_params;
    LIST *params_list = create_list();

    while (param != NULL)
    {
        int param_type = atoi(param->tipo);
        if (param_type == N_STRING)
            return ERR_FUNCTION_STRING; // argumento de função não pode ser string
        add_to_list(params_list, param->label, param_type);
        param = param->next_cmd;
        // eles ja são adicionados na tabela no parser.y
    }
    add_entry(stack, indentificador->valor.s, conteudo);
    return 0;
}

// function to variable declaration. ident is the identifier, var_value is the value used to initialize the variable in its declaration
int verify_var_declaration(STACK *stack, TOKEN_INFO *ident, node_t *var_value, int is_static, int is_const)
{
    HASH_TBL *entry = lookup_declaration(stack, ident->valor.s); // pode dar override em escopos maiores, mas não no atual
    if (entry != NULL)                                           // redeclaração de variável
    {
        return ERR_DECLARED;
    }
    else
    {
        int tipo = atoi(var_value->tipo);
        CONTEUDO *content = malloc(sizeof(CONTEUDO));
        content->tipo = tipo;
        content->natureza = C_VAR;
        content->static_var = is_static;
        content->const_var = is_const;
        content->linha = ident->linha;
        content->valor = var_value->value; // verificar se isso for um identificador se isso já tá declarado
        if(var_value->value->tipo == IDENT)
        {
            HASH_TBL* initial_ident;
            int used = verify_used_ident(stack, var_value->value, initial_ident);
            if( used != 0 )
                return ERR_UNDECLARED;
        }
        content->argumentos = NULL;
        switch (tipo) {
            case N_INT:
                content->tamanho = 4;
                break;
            case N_FLOAT:
                content->tamanho = 8;
                break;
            case N_BOOLEAN:
                content->tamanho = 1;
                break;
            case N_CHAR:
                content->tamanho = 1;
                break;
            case N_STRING:
                content->tamanho = 1; // isso aqui tem q ser mudado pra inicialização de variáveis
                break;
        }
        add_entry(stack, ident->valor.s, content);
    }
    return 0;
}

// function to test if a used identifier is declared in the scope. returns the entry in the entry field
int verify_used_ident(STACK *stack, TOKEN_INFO *ident, HASH_TBL* entry)
{
    entry = lookup_stack(stack, ident->valor.s);
    if (entry == NULL)
    {
        return ERR_UNDECLARED;
    }
    return 0;
}
