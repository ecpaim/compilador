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

// returns pointer to last instruction
INSTRUCTION* read_iloc_code(){

	INSTRUCTION *last_instruction = NULL;

	FILE *f = fopen("temp", "r");

	char *line = NULL;
	size_t len = 0;
    ssize_t read;

    char delim[] = " ,=>\n\0";

	while ((read = getline(&line, &len, f)) != -1) {
      
        printf("%s", line);

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

    return last_instruction;
}



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