#ifndef STACK_HEADER
#define STACK_HEADER
#include "hashtable.h"

typedef struct stack {
	HASH_TBL* hashtab[HASHSIZE];
	struct stack *next; // the element below 

} STACK;

STACK* create_stack();

// creates another hashtable and puts on top of stack
STACK* put_stack(STACK* stack);

// removes top of stack and deallocs its hashtable
STACK* pop_stack(STACK* stack);

// looks for declaration in current scope
HASH_TBL *lookup_declaration(STACK* stack, char *s);

// looks for entry in all stacks
HASH_TBL *lookup_stack( STACK* stack, char *s);

// adds entry to hashtable on top of stack
void add_entry(STACK* stack, char *name, CONTEUDO *content);

// prints content of all hashtables
void print_stack(STACK* stack);


// creates the list
LIST* create_list();

// print elements inside the list
void print_list(LIST *list);

// add element at the end of the list
void add_to_list(LIST **list, char* element, int type);

// free the list
void free_list(LIST *list);

#endif
