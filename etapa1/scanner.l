%option yylineno
%{
	#include <stdio.h>
	#include "tokens.h"

	int global_var_is_bad_practice = 0;
	int get_line_number(void);
%}

white [ \t]+

%%

\n { }
{white} { }

"int" { return TK_PR_INT;}
"float" { return TK_PR_FLOAT;}
"bool" { return TK_PR_BOOL;}
"char" { return TK_PR_CHAR;}
"string" { return TK_PR_STRING;}
"if" { return TK_PR_IF;}
"then" { return TK_PR_THEN;}
"else" { return TK_PR_ELSE;}


"=" { return (int)'=';}
";" { return (int)';';}

[a-zA-Z_][a-zA-Z0-9_]* { return TK_IDENTIFICADOR;}
(\+|-)?[0-9]+ { return TK_LIT_INT;}


%%


int get_line_number (void){
	return yylineno;
}