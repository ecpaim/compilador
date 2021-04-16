#ifndef ILOC_GENERATOR
#define ILOC_GENERATOR
#include "symbol_table.h"
/*
typedef struct block_of_code{

	char *code;
	int number_of_lines;
	struct block_of_code *previous;
	struct block_of_code *next;

} CODE_BLOCK;

por problemas de compatibilidade essa struct ficou definida em hashtable.h
*/

extern int deslocamento_rfp;
extern int deslocamento_rbss;
extern int deslocamento_rsp; 

CODE_BLOCK *create_code();

char *create_register();

char *create_label();

// global variables dont produce any iloc code so we just update the offset of rbss
int ILOC_add_global_var(STACK *stack, char *type, node_t *nodo1, node_t *nodo2);

int ILOC_add_func_arg(STACK* stack, TOKEN_INFO* identificador, node_t *type, int is_const);

int ILOC_add_function(STACK *stack, TOKEN_INFO *indentificador, node_t *node, int static_func, node_t *func_params, node_t *parent);

int ILOC_function_call(STACK *stack, node_t *node, node_t *args);

CODE_BLOCK *ILOC_add_func_code(node_t *header, node_t *block, CODE_BLOCK *iloc_code, STACK *stack);

STACK *ILOC_put_stack(STACK *stack, char *type);

node_t *ILOC_cria_nodo(char *label, TOKEN_INFO *valor_lexico, char *type, STACK *stack);

void print_iloc(CODE_BLOCK *iloc_code);

#endif