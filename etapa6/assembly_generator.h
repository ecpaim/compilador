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

#endif