%{
#include<stdio.h>
#include <stdlib.h>
#define YYERROR_VERBOSE 1
extern int yylineno;
int yylex(void);
int yyerror (char const *s);
%}

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token TK_PR_BREAK
%token TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_PR_END
%token TK_PR_DEFAULT
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO

%%

programa: def programa | def;
def: global | funcao;

tipo: TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL | TK_PR_CHAR | TK_PR_STRING;
literais : TK_LIT_CHAR | TK_LIT_FALSE | TK_LIT_FLOAT | TK_LIT_INT | TK_LIT_STRING | TK_LIT_TRUE;

global: TK_PR_STATIC tipo lista ';'| tipo lista ';';
lista: varglobal ',' lista | varglobal;
varglobal: TK_IDENTIFICADOR | TK_IDENTIFICADOR '[' TK_LIT_INT ']';

funcao : func_header func_block

func_header : 
    tipo TK_IDENTIFICADOR func_params 
    | TK_PR_STATIC tipo TK_IDENTIFICADOR func_params;

func_params : 
    '(' func_prim_arg ')' 
    | '('')'; 

func_prim_arg : 
    tipo TK_IDENTIFICADOR ',' func_prim_arg 
    | TK_PR_CONST tipo TK_IDENTIFICADOR ',' func_prim_arg 
    | tipo TK_IDENTIFICADOR 
    | TK_PR_CONST tipo TK_IDENTIFICADOR;

func_block :
    '{' func_commands '}'
    | '{''}'

func_commands : 
    comando';' func_commands
    | comando';'
    | comando_fluxo
    | comando_fluxo func_commands;

comando : 
    cmd_decl_var
    | cmd_attrib
    | cmd_io
    | cmd_func_call
    | cmd_shift
    | cmd_simple_keyword

comando_fluxo :
    cmd_fluxo;

cmd_decl_var :
    tipo lista_decl_var
    | TK_PR_STATIC tipo lista_decl_var
    | TK_PR_STATIC TK_PR_CONST tipo lista_decl_var
    | TK_PR_CONST tipo lista_decl_var;

lista_decl_var :
    TK_IDENTIFICADOR inic_decl_var
    | TK_IDENTIFICADOR
    | TK_IDENTIFICADOR inic_decl_var ',' lista_decl_var
    | TK_IDENTIFICADOR ',' lista_decl_var

inic_decl_var :
    TK_OC_LE TK_IDENTIFICADOR 
    | TK_OC_LE literais;

cmd_attrib : 
    TK_IDENTIFICADOR '=' exp
    | TK_IDENTIFICADOR'['exp']' '=' exp;

cmd_io : 
    TK_PR_INPUT TK_IDENTIFICADOR
    | TK_PR_OUTPUT TK_IDENTIFICADOR
    | TK_PR_OUTPUT literais;

cmd_func_call : 
    TK_IDENTIFICADOR '('cmd_func_call_args')';

cmd_func_call_args :
    exp
    | exp ',' cmd_func_call_args
    | ;

cmd_shift :
    TK_IDENTIFICADOR shift_op TK_LIT_INT 
    | TK_IDENTIFICADOR'['exp']' shift_op TK_LIT_INT;

shift_op : TK_OC_SL | TK_OC_SR;

cmd_simple_keyword : TK_PR_RETURN exp | TK_PR_BREAK | TK_PR_CONTINUE;

cmd_fluxo :
    TK_PR_IF '('exp')' func_block cmd_fluxo_else
    | cmd_iter;

cmd_fluxo_else :
    TK_PR_ELSE func_block
    | ;

cmd_iter :
    TK_PR_FOR '('cmd_attrib ':' exp ':' cmd_attrib ')' func_block
    | TK_PR_WHILE '(' exp ')' TK_PR_DO func_block;

exp : TK_IDENTIFICADOR | TK_LIT_STRING | TK_LIT_INT;
%%

int yyerror(const char *str)
{
    fprintf(stderr,"error: %s in line %d\n", str, yylineno);
    return 1;
}


