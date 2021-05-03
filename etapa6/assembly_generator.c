#include "assembly_generator.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

INSTRUCTION* create_instruction(){
	INSTRUCTION *new = malloc(sizeof(INSTRUCTION));
	new->iloc_name = NULL;
	new->op1 = NULL;
	new->op2 = NULL;
	new->op3 = NULL;
	new->next = NULL;
	new->previous = NULL;

	return new;
}

INSTRUCTION* concat_instruction(INSTRUCTION *parent, INSTRUCTION *new_code){

    if(new_code == NULL){
        return parent;
    } else if(parent == NULL){
        return new_code;
    }

    INSTRUCTION* first_new_instruction = new_code;

    while(first_new_instruction->previous != NULL){
        first_new_instruction =first_new_instruction->previous;
    }


    parent->next = first_new_instruction;
    first_new_instruction->previous = parent;

    return new_code;
}

void free_instructions(INSTRUCTION *last){
    while(last != NULL){
        INSTRUCTION *aux = last->previous;
        free(last->iloc_name);
        free(last->op1);
        free(last->op2);
        free(last->op3);
        free(last);

        last = aux;
    }
}

// returns pointer to first instruction
INSTRUCTION* read_iloc_code(){

	INSTRUCTION *last_instruction = NULL;

	FILE *f = fopen("temp", "r");

	char *line = NULL;
	size_t len = 0;
    ssize_t read;

    char delim[] = " ,=>\n\0";

	while ((read = getline(&line, &len, f)) != -1) {
      
        //printf("%s", line);

        char *tkn = strtok(line, delim);

        INSTRUCTION *inst = create_instruction();

        int nOperators = 0;

        while( tkn != NULL){
        	switch(nOperators){
        		case 0:
        			inst->iloc_name = strdup(tkn);
        			break;
        		case 1:
        			inst->op1 = strdup(tkn);
        			break;
        		case 2:
        			inst->op2 = strdup(tkn);
        			break;
        		case 3:
        			inst->op3 = strdup(tkn);
        			break;
        		default:
        			printf("too many iloc operators!");
        			return NULL;
        	}
        	nOperators++;
        	
        	tkn = strtok(NULL, delim);
        }
        last_instruction = concat_instruction(last_instruction, inst);

    }

    free(line);

    fclose(f);

    INSTRUCTION *first_instruction = last_instruction;

    while(first_instruction->previous != NULL){
        first_instruction = first_instruction->previous;
    }

    return first_instruction;
}

void extract_function_name(char *name, char* label){

    char delim[] = " :\n\0";

    char *aux = strdup(label);

    char* tkn = strtok(aux+1, delim);

    sprintf(name,"%s",tkn);

    tkn = strtok(NULL, delim);

    free(aux);

    return;
}

/*
alterna circularmente entre os registradores
*/
char *get_new_reg(){

    static int next = 0;

    int aux = next;
    next++;
    if(next = 11) next = 0;

    switch(aux){
        case 0:
            return "%ecx";
        case 1:
            return "%edx";
        case 2:
            return "%ebx";
        case 3:
            return "%r8d";
        case 4:
            return "%r9d";
        case 5:
            return "%r10d";
        case 6:
            return "%r11d";
        case 7: 
            return "%r12d";
        case 8: 
            return "%r13d";
        case 9: 
            return "%r14d";
        case 10: 
            return "%r15d";
        default:
            return "%eax";

    }
}

void convert_to_assembly(INSTRUCTION* iloc_code, STACK* stack){

    INSTRUCTION *aux = iloc_code;

    iloc_code = iloc_code->next->next; // first two instructions just set the value of rfp and rsp
    iloc_code = iloc_code->next->next; // next two instructions set value of rbss and jump to main

    CODE_BLOCK* assembly_code = create_block("\t.text \n", 1); //initial assembly instruction

    do{
        printf("inst: %s %s %s %s \n",aux->iloc_name, aux->op1, aux->op2, aux->op3);
        aux = aux->next;

    }while(aux != NULL);

    STACK* iloc_to_assembly_reg = create_stack();
    CONTEUDO *content = malloc(sizeof(CONTEUDO));
    content->return_label = strdup("%rsp"); 
    add_entry(iloc_to_assembly_reg,"rsp", content); // adds rsp -> %rsp translation

    content = malloc(sizeof(CONTEUDO));
    content->return_label = strdup("%rbp");
    add_entry(iloc_to_assembly_reg,"rfp", content); // adds rfp -> %rbp translation

    content = malloc(sizeof(CONTEUDO));
    content->return_label = strdup("%rip");
    add_entry(iloc_to_assembly_reg,"rbss", content); // adds rbss -> %rip translation

    char *current_function = NULL;
    
    while(iloc_code != NULL){

        char *line = malloc(128);

        if((strcmp(iloc_code->iloc_name,"loadAI") == 0) && (strcmp(iloc_code->op1,"rsp") == 0) && (strcmp(iloc_code->op2,"12") == 0) ){ // function call return value

            HASH_TBL *op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);

            if(op3 == NULL){
                char *reg = get_new_reg();
                content = malloc(sizeof(CONTEUDO));
                content->return_label = strdup(reg); 
                add_entry(iloc_to_assembly_reg, iloc_code->op3 , content);
                op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);
            }

            sprintf(line,"\tmovl\t%%eax, %s \n",op3->content->return_label);

            CODE_BLOCK *block = create_block(line,3);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if((strcmp(iloc_code->iloc_name,"addI") == 0) && (strcmp(iloc_code->op1,"rpc") == 0)){ // function call instructions

            for(int i = 0; i < 3; i++){ // not useful on assembly
                iloc_code = iloc_code->next;
            }

        } else if((strcmp(iloc_code->iloc_name,"loadAI") == 0) && (strcmp(iloc_code->op1,"rfp") == 0) && (strcmp(iloc_code->op2,"0") == 0) ){ // function return instructions

            sprintf(line,"\tpopq\t%%rbp\n\tret\n\t.size\t%s, .-%s\n",current_function,current_function);

            CODE_BLOCK *block = create_block(line,3);

            assembly_code = concat_iloc_code(assembly_code, block);

            for(int i = 0; i < 5; i++){ // skip next 5 instructions (iloc function return)
                iloc_code = iloc_code->next;
            }
          

        } else if((strcmp(iloc_code->iloc_name,"storeAI") == 0) && (strcmp(iloc_code->op2,"rfp") == 0) && (strcmp(iloc_code->op3,"12") == 0) ){ //return value

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);

            sprintf(line, "\tmovl\t%s, %%eax\n", op1->content->return_label);

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if( (strcmp(iloc_code->iloc_name,"jump") == 0) || (strcmp(iloc_code->iloc_name,"jumpI") == 0) ){ // jumpI

            if(strcmp(iloc_code->iloc_name,"jump") == 0){
                HASH_TBL *assembly_reg = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
                sprintf(line,"\tjmp\t%s \n",assembly_reg->content->return_label);

            } else { // it can be a function call

                char func_name[128];
                extract_function_name(func_name,iloc_code->op1);
                HASH_TBL *entry = lookup_declaration(stack, func_name);
                if(entry != NULL){
                    sprintf(line,"\tcall\t%s \n",func_name);
                } else{
                    sprintf(line,"\tjmp\t%s \n",iloc_code->op1);
                }
            }

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"i2i") == 0) { // reg to reg

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
            HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

            if((strcmp(iloc_code->op1,"rsp") == 0) || (strcmp(iloc_code->op1,"rfp") == 0) || (strcmp(iloc_code->op1,"rbss") == 0)){
                sprintf(line, "\tmovq\t%s,%s \n", op1->content->return_label, op2->content->return_label);
            } else {
                sprintf(line, "\tmovl\t%s,%s \n", op1->content->return_label, op2->content->return_label);
            }

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"addI") == 0){

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
            
            HASH_TBL *op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);

            if(op3 == NULL){
                char *reg = get_new_reg();
                content = malloc(sizeof(CONTEUDO));
                content->return_label = strdup(reg); 
                add_entry(iloc_to_assembly_reg, iloc_code->op3 , content);
                op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);
            }
            if((strcmp(iloc_code->op1,"rsp") == 0) || (strcmp(iloc_code->op1,"rfp") == 0) || (strcmp(iloc_code->op1,"rbss") == 0) || 
                (strcmp(iloc_code->op3,"rsp") == 0) || (strcmp(iloc_code->op3,"rfp") == 0) || (strcmp(iloc_code->op3,"rbss") == 0)){
                sprintf(line,"\taddq\t$%s, %s\n\tmovq\t%s, %s \n",iloc_code->op2, op1->content->return_label, op1->content->return_label, op3->content->return_label);
            } else { 
                sprintf(line,"\taddl\t$%s, %s\n\tmovl\t%s, %s \n",iloc_code->op2, op1->content->return_label, op1->content->return_label, op3->content->return_label);
            }
            

            CODE_BLOCK *block = create_block(line,2);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"storeAI") == 0){

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);

            HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

            if((strcmp(iloc_code->op1,"rsp") == 0) || (strcmp(iloc_code->op1,"rfp") == 0) || (strcmp(iloc_code->op1,"rbss") == 0) || 
                (strcmp(iloc_code->op3,"rsp") == 0) || (strcmp(iloc_code->op3,"rfp") == 0) || (strcmp(iloc_code->op3,"rbss") == 0)){
                sprintf(line,"\tmovq\t%s,-%s(%s)\n",op1->content->return_label, iloc_code->op3, op2->content->return_label);
            } else {
                sprintf(line,"\tmovl\t%s,-%s(%s)\n",op1->content->return_label, iloc_code->op3, op2->content->return_label);
            }
            

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"loadAI") == 0){

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);

            HASH_TBL *op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);

            if(op3 == NULL){
                char *reg = get_new_reg();
                content = malloc(sizeof(CONTEUDO));
                content->return_label = strdup(reg); 
                add_entry(iloc_to_assembly_reg, iloc_code->op3 , content);
                op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);
            }
            sprintf(line,"\tmovl\t-%s(%s), %s\n", iloc_code->op2, op1->content->return_label, op3->content->return_label);

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"loadI") == 0){
            
            HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

            if(op2 == NULL){
                char *reg = get_new_reg();
                content = malloc(sizeof(CONTEUDO));
                content->return_label = strdup(reg); 
                add_entry(iloc_to_assembly_reg, iloc_code->op2 , content);
                op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);
            }
            
            sprintf(line, "\tmovl\t$%s, %s \n",iloc_code->op1, op2->content->return_label);

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);


        } else if(strcmp(iloc_code->iloc_name,"halt") == 0){

            sprintf(line, "\tpopq\t%%rbp\n\tret\n\t.size\tmain, .-main\n\t.section\t.note.GNU-stack,\"\",@progbits \n");

            CODE_BLOCK *block = create_block(line,4);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else { // it is a label

            char func_name[128];
         
            extract_function_name(func_name,iloc_code->iloc_name);
             
            HASH_TBL *entry = lookup_declaration(stack, func_name);

            CODE_BLOCK *block;
            if(entry != NULL){ // beginning of function
                sprintf(line, "\t.globl\t%s \n\t.type\t%s, @function \n%s:\n.%s \n\tpushq\t%%rbp\n\tmovq\t%%rsp, %%rbp\n",func_name, func_name, func_name, iloc_code->iloc_name);
                block = create_block(line,6);
                current_function = strdup(func_name);

                iloc_code = iloc_code->next; // skip next instruction

            } else {
                sprintf(line, "%s \n",iloc_code->iloc_name);
                block = create_block(line,1);
            }

            assembly_code = concat_iloc_code(assembly_code, block);
        }

        //printf("line: %s", assembly_code->code);

        iloc_code = iloc_code->next;
    }

    print_iloc(assembly_code);

    free(current_function);
}

/*

int main(){

	INSTRUCTION *last = read_iloc_code();
	INSTRUCTION *aux = last;
	
	while(aux->previous != NULL){
        aux = aux->previous;
    }

    do{
        printf("inst: %s %s %s %s \n",aux->iloc_name, aux->op1, aux->op2, aux->op3);
        aux = aux->next;

    }while(aux != NULL);

    free_instructions(last);

	return 0;
}
*/