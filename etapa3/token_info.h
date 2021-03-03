
enum tipo{ CHAR_ESP, OP_COMP, IDENT, LIT};
enum tipo_lit{INT, FLOAT, CHAR, BOOLEAN, STRING};

typedef struct token_info{
	int linha;
	int tipo;
	char* valor; // maybe we'll need to dealloc this with free()
	int tipo_lit;
	union {
		int i;
		float f;
		char c;
		int b;
		char* s;		
	} valor_lit;
	
} TOKEN_INFO;

TOKEN_INFO* add_token(int line, int type, char* yytext, int lit_type);


