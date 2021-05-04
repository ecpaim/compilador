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

    static int next = 1;

    int aux = next;
    next++;
    if(next == 11) next = 1;

    switch(aux){
        case 0:
            return "%edx";
        case 1:
            return "%ecx";
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

    STACK* offset_to_global_var = create_stack();

    for(int i = 0; i < HASHSIZE; i++){
        if(stack->hashtab[i] != NULL){
            CONTEUDO *content = stack->hashtab[i]->content;
            if( content != NULL){
                if(content->natureza == 1){
                    char *line = malloc(128);
                    sprintf(line,"\t.comm\t%s,4,4\n", stack->hashtab[i]->name);
                    CODE_BLOCK *block = create_block(line,3);
                    assembly_code = concat_iloc_code(assembly_code, block);

                    CONTEUDO *cnt = malloc(sizeof(CONTEUDO));
                    cnt->return_label = strdup(stack->hashtab[i]->name); 
                    char desloc[20];
                    sprintf(desloc,"%d",content->deslocamento);
                    add_entry(offset_to_global_var,desloc, cnt);
                }
            }
        }
                
    }

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

        /* in AT&T assembly x64_86, the stack must move in multiples of 16*/
        if((strcmp(iloc_code->iloc_name,"addI") == 0) && (strcmp(iloc_code->op1,"rsp") == 0) && (strcmp(iloc_code->op3,"rsp") == 0) ){
          
            sprintf(line,"\taddq\t$-16, %%rsp\n");

            CODE_BLOCK *block = create_block(line,3);

            assembly_code = concat_iloc_code(assembly_code, block);


        } else if((strcmp(iloc_code->iloc_name,"addI") == 0) && (strcmp(iloc_code->op1,"rpc") == 0)){ // function call instructions

            for(int i = 0; i < 3; i++){ // not useful on assembly
                iloc_code = iloc_code->next;
            }


        } else if((strcmp(iloc_code->iloc_name,"cbr") == 0)){ 

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
            sprintf(line,"\tcmpl\t$1,%s \n\tje\t.%s \n\tjne\t.%s \n", op1->content->return_label, iloc_code->op2, iloc_code->op3);

            CODE_BLOCK *block = create_block(line,3);

            assembly_code = concat_iloc_code(assembly_code, block);


        } else if((strcmp(iloc_code->iloc_name,"cmp_LT") == 0)){ // "GAS/AT&T syntax can be rather confusing, as for example cmp $0, %rax followed by jl branch will branch if %rax < 0"
            assembly_code = cmp_instructions(iloc_to_assembly_reg, assembly_code, iloc_code, line);
        } else if((strcmp(iloc_code->iloc_name,"cmp_GT") == 0)){ 
            assembly_code = cmp_instructions(iloc_to_assembly_reg, assembly_code, iloc_code, line);
        } else if((strcmp(iloc_code->iloc_name,"cmp_LE") == 0)){ 
            assembly_code = cmp_instructions(iloc_to_assembly_reg, assembly_code, iloc_code, line);
        } else if((strcmp(iloc_code->iloc_name,"cmp_GE") == 0)){ 
            assembly_code = cmp_instructions(iloc_to_assembly_reg, assembly_code, iloc_code, line);
        } else if((strcmp(iloc_code->iloc_name,"cmp_EQ") == 0)){ 
            assembly_code = cmp_instructions(iloc_to_assembly_reg, assembly_code, iloc_code, line);
        }else if((strcmp(iloc_code->iloc_name,"cmp_NE") == 0)){ 
            assembly_code = cmp_instructions(iloc_to_assembly_reg, assembly_code, iloc_code, line);
        } else if((strcmp(iloc_code->iloc_name,"storeAI") == 0) && (strcmp(iloc_code->op2,"rsp") == 0)){ // function call arguments

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);

            sprintf(line,"\tsubq\t$8, %%rsp \n\tmovl\t%s,(%%rsp)\n",op1->content->return_label);

            CODE_BLOCK *block = create_block(line,2);

            assembly_code = concat_iloc_code(assembly_code, block);

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
                    
                    // function call return value
                    HASH_TBL *op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->next->op3);
                    

                    if(op3 == NULL){
                        char *reg = get_new_reg();
                        content = malloc(sizeof(CONTEUDO));
                        content->return_label = strdup(reg); 
                        add_entry(iloc_to_assembly_reg, iloc_code->next->op3 , content);
                        op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->next->op3);
                    }

                    sprintf(line,"\tcall\t%s \n\tmovl\t%%eax, %s \n",func_name, op3->content->return_label);

                    iloc_code = iloc_code->next; // skip next instruction
                    
                } else{
                    sprintf(line,"\tjmp\t.%s \n",iloc_code->op1);
                }
            }

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"i2i") == 0) { // reg to reg
            
            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
            HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

            if(op2 == NULL){
                char *reg = get_new_reg();
                content = malloc(sizeof(CONTEUDO));
                content->return_label = strdup(reg); 
                add_entry(iloc_to_assembly_reg, iloc_code->op2 , content);
                op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);
            }

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
                sprintf(line,"\taddq\t$-%s, %s\n\tmovq\t%s, %s \n",iloc_code->op2, op1->content->return_label, op1->content->return_label, op3->content->return_label);
            } else { 
                sprintf(line,"\taddl\t$%s, %s\n\tmovl\t%s, %s \n",iloc_code->op2, op1->content->return_label, op1->content->return_label, op3->content->return_label);
            }
            

            CODE_BLOCK *block = create_block(line,2);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"storeAI") == 0){

            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);

            HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

            if((strcmp(iloc_code->op2,"rbss") == 0)){
               
                HASH_TBL *var_name = lookup_stack( offset_to_global_var, iloc_code->op3);
                sprintf(line,"\tmovl\t%s,%s(%%rip) \n", op1->content->return_label, var_name->content->return_label);

            } else if((strcmp(iloc_code->op1,"rsp") == 0) || (strcmp(iloc_code->op1,"rfp") == 0) || (strcmp(iloc_code->op3,"rsp") == 0) || (strcmp(iloc_code->op3,"rfp") == 0)){
                sprintf(line,"\tmovq\t%s,-%s(%s)\n",op1->content->return_label, iloc_code->op3, op2->content->return_label);
            } else {
                sprintf(line,"\tmovl\t%s,-%s(%s)\n",op1->content->return_label, iloc_code->op3, op2->content->return_label);
            }
            

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

            sprintf(line, "\tmovq\t%%rbp, %%rsp\n\tpopq\t%%rbp\n\tret\n\t.size\tmain, .-main\n\t.section\t.note.GNU-stack,\"\",@progbits \n");

            CODE_BLOCK *block = create_block(line,5);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(iloc_code->op1 == NULL && iloc_code->op2 == NULL && iloc_code->op3 == NULL) { // it is a label

            char func_name[128];
         
            extract_function_name(func_name,iloc_code->iloc_name);
             
            HASH_TBL *entry = lookup_declaration(stack, func_name);

            CODE_BLOCK *block;
            if(entry != NULL){ // beginning of function
                
                current_function = strdup(func_name);

                sprintf(line, "\t.globl\t%s \n\t.type\t%s, @function \n%s:\n.%s \n\tpushq\t%%rbp\n\tmovq\t%%rsp, %%rbp\n",func_name, func_name, func_name, iloc_code->iloc_name);
                block = create_block(line,6);

                iloc_code = iloc_code->next; // skip next instruction i2i rsp => rfp

                iloc_code = iloc_code->next; // processing addI rsp, 32 => rsp and args

                if(strcmp(func_name,"main") != 0){

                    int number_args = (atoi(iloc_code->op2) - 16)/8;

                    char *var_space = malloc(128);
                    sprintf(var_space,"\taddq\t$-%d, %%rsp\n",16*number_args);
                    CODE_BLOCK* var_space_block = create_block(var_space,1);
                    block = concat_iloc_code(block,var_space_block);

                    for(int i = 0; i<number_args; i++){ 
                        iloc_code = iloc_code->next;
                        char *get_arg = malloc(128);
                        sprintf(get_arg,"\tmovl\t%d(%%rbp), %%eax \n\tmovl\t%%eax,-%s(%%rbp)\n",i*8+16, iloc_code->next->op3);
                        CODE_BLOCK* arg_block = create_block(get_arg,2);
                        block = concat_iloc_code(block,arg_block);
                        iloc_code = iloc_code->next;
                    }
                }

            } else {
                /* if it is iloc function return instructions */
                if((strcmp(iloc_code->next->iloc_name,"loadAI") == 0) && (strcmp(iloc_code->next->op1,"rfp") == 0) && (strcmp(iloc_code->next->op2,"0") == 0) && (iloc_code->next->next != NULL)) {
                    if( (strcmp(iloc_code->next->next->iloc_name,"loadAI") == 0) && (strcmp(iloc_code->next->next->op1,"rfp") == 0) && (strcmp(iloc_code->next->next->op2,"4") == 0)){
                        
                        sprintf(line,".%s \n\tleave\n\tret\n\t.size\t%s, .-%s\n",iloc_code->iloc_name, current_function,current_function);

                        block = create_block(line,4);

                        for(int i = 0; i < 6; i++){ // skip next 5 instructions (iloc function return)
                            iloc_code = iloc_code->next;
                        }

                    } else {
                        sprintf(line, ".%s \n",iloc_code->iloc_name);
                        block = create_block(line,1);
                    }
                } else {
                    sprintf(line, ".%s \n",iloc_code->iloc_name);
                    block = create_block(line,1);
                }
            }

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

            if(strcmp(iloc_code->op1,"rbss") == 0){
                HASH_TBL *var_name = lookup_stack( offset_to_global_var, iloc_code->op2);
                sprintf(line,"\tmovl\t%s(%%rip), %s\n",var_name->content->return_label, op3->content->return_label);

            } else {

                sprintf(line,"\tmovl\t-%s(%s), %s\n", iloc_code->op2, op1->content->return_label, op3->content->return_label);

            }

            CODE_BLOCK *block = create_block(line,1);

            assembly_code = concat_iloc_code(assembly_code, block);

        } else if(strcmp(iloc_code->iloc_name,"mult") == 0) {
            assembly_code = binary_exp(iloc_to_assembly_reg, iloc_code, assembly_code, "imul");
        } else if(strcmp(iloc_code->iloc_name,"add") == 0) {
            assembly_code = binary_exp(iloc_to_assembly_reg, iloc_code, assembly_code, "addl");
        } else if(strcmp(iloc_code->iloc_name,"sub") == 0) {
            assembly_code = binary_exp(iloc_to_assembly_reg, iloc_code, assembly_code, "subl");
        } else if(strcmp(iloc_code->iloc_name,"and") == 0) {
            assembly_code = binary_exp(iloc_to_assembly_reg, iloc_code, assembly_code, "andl");
        } else if(strcmp(iloc_code->iloc_name,"or") == 0) {
            assembly_code = binary_exp(iloc_to_assembly_reg, iloc_code, assembly_code, "orl");
        } else if(strcmp(iloc_code->iloc_name,"div") == 0) {
            /*
            movl op1->content->return_label, %eax
            cltd (rax contem quadword)
            movq $0 %rdx
            idivq op2->content->return_label (eax tem a resposta)
            */
            HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
            HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

            char* line = malloc(256);
            sprintf(line, "\tmovl\t%s, %%eax\n\tcltd\n\tmovq\t$0, %%rdx\n\tidivl\t%s\n", op1->content->return_label, op2->content->return_label);
            // D - S
            // subl S, D = D - S
            CONTEUDO* content = malloc(sizeof(CONTEUDO));
            content->return_label = strdup("%eax"); 
            add_entry(iloc_to_assembly_reg, iloc_code->op3 , content);

            CODE_BLOCK *block = create_block(line,4);

            assembly_code = concat_iloc_code(assembly_code, block);
        }
        iloc_code = iloc_code->next;
    }

    print_iloc(assembly_code);

    free(current_function);
}

CODE_BLOCK* cmp_instructions(STACK* iloc_to_assembly_reg, CODE_BLOCK* assembly_code, INSTRUCTION* iloc_code, char *line){


    HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
    HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);
    HASH_TBL *op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);

    if(op3 == NULL){
        char *reg = get_new_reg();
        CONTEUDO* content = malloc(sizeof(CONTEUDO));
        content->return_label = strdup(reg); 
        add_entry(iloc_to_assembly_reg, iloc_code->op3 , content);
        op3 = lookup_stack( iloc_to_assembly_reg, iloc_code->op3);
    }

    if(strcmp(iloc_code->iloc_name,"cmp_LT") == 0){

        sprintf(line,"\tcmpl\t%s, %s \n\tsetl\t%%al \n\tcbtw\n\tcwtl\n\tmovl\t%%eax, %s \n", op2->content->return_label, op1->content->return_label, op3->content->return_label);

    } else if(strcmp(iloc_code->iloc_name,"cmp_GT") == 0){

        sprintf(line,"\tcmpl\t%s, %s \n\tsetg\t%%al \n\tcbtw\n\tcwtl\n\tmovl\t%%eax, %s \n", op2->content->return_label, op1->content->return_label, op3->content->return_label);

    } else if(strcmp(iloc_code->iloc_name,"cmp_LE") == 0){

        sprintf(line,"\tcmpl\t%s, %s \n\tsetle\t%%al \n\tcbtw\n\tcwtl\n\tmovl\t%%eax, %s \n", op2->content->return_label, op1->content->return_label, op3->content->return_label);

    } else if(strcmp(iloc_code->iloc_name,"cmp_GE") == 0){

        sprintf(line,"\tcmpl\t%s, %s \n\tsetge\t%%al \n\tcbtw\n\tcwtl\n\tmovl\t%%eax, %s \n", op2->content->return_label, op1->content->return_label, op3->content->return_label);

    } else if(strcmp(iloc_code->iloc_name,"cmp_EQ") == 0){

        sprintf(line,"\tcmpl\t%s, %s \n\tsete\t%%al \n\tcbtw\n\tcwtl\n\tmovl\t%%eax, %s \n", op2->content->return_label, op1->content->return_label, op3->content->return_label);

    } else if(strcmp(iloc_code->iloc_name,"cmp_NE") == 0){

        sprintf(line,"\tcmpl\t%s, %s \n\tsetne\t%%al \n\tcbtw\n\tcwtl\n\tmovl\t%%eax, %s \n", op2->content->return_label, op1->content->return_label, op3->content->return_label);

    } 

    CODE_BLOCK *block = create_block(line,5);

    return concat_iloc_code(assembly_code, block);
}

CODE_BLOCK* binary_exp(STACK *iloc_to_assembly_reg, INSTRUCTION* iloc_code, CODE_BLOCK* assembly_code, char* operation){
    HASH_TBL *op1 = lookup_stack( iloc_to_assembly_reg, iloc_code->op1);
    HASH_TBL *op2 = lookup_stack( iloc_to_assembly_reg, iloc_code->op2);

    char* line = malloc(256);
    sprintf(line, "\t%s\t%s, %s\n", operation, op2->content->return_label, op1->content->return_label);
    // D - S
    // subl S, D = D - S
    // o ultimo é o destino 
    CONTEUDO* content = malloc(sizeof(CONTEUDO));
    content->return_label = strdup(op1->content->return_label); 
    add_entry(iloc_to_assembly_reg, iloc_code->op3 , content);
    CODE_BLOCK *block = create_block(line,2);

    return concat_iloc_code(assembly_code, block);
}
