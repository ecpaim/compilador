#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


// creates new stack
STACK* create_stack(){

	STACK* new_stack = malloc(sizeof(STACK));

	for(int i = 0; i < HASHSIZE; i++){
		new_stack->hashtab[i] = NULL;
	}

	new_stack->next = NULL;

	return new_stack;
}

// creates another hashtable and puts on top of stack
STACK* put_stack(STACK* stack){
	STACK* new_stack = create_stack();

	new_stack->next = stack;

	return new_stack;
}

// removes top of stack and deallocs its hashtable
STACK* pop_stack(STACK* stack){

	STACK* new_stack = stack->next;

	clear_table(stack->hashtab, HASHSIZE);

	free(stack);

	return new_stack;
}

// looks for declaration in current scope
HASH_TBL *lookup_declaration(STACK* stack, char *s){

	HASH_TBL* entry = lookup(stack->hashtab, s);

	return entry;
}

// looks for entry in all stacks
HASH_TBL *lookup_stack( STACK* stack, char *s){

	HASH_TBL* entry = NULL;

	do{
		entry = lookup(stack->hashtab, s);

		if(entry != NULL){
			break;
		}
		stack = stack->next;
	}while(stack != NULL);

	return entry;
}

// adds entry to hashtable on top of stack
void add_entry(STACK* stack, char *name, CONTEUDO *content){
	add_to_table(stack->hashtab, name, content);
}

// prints content of all hashtables
void print_stack(STACK* stack){

	int j = 0;

	do{
		printf("\n stack %d \n", ++j);

		for(int i = 0; i < HASHSIZE; i++){
			if(stack->hashtab[i] != NULL){
				printf("item nome: %s \n", stack->hashtab[i]->name);
				CONTEUDO *content = stack->hashtab[i]->content;
				if( content != NULL){
					printf("linha: %d \nnatureza: %d \ntipo: %d \ntamanho: %d \n\n",  content->linha, content->natureza, content->tipo, content->tamanho);
				}
			}
				
		}

		stack = stack->next;

	}while(stack != NULL);

}



/*
int main(){

	STACK* stack = create_stack();

	add_entry(stack, "global1", NULL);
	add_entry(stack, "global2", NULL);

	stack = put_stack(stack);

	add_entry(stack, "local1", NULL);
	add_entry(stack, "local2", NULL);

	stack = put_stack(stack);

	add_entry(stack, "local3", NULL);

	if(lookup_stack(stack, "local2") != NULL){
		printf("localizou local2 na segunda pilha\n");
	}
	if(lookup_stack(stack, "erro") == NULL){
		printf("identificou certo um erro\n");
	}

	print_stack(stack);

	stack = pop_stack(stack);
	stack = pop_stack(stack);

	print_stack(stack);

	stack = pop_stack(stack);
	if(stack == NULL)
		printf("\n tudo certo \n");


	return 0;
}
*/
