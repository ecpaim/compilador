#include "token_info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_token(TOKEN_INFO* tk){
	if(tk != NULL){
		if(tk->tipo != LIT || tk->tipo_lit == STRING){
            free(tk->valor.s);
        }
        free(tk);
	}
	return;
}

TOKEN_INFO* add_token(int line, int type, char* yytext, int lit_type){

	TOKEN_INFO *new_token = malloc(sizeof(TOKEN_INFO));

	new_token->linha = line;
	new_token->tipo = type;
	new_token->tipo_lit = lit_type;
	
	if(type != LIT){
		new_token->valor.s = strdup(yytext);
	
	} else { //token is literal
		
		char tru[] = "true";
		char fal[] = "false";
		char* p;
		char* p_linha;
		switch(lit_type){
			case INT:
				new_token->valor.i = atoi(yytext);
				break;		
			case FLOAT:
				new_token->valor.f = atof(yytext);
				break;
			case CHAR:
				new_token->valor.c = (char) yytext[1];	
				break;
			case BOOLEAN:
				if(strcmp(yytext, tru) == 0){
					new_token->valor.b = 1;				
				} else if(strcmp(yytext, fal) == 0){
					new_token->valor.b = 0;				
				} else {
					new_token->valor.b = atoi(yytext); 
				}  
				break;
			case STRING:
				p = strdup(yytext); 
				p_linha = malloc(sizeof(p)-1);
				memcpy(p_linha, p+1,sizeof(p_linha));
				free(p);

				p_linha[strlen(p_linha)-1] = 0; // removes last "
				new_token->valor.s = p_linha;
				break;	
			default:
				break; // explicitamente se não tem valor literal não fazer nada
		}
	}

	return new_token;
};
