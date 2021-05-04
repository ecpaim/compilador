#ifndef ASSEMBLY_HEADER
#define ASSEMBLY_HEADER
#include "iloc_generator.h"

typedef struct instruction{
	char *iloc_name;
	char *op1;
	char *op2;
	char *op3;
	struct instruction *next;
	struct instruction *previous;

} INSTRUCTION;

// returns pointer to first instruction
INSTRUCTION* read_iloc_code();

void convert_to_assembly(INSTRUCTION* iloc_code, STACK* stack);

CODE_BLOCK* binary_exp(STACK *iloc_to_assembly_reg, INSTRUCTION* iloc_code, CODE_BLOCK* assembly_code, char* operation);

CODE_BLOCK* cmp_instructions(STACK* iloc_to_assembly_reg, CODE_BLOCK* assembly_code, INSTRUCTION* iloc_code, char *line);

#endif