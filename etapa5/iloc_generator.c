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

    new_code->code = strdup("loadI 2048 => rfp \nloadI 2048 =>rsp \n");
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

// this is just an auxiliary function
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

    sprintf(code, "%s: \ni2i rsp => rfp \naddI rsp, %d => rsp \n", label, deslocamento_rfp);

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

        deslocamento_rfp = 16; // after
    }

    return stack;
}


CODE_BLOCK *ILOC_add_func_code(node_t *header, node_t *block, CODE_BLOCK *iloc_code, STACK *stack){
 
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

        char *halt_code = strdup("halt");

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

        sprintf(code, "loadAI rfp, 0 => %s \nloadAI rfp, 4 => %s \nloadAI rfp, 8 => %s \ni2i %s => rsp \ni2i %s => rfp \njump => %s \n",
            r0, r1, r2, r1, r2, r0);

        free(r0);
        free(r1);
        free(r2);

        CODE_BLOCK *return_inst = create_block(code, 6);

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

        sprintf(arg_param, "storeAI %s, => rsp, %d \n", arg_reg, rsp_offset);
        rsp_offset += 4;

        CODE_BLOCK *param_block = create_block(arg_param, 1);

        arg_block = concat_iloc_code(arg_block, param_block);

        initial_block = concat_iloc_code(initial_block, arg_block);

        return_offset += arg_block->number_of_lines + 1;

        args = args->next_cmd;
    }

    char *jump_code = malloc(1*128);
    sprintf(jump_code,"jumpI => %s \n", func_label);

    CODE_BLOCK *jump_block = create_block(jump_code, 1);

    return_offset += 1;

    initial_block = concat_iloc_code(initial_block, jump_block);

    char *return_addr = malloc(1*128);

    sprintf(return_addr, "addI rpc, %d => %s \n", return_offset, return_reg);

    CODE_BLOCK *return_block = create_block(return_addr, 1);

    initial_block = concat_iloc_code(return_block, initial_block);

    node->code = initial_block;

    free(return_reg);

    return 0;
}

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


void print_iloc(CODE_BLOCK *iloc_code){

    int lines = 0;

    while(iloc_code->previous != NULL){
        iloc_code = iloc_code->previous;
    }

    do{
        printf("%s",iloc_code->code);
        lines += iloc_code->number_of_lines;
        iloc_code = iloc_code->next;

    }while(iloc_code != NULL);

    printf("\nnumber of lines: %d\n", lines);
}