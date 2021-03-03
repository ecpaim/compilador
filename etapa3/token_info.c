#include "token_info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


TOKEN_INFO* add_token(int line, int type, char* yytext, int lit_type){

	TOKEN_INFO *new_token = malloc(sizeof(TOKEN_INFO));

	new_token->linha = line;
	new_token->tipo = type;
	
	if(type != LIT){
		new_token->valor = strdup(yytext);
	
	} else { //token is literal

		new_token->tipo_lit = lit_type;

		char tru[5];
		char fal[6];
		char* p;
		switch(lit_type){
			case INT:
				new_token->valor_lit.i = atoi(yytext);
				break;		
			case FLOAT:
				new_token->valor_lit.f = atof(yytext);
				break;
			case CHAR:
				new_token->valor_lit.c = (char) yytext[1];	
				break;
			case BOOLEAN:
				strcpy(tru, "true");
				strcpy(fal,"false");
				if(strcmp(yytext, tru)){
					new_token->valor_lit.b = 1;				
				} else if(strcmp(yytext, fal)){
					new_token->valor_lit.b = 0;				
				} else {
					new_token->valor_lit.b = atoi(yytext);
				}  
				break;
			case STRING:
				p = strdup(yytext);
				p++; // removes first " (does it cause memory leak?)
				p[strlen(p)-1] = 0; // removes last "
				new_token->valor_lit.s = p;
				break;	
		}
	}

	return new_token;
};
