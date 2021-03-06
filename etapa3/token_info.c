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

		char tru[] = "true";
		char fal[] = "false";
		char* p;
		char* p_linha;
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
				if(strcmp(yytext, tru)){
					new_token->valor_lit.b = 1;				
				} else if(strcmp(yytext, fal)){
					new_token->valor_lit.b = 0;				
				} else {
					new_token->valor_lit.b = atoi(yytext); // ?? um token boolean pode ser outra coisa?
				}  
				break;
			case STRING:
				p = strdup(yytext);
				p_linha = malloc(sizeof(p)-1);
				memcpy(p_linha, p+1,sizeof(p_linha));
				free(p);

				p[strlen(p)-1] = 0; // removes last "
				new_token->valor_lit.s = p;
				break;	
			default:
				break; // explicitamente se não tem valor literal não fazer nada
		}
	}

	return new_token;
};
