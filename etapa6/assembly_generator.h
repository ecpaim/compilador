#ifndef ASSEMBLY_HEADER
#define ASSEMBLY_HEADER

typedef struct instruction{
	char *iloc_name;
	char *op1;
	char *op2;
	char *op3;
	struct instruction *next;
	struct instruction *previous;

} INSTRUCTION;

// returns pointer to last instruction
INSTRUCTION* read_iloc_code();

#endif