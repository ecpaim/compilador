%option yylineno
%{
	#include <stdio.h>
	#include "token_info.h"
	#include "parser.tab.h"

	int global_var_is_bad_practice = 0;
%}

int get_line_number(void);	

white [ \t]+
digit [0-9]
integer {digit}+
exponent [eE][+-]?{integer}
real {integer}("."{integer})?{exponent}?
notreal {integer}(".")[a-zA-Z_]+{exponent}?

%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] { }
"//"([^\n]+)$ { }

\n { }
{white} { }

"false" { yylval.valor_lexico = add_token(yylineno, LIT, yytext, BOOLEAN);  return TK_LIT_FALSE; }
"true" { yylval.valor_lexico = add_token(yylineno, LIT, yytext, BOOLEAN); return TK_LIT_TRUE; }
\".*\" { yylval.valor_lexico = add_token(yylineno, LIT, yytext, STRING); return TK_LIT_STRING; }

"int" { return TK_PR_INT; }
"float" { return TK_PR_FLOAT; }
"bool" { return TK_PR_BOOL; }
"char" { return TK_PR_CHAR; }
"string" { return TK_PR_STRING; }
"if" { return TK_PR_IF; }
"then" { return TK_PR_THEN; }
"else" { return TK_PR_ELSE; }
"while" { return TK_PR_WHILE; }
"do" { return TK_PR_DO; }
"input" { return TK_PR_INPUT; }
"output" { return TK_PR_OUTPUT; }
"return" { return TK_PR_RETURN; }
"const" { return TK_PR_CONST; }
"static" { return TK_PR_STATIC; }
"foreach" { return TK_PR_FOREACH; }
"for" { return TK_PR_FOR; }
"switch" { return TK_PR_SWITCH; }
"case" { return TK_PR_CASE; }
"break" { return TK_PR_BREAK; }
"continue" { return TK_PR_CONTINUE; }
"class" { return TK_PR_CLASS; }
"private" { return TK_PR_PRIVATE; }
"public" { return TK_PR_PUBLIC; }
"protected" { return TK_PR_PROTECTED; }
"end" { return TK_PR_END; }
"default" { return TK_PR_DEFAULT; }

"=" { return (int)'='; }
";" { return (int)';'; }
"," { return (int)','; }
":" { return (int)':'; }
"(" { return (int)'('; }
")" { return (int)')'; }
"[" { return (int)'['; }
"]" { return (int)']'; }
"{" { return (int)'{'; }
"}" { return (int)'}'; }
"+" { return (int)'+'; }
"-" { return (int)'-'; }
"|" { return (int)'|'; }
"*" { return (int)'*'; }
"/" { return (int)'/'; }
"<" { return (int)'<'; }
">" { return (int)'>'; }
"!" { return (int)'!'; }
"&" { return (int)'&'; }
"%" { return (int)'%'; }
"#" { return (int)'#'; }
"^" { return (int)'^'; }
"." { return (int)'.'; }
"$" { return (int)'$'; }
"?" { return (int)'?'; }

"<=" { return TK_OC_LE; }
">=" { return TK_OC_GE; }
"==" { return TK_OC_EQ; }
"!=" { return TK_OC_NE; }
"&&" { return TK_OC_AND; }
"||" { return TK_OC_OR; }
">>" { return TK_OC_SR; }
"<<" { return TK_OC_SL; }


[a-zA-Z_][a-zA-Z0-9_]* { return TK_IDENTIFICADOR; }
[0-9]+[a-zA-Z_]+[a-zA-Z_]* { return TOKEN_ERRO; }

[0-9]+ { return TK_LIT_INT; }

{real} { return TK_LIT_FLOAT; }
{notreal} { return TOKEN_ERRO; }

'.{1}' { return TK_LIT_CHAR; }
. { return TOKEN_ERRO; }

%%


int get_line_number (void){
	return yylineno;
}
