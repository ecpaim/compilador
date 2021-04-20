#include "iloc_generator.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int deslocamento_rfp = 0;
int deslocamento_rbss = 0;
int deslocamento_rsp = 0;

char *create_register(){

    static int register_number = 0;

    char nome[32];

    sprintf(nome,"r%d",register_number);

    char* r = malloc(strlen(nome)+1);

    strcpy(r,nome);

    register_number++;

    return r;
}

char *create_label(){

    static int label_number = 0;

    char nome[16];

    sprintf(nome,"L%d",label_number);

    char* l = malloc(strlen(nome)+1);

    strcpy(l,nome);

    label_number++;

    return l;
}

CODE_BLOCK* create_code(){

    CODE_BLOCK *new_code = malloc(sizeof(CODE_BLOCK));

    new_code->code = strdup("loadI 2048 => rfp \nloadI 2048 => rsp \n");
    new_code->number_of_lines = 2;
    new_code->previous = NULL;
    new_code->next = NULL;

    return new_code;
}

CODE_BLOCK* create_block(char *code, int n_lines){
    CODE_BLOCK *new_code = malloc(sizeof(CODE_BLOCK));
    new_code->code = code;
    new_code->number_of_lines = n_lines;
    new_code->previous = NULL;
    new_code->next = NULL;
    new_code->r = NULL;

    return new_code;
}

// returns pointer to the last instruction of the code
CODE_BLOCK* concat_iloc_code(CODE_BLOCK *parent, CODE_BLOCK *new_code){

    if(new_code == NULL){
        return parent;
    } else if(parent == NULL){
        return new_code;
    }

    CODE_BLOCK* first_new_instruction = new_code;

    while(first_new_instruction->previous != NULL){
        first_new_instruction =first_new_instruction->previous;
    }


    parent->next = first_new_instruction;
    first_new_instruction->previous = parent;

    return new_code;
}


// global variables dont produce any iloc code so we just update the offset of rbss
int ILOC_add_global_var(STACK *stack, char *type, node_t *nodo1, node_t *nodo2){

    int r = add_var(stack, type, nodo1, nodo2, NULL, NULL, &deslocamento_rbss);


    return r;
}


int ILOC_add_func_arg(STACK* stack, TOKEN_INFO* identificador, node_t *type, int is_const){

    int r = add_func_arg_to_table( stack, identificador, type, is_const, deslocamento_rfp);

    deslocamento_rfp += 4; // so usamos o  tipo INT

    return r;
}

// the variables defined in the func header are stored after all param values
void update_args_offset(STACK *stack, char *func_name, int list_size, char *label){

    HASH_TBL *entry = lookup_stack(stack, func_name);

    LIST *func_params = entry->content->argumentos;

    entry->content->func_label = label;

    int initial_offset = 16 + list_size*4;

    while(func_params != NULL){
        HASH_TBL *arg = lookup_declaration(stack, func_params->label);

        arg->content->deslocamento = initial_offset;

        initial_offset += 4;

        func_params = func_params->next;
    }

}

int ILOC_add_function(STACK *stack, TOKEN_INFO *indentificador, node_t *node, int static_func, node_t *func_params, node_t *parent){

    if(strcmp(indentificador->valor.s, "main") == 0) // main não precisa guardar endereço retorno, rsp e rfp antigo ou valor de retorno
        deslocamento_rfp = 0;

    int list_size = 0;

    int r = add_function_to_table(stack, indentificador, node, static_func, func_params, deslocamento_rbss, &list_size);

    char *label = create_label(); // the function label

    update_args_offset(stack, indentificador->valor.s, list_size, label);

    deslocamento_rbss += 4;

    /*
        rfp+0: endereço de retorno
        rfp+4: rsp antigo
        rfp+8: rfp antigo
        rfp+12: valor do retorno (só é escrito no fim da função)
        rfp+16: valor do parametro 1
        rfp+20: valor do parametro 2 
        rfp+24: valor da variavel 1 (que é igual ao valor do parametro 1)
        rfp+28: valor da variavel 2 (que é igual ao valor do parametro 2)
    */

    int n_of_lines = 3 + 2*list_size;

    char *code = malloc(n_of_lines*128); // each instruction can have at max 128 characters

    sprintf(code, "%s: \ni2i rsp => rfp \naddI rsp, %d => rsp \n", label, deslocamento_rfp + 4*list_size);

    char *new_reg = create_register();
    int param_offset = 16;

    for(int i = 0; i < list_size; i++){
        char line[256];
        sprintf(line, "loadAI rfp, %d => %s \nstoreAI %s => rfp, %d \n", param_offset, new_reg, new_reg, deslocamento_rfp);
        deslocamento_rfp += 4;
        param_offset += 4;

        strcat(code, line);
    }
    free(new_reg);

    //printf("\ncode: \n%s \nn lines: %d \n",code, n_of_lines);

    CODE_BLOCK *new_block = create_block(code, n_of_lines);
   
    parent->code = new_block;

    return r;
}

STACK *ILOC_put_stack(STACK *stack, char *type){

    stack = put_stack(stack);
    
    if(strcmp(type,"function") == 0){

        deslocamento_rfp = 16; // after return address, rsp and rfp values, return value
    }

    return stack;
}


CODE_BLOCK *ILOC_add_func_code(node_t *header, node_t *block, CODE_BLOCK *iloc_code, STACK *stack, char *return_label){
    if(strcmp(header->label, "main") == 0){

        

        /* adds jumpI => Lmain to code*/
        HASH_TBL *entry = lookup_stack(stack, header->label);

        char *func_label = entry->content->func_label;

        char *line = malloc(1*128);

        sprintf(line,"jumpI => %s\n",func_label);


        CODE_BLOCK *jump_to_main = create_block(line, 1);

        CODE_BLOCK *final_code = iloc_code;

        while( final_code->previous != NULL){
            final_code = final_code->previous;
        }

        jump_to_main->next = final_code->next;
        jump_to_main->previous = final_code;
        if(final_code->next != NULL){
            final_code->next->previous = jump_to_main;
        } else {
            iloc_code = jump_to_main;
        }
        final_code->next = jump_to_main;

        /* the main function doesn't have instructions to jump to return address */

        char *halt_code = strdup("halt\n");

        CODE_BLOCK *halt_block = create_block(halt_code, 1);

        CODE_BLOCK *func_body;
        if( block != NULL){
            func_body = concat_iloc_code(block->code, halt_block);
        } else {
            func_body = concat_iloc_code(NULL, halt_block);
        }

        CODE_BLOCK *all_function = concat_iloc_code(header->code, func_body);

        return concat_iloc_code(iloc_code, all_function);

    } else {

        char *r0 = create_register();
        char *r1 = create_register();
        char *r2 = create_register();

        char *code = malloc(6*128);

        sprintf(code, "%s: \nloadAI rfp, 0 => %s \nloadAI rfp, 4 => %s \nloadAI rfp, 8 => %s \ni2i %s => rsp \ni2i %s => rfp \njump => %s \n",
            return_label, r0, r1, r2, r1, r2, r0);

        free(r0);
        free(r1);
        free(r2);

        CODE_BLOCK *return_inst = create_block(code, 7);

        CODE_BLOCK *func_body;

        if( block != NULL){
            func_body = concat_iloc_code(block->code, return_inst);
        } else {
            func_body = concat_iloc_code(NULL, return_inst);
        }
        
        CODE_BLOCK *all_function = concat_iloc_code(header->code, func_body);
         
        return concat_iloc_code(iloc_code, all_function);

    }


}

int ILOC_function_return(STACK *stack, node_t *child, int f_type, char *return_label, node_t* parent){

    int r = verify_function_return(stack, child, f_type);

    if(r != 0){
        return r;
    }

    char *line = malloc(2*128);

    sprintf(line, "storeAI %s => rfp, 12 \njumpI => %s \n",child->code->r, return_label);

    CODE_BLOCK *return_block = create_block(line, 2);

    parent->code = concat_iloc_code(child->code, return_block);

    return 0;
}

int ILOC_function_call(STACK *stack, node_t *node, node_t *args){

    int r = function_call(stack, node);
    if(r!=0) 
        return r;

    HASH_TBL *entry = lookup_stack(stack, node->label);

    char *func_label = entry->content->func_label; // label da função

    char *return_reg = create_register(); // registrador com endereço de retorno

    int return_offset = 4;

    char *initial_code = malloc(3*128);

    sprintf(initial_code, "storeAI %s => rsp, 0 \nstoreAI rsp => rsp, 4 \nstoreAI rfp => rsp, 8 \n", return_reg);

    CODE_BLOCK *initial_block = create_block(initial_code, 3);

    int rsp_offset = 16; // 16, não 12 porque rsp+12 guarda o valor de retorno

    while(args != NULL){ // adiciona código de cada parametro

        CODE_BLOCK *arg_block = args->code; // supondo que todos os nodos exp tenham esse valor

        char *arg_reg = arg_block->r;

        char *arg_param = malloc(1*128);

        sprintf(arg_param, "storeAI %s => rsp, %d \n", arg_reg, rsp_offset);
        rsp_offset += 4;

        CODE_BLOCK *param_block = create_block(arg_param, 1);

        arg_block = concat_iloc_code(arg_block, param_block);

        initial_block = concat_iloc_code(initial_block, arg_block);

        return_offset += arg_block->number_of_lines + 1;

        args = args->next_cmd;
    }

    char *jump_code = malloc(2*128);

    char *return_value = create_register();

    sprintf(jump_code,"jumpI => %s \nloadAI rsp, 12 => %s \n", func_label, return_value);

    CODE_BLOCK *jump_block = create_block(jump_code, 2);

    return_offset += 1;

    initial_block = concat_iloc_code(initial_block, jump_block);

    char *return_addr = malloc(1*128);

    sprintf(return_addr, "addI rpc, %d => %s \n", return_offset, return_reg);

    CODE_BLOCK *return_block = create_block(return_addr, 1);

    initial_block = concat_iloc_code(return_block, initial_block);

    node->code = initial_block;

    node->code->r = return_value;

    free(return_reg);

    return 0;
}

// se o nodo é um token literal ou identificador cria o código correspondente
node_t *ILOC_cria_nodo(char *label, TOKEN_INFO *valor_lexico, char *type, STACK *stack){

    node_t *r = cria_nodo(label, valor_lexico);

    if(strcmp(type,"ident") == 0){

        char *line = malloc(1*128);

        HASH_TBL *entry = lookup_stack(stack, r->label);

        char *ident_reg = create_register();

        if(entry->content->is_global > 0){
            sprintf(line, "loadAI rbss, %d => %s \n", entry->content->deslocamento, ident_reg);

        } else {
            sprintf(line, "loadAI rfp, %d => %s \n", entry->content->deslocamento, ident_reg);
        }
        

        CODE_BLOCK *ident_block = create_block(line, 1);

        ident_block->r = ident_reg;

        r->code = ident_block;

    } else if(strcmp(type,"lit") == 0){

        char *line = malloc(1*128);

        char *lit_reg = create_register();

        sprintf(line, "loadI %s => %s \n", label, lit_reg);

        CODE_BLOCK *lit_block = create_block(line, 1);

        lit_block->r = lit_reg;

        r->code = lit_block;
    }


    return r;
}


int ILOC_verify_var_declaration(STACK *stack, TOKEN_INFO *ident, int type, node_t *var_value, int is_static, int is_const){

    int r = verify_var_declaration(stack, ident, type, var_value, is_static, is_const);

    HASH_TBL *entry = lookup_declaration(stack, ident->valor.s);

    entry->content->deslocamento = deslocamento_rfp;

    deslocamento_rfp += 4;

    return r;
}


void ILOC_add_local_var(node_t *parent, node_t *ident, node_t *initializer, char *type, STACK *stack){

    char *line = malloc(1*128);

    sprintf(line,"addI rsp, 4 => rsp \n");

    CODE_BLOCK *declr_block = create_block(line, 1);

    if(strcmp(type, "initialized") == 0){

        HASH_TBL *entry = lookup_declaration(stack, ident->label);

        char *attr = malloc(1*128);

        sprintf(attr,"storeAI %s =>rfp, %d \n", initializer->code->r, entry->content->deslocamento);

        CODE_BLOCK *attr_block = create_block(attr,1);

        declr_block = concat_iloc_code(declr_block, initializer->code);

        declr_block = concat_iloc_code(declr_block, attr_block);

        parent->code = declr_block;

    } else if(strcmp(type, "not_initialized") == 0){

        parent->code = declr_block;

    }
}

void ILOC_add_rbss_offset(CODE_BLOCK *iloc_code){

     int lines = 0;

    do{
        lines += iloc_code->number_of_lines;
        iloc_code = iloc_code->previous;

    }while(iloc_code->previous != NULL);

    lines += iloc_code->number_of_lines;

    char *code = malloc(1*128);

    sprintf(code,"loadI %d => rbss \n",lines+1);

    CODE_BLOCK *block = create_block(code,1);

    block->next = iloc_code->next;
    iloc_code->next->previous = block;
    iloc_code->next = block;
    block->previous = iloc_code;

    //printf("number of lines: %d\n", lines+1);

}

CODE_BLOCK* ILOC_cmd_attrib(char *ident, STACK *stack, node_t *exp) {
    /*
        < run exp code >
        storeAI exp->r => rbss/rfp, deslocamento
    */

    HASH_TBL *entry = lookup_stack(stack, ident);
    
    char *code = malloc(128);
   
    if(entry->content->is_global) 
        sprintf(code,"storeAI %s => rbss, %d \n", exp->code->r, entry->content->deslocamento);
    else
        sprintf(code,"storeAI %s => rfp, %d \n", exp->code->r, entry->content->deslocamento);

    CODE_BLOCK *block = create_block(code,1);
    
    return concat_iloc_code( exp->code, block);
}

// cmd with optional else: if exp evaluates to true, executes true_cmds, if exp evaluates to false executes false_cmds
CODE_BLOCK* ILOC_cmd_if(STACK *stack, node_t *exp, node_t *true_cmds, node_t *false_cmds) {
    /*
        < run exp code >
        cbr exp->r => L1, L2
        L1: nop
        true_cmds
        jumpI L3
        L2: nop
        false_cmds <<<<< can be empty (else is optional)
        L3: rest
    */

    char* l1 = create_label();
    char* l2 = create_label();
    char *l3 = create_label();

    char *code = malloc(128);
    sprintf(code,"cbr %s => %s, %s \n%s: \n", exp->code->r, l1, l2, l1);
    CODE_BLOCK* block = create_block(code, 1);
    block = concat_iloc_code(exp->code, block);
    block = concat_iloc_code(block, true_cmds->code);

    char *code_JI = malloc(128);
    sprintf(code_JI,"jumpI => %s\n", l3);
    CODE_BLOCK* jumpI_block = create_block(code_JI, 1);
    block = concat_iloc_code(block, jumpI_block);

    char *code_j2 = malloc(128);
    sprintf(code_j2,"%s:\n", l2);
    CODE_BLOCK* block_2 = create_block(code_j2, 1);
    if(false_cmds != NULL) {
        block_2 = concat_iloc_code(block_2, false_cmds->code);
    }

    return concat_iloc_code(block, block_2);
}

CODE_BLOCK* ILOC_cmd_while(STACK *stack, node_t* exp, node_t* do_cmds)
{
    /*
    L1:
        <exp code>
        cbr exp->r => L2, L3
    L2:
        <code from do ...>
        jumpI L1
    L3: 
        nope
    */
    char* l1 = create_label();
    char* l2 = create_label();
    char* l3 = create_label();

    char *code_l1 = malloc(128);
    sprintf(code_l1,"%s: \n", l1);
    CODE_BLOCK* block_l1 = create_block(code_l1, 1);
    block_l1 = concat_iloc_code(block_l1, exp->code);

    char *code_cbr = malloc(128);
    sprintf(code_cbr,"cbr %s => %s, %s\n", exp->code->r, l2, l3);
    CODE_BLOCK* block_cbr = create_block(code_cbr, 1);
    block_cbr = concat_iloc_code(block_l1, block_cbr);

    char *code_l2 = malloc(128);
    sprintf(code_l2,"%s: \n", l2);
    CODE_BLOCK* block_l2 = create_block(code_l2, 1);
    block_l2 = concat_iloc_code(block_cbr, block_l2);

    block_l2 = concat_iloc_code(block_l2, do_cmds->code);

    char *code_ji = malloc(128);
    sprintf(code_ji,"jumpI => %s\n", l1);
    CODE_BLOCK* block_ji = create_block(code_ji, 1);
    block_ji = concat_iloc_code(block_l2, block_ji);

    char *code_l3 = malloc(128);
    sprintf(code_l3,"%s: \n", l3);
    CODE_BLOCK* block_l3 = create_block(code_l3, 1);
    block_l3 = concat_iloc_code(block_ji, block_l3);

    return block_l3;
}

CODE_BLOCK* ILOC_cmd_for(STACK *stack, node_t* initial, node_t* condition, node_t* increment, node_t* cmds)
{
    /*
        <initialization>
    L1: <condition>
        cbr condition->r => L2, L3
    L2:
        <cmds>
        <increment>
        jumpI L1
    L3: nope
    */
    char* l1 = create_label();
    char* l2 = create_label();
    char* l3 = create_label();

    char *code_l1 = malloc(128);
    sprintf(code_l1,"%s: \n", l1);
    CODE_BLOCK* block_l1 = create_block(code_l1, 1);

    block_l1 = concat_iloc_code(initial->code, block_l1);

    block_l1 = concat_iloc_code(block_l1, condition->code);

    char *code_cbr = malloc(128);
    sprintf(code_cbr,"cbr %s => %s, %s\n", condition->code->r, l2, l3);
    CODE_BLOCK* block_cbr = create_block(code_cbr, 1);
    block_cbr = concat_iloc_code(block_l1, block_cbr);

    char *code_l2 = malloc(128);
    sprintf(code_l2,"%s: \n", l2);
    CODE_BLOCK* block_l2 = create_block(code_l2, 1);
    block_l2 = concat_iloc_code(block_cbr, block_l2);

    block_l2 = concat_iloc_code(block_l2, cmds->code);
    block_l2 = concat_iloc_code(block_l2, increment->code);


    char *code_ji = malloc(128);
    sprintf(code_ji,"jumpI => %s\n", l1);
    CODE_BLOCK* block_ji = create_block(code_ji, 1);
    block_ji = concat_iloc_code(block_l2, block_ji);

    char *code_l3 = malloc(128);
    sprintf(code_l3,"%s: \n", l3);
    CODE_BLOCK* block_l3 = create_block(code_l3, 1);
    block_l3 = concat_iloc_code(block_ji, block_l3);

    return block_l3;
}

int ILOC_binary_exp(node_t *parent, node_t *left, node_t *right){

    int r = binary_type_inference(parent, left, right); 

    if(r != 0){
        return r;
    }
    char *regLeft = left->code->r;
    char *regRight = right->code->r;

    char *op = parent->label;

    char *resultReg = create_register();

    char *line = malloc(1*128);

    CODE_BLOCK *op_block;

    if(strcmp(op,"+") == 0){
        
        sprintf(line,"add %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "-") == 0){

        sprintf(line,"sub %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "*") == 0){

        sprintf(line,"mult %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "/") == 0){

        sprintf(line,"div %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "&&") == 0){

        sprintf(line,"and %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "||") == 0){

        sprintf(line,"or %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "<") == 0){

        sprintf(line,"cmp_LT %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, ">") == 0){

        sprintf(line,"cmp_GT %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "<=") == 0){

        sprintf(line,"cmp_LE %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, ">=") == 0){

        sprintf(line,"cmp_GE %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "==") == 0){

        sprintf(line,"cmp_EQ %s, %s => %s \n", regLeft, regRight, resultReg);

    } else if( strcmp(op, "!=") == 0){

        sprintf(line,"cmp_NE %s, %s => %s \n", regLeft, regRight, resultReg);

    } 

    op_block = create_block(line, 1);

    /* SHORT CIRCUIT */
    if(strcmp(op,"&&") != 0 && strcmp(op,"||") != 0 ){

        parent->code = concat_iloc_code(left->code, right->code);

        parent->code = concat_iloc_code(parent->code, op_block);

    } else if( strcmp(op,"&&") == 0 ){

        char *circuit_line = malloc(3*128);
        
        char *labelNoJump = create_label();

        char *labelJump = create_label();

        sprintf(circuit_line,"i2i %s => %s \ncbr %s => %s, %s \n%s: \n",regLeft, resultReg, resultReg, labelNoJump, labelJump, labelNoJump);

        CODE_BLOCK *circuit_block = create_block(circuit_line,3);

        char *jump_line = malloc(1*128);

        sprintf(jump_line,"%s: \n", labelJump);

        CODE_BLOCK *jump_block = create_block(jump_line,1);

        parent->code = concat_iloc_code(left->code, circuit_block);

        parent->code = concat_iloc_code(parent->code, right->code);

        parent->code = concat_iloc_code(parent->code, op_block);
        
        parent->code = concat_iloc_code(parent->code, jump_block);

        free(labelJump);
        free(labelNoJump);

    } else if( strcmp(op,"||") == 0 ){

        char *circuit_line = malloc(3*128);
        
        char *labelNoJump = create_label();

        char *labelJump = create_label();

        sprintf(circuit_line,"i2i %s => %s \ncbr %s => %s, %s \n%s: \n",regLeft, resultReg, resultReg, labelJump, labelNoJump, labelNoJump);

        CODE_BLOCK *circuit_block = create_block(circuit_line,3);

        char *jump_line = malloc(1*128);

        sprintf(jump_line,"%s: \n", labelJump);

        CODE_BLOCK *jump_block = create_block(jump_line,1);

        parent->code = concat_iloc_code(left->code, circuit_block);

        parent->code = concat_iloc_code(parent->code, right->code);

        parent->code = concat_iloc_code(parent->code, op_block);
        
        parent->code = concat_iloc_code(parent->code, jump_block);

        free(labelJump);
        free(labelNoJump);
    }
    

    parent->code->r = resultReg;
    
    return 0;
}
int ILOC_unary_exp(node_t *parent, node_t *child){

    int r = unary_type_inference(parent, child); 

    if(r != 0){
        return r;
    }

    char *regChild = child->code->r;

    char *op = parent->label;

    char *resultReg = create_register();

    char *line;

    CODE_BLOCK *op_block;

    if( strcmp(op, "+") == 0){

        line = malloc(1*128);

        sprintf(line,"addI %s, 0 => %s \n",regChild, resultReg);

        op_block = create_block(line, 1);

    } else if( strcmp(op, "-") == 0){

        char *aux = create_register();

        line = malloc(2*128);

        sprintf(line,"multI %s, 2 => %s \nsub %s, %s => %s \n",regChild, aux, regChild, aux, resultReg);

        free(aux);

        op_block = create_block(line, 2);

    } else if( strcmp(op, "?") == 0){

        line = malloc(1*128);

        sprintf(line,"cmp_GT %s, 0 => %s \n",regChild, resultReg);

        op_block = create_block(line, 1);

    }


    parent->code = concat_iloc_code(child->code, op_block);

    parent->code->r = resultReg;

    return 0;
}

void print_iloc(CODE_BLOCK *iloc_code){


    while(iloc_code->previous != NULL){
        iloc_code = iloc_code->previous;
    }

    do{
        printf("%s",iloc_code->code);
        iloc_code = iloc_code->next;

    }while(iloc_code != NULL);

    free(NULL);

}

void free_iloc(CODE_BLOCK *iloc_code){
    while(iloc_code != NULL){
        CODE_BLOCK *aux = iloc_code->previous;
        free(iloc_code->code);
        free(iloc_code->r);
        free(iloc_code);

        iloc_code = aux;
    }
}