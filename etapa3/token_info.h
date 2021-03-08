#ifndef TOKEN_HEADER
#define TOKEN_HEADER
enum tipo{ CHAR_ESP, OP_COMP, IDENT, LIT};
enum tipo_lit{INT, FLOAT, CHAR, BOOLEAN, STRING, OC_ID_SC};

typedef struct token_info{
	int linha;
	int tipo;
	int tipo_lit;
	union {
		int i;
		float f;
		char c;
		int b;
		char* s;		
	} valor;
	
} TOKEN_INFO;

TOKEN_INFO* add_token(int line, int type, char* yytext, int lit_type);


#endif