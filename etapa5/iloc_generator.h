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

// returns pointer to the last instruction of the code
CODE_BLOCK* concat_iloc_code(CODE_BLOCK *parent, CODE_BLOCK *new_code);

// global variables dont produce any iloc code so we just update the offset of rbss
int ILOC_add_global_var(STACK *stack, char *type, node_t *nodo1, node_t *nodo2);

int ILOC_add_func_arg(STACK* stack, TOKEN_INFO* identificador, node_t *type, int is_const);

int ILOC_add_function(STACK *stack, TOKEN_INFO *indentificador, node_t *node, int static_func, node_t *func_params, node_t *parent);

CODE_BLOCK *ILOC_add_func_code(node_t *header, node_t *block, CODE_BLOCK *iloc_code, STACK *stack);

int ILOC_function_call(STACK *stack, node_t *node, node_t *args);

STACK *ILOC_put_stack(STACK *stack, char *type);

// se o nodo é um token literal ou identificador cria o código correspondente
node_t *ILOC_cria_nodo(char *label, TOKEN_INFO *valor_lexico, char *type, STACK *stack);

int ILOC_verify_var_declaration(STACK *stack, TOKEN_INFO *ident, int type, node_t *var_value, int is_static, int is_const);

void ILOC_add_local_var(node_t *parent, node_t *ident, node_t *initializer, char *type, STACK *stack);

void ILOC_add_rbss_offset(CODE_BLOCK *iloc_code);

CODE_BLOCK* ILOC_cmd_attrib(char *ident, STACK *stack, node_t *exp);

void print_iloc(CODE_BLOCK *iloc_code);

#endif