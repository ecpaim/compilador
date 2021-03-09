%{
#include<stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "token_info.h"
#define YYERROR_VERBOSE 1

extern void *arvore;

extern int yylineno;
int yylex(void);
int yyerror (char const *s);
%}

%union{
	TOKEN_INFO *valor_lexico;
    node_t *no;
}

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
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_OC_SL
%token<valor_lexico> TK_OC_SR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_LIT_CHAR
%token<valor_lexico> TK_LIT_STRING
%token<valor_lexico> TK_IDENTIFICADOR
%token TOKEN_ERRO

%type<no> programa_star programa def global funcao
%type<no> tipo literais
%type<no> lista varglobal
%type<no> func_header func_params func_prim_arg func_block func_commands
%type<no> comando cmd_decl_var lista_decl_var inic_decl_var cmd_attrib cmd_io cmd_func_call cmd_func_call_args 
%type<no> cmd_shift shift_op cmd_simple_keyword cmd_fluxo cmd_fluxo_else cmd_iter
%type<no> unary_op binary_op
%type<no> exp exp_unit exp_value


%start programa_star
%%
programa_star: 
    programa { arvore = $1; }
;
programa: 
    def programa { $$ = join_nodes($1, $2); }
    |  { $$ = NULL; }
;
def: 
    global { }
    | funcao { $$ = $1; }
;

tipo: 
	TK_PR_INT { }
	| TK_PR_FLOAT { }
	| TK_PR_BOOL {  }
	| TK_PR_CHAR { }
	| TK_PR_STRING { }
; 
literais : 
	TK_LIT_CHAR { char str[16]; sprintf(str,"%c",$1->valor.c); $$ = cria_nodo(str,$1); }
	| TK_LIT_FALSE { char str[16]; sprintf(str,"false"); $$ = cria_nodo(str,$1); }
	| TK_LIT_FLOAT { char str[16]; sprintf(str,"%f",$1->valor.f); $$ = cria_nodo(str,$1); }
	| TK_LIT_INT { char str[16]; sprintf(str,"%d",$1->valor.i); $$ = cria_nodo(str,$1); }
	| TK_LIT_STRING { $$ = cria_nodo($1->valor.s,$1); }
	| TK_LIT_TRUE { char str[16]; sprintf(str,"true"); $$ = cria_nodo(str,$1); }
;

global: 
	TK_PR_STATIC tipo lista ';' { $$ = $3; }
	| tipo lista ';' { $$ = $2; }
;
lista: 
	varglobal ',' lista { /* variaveis sem inicializacao nao fazem parte da arvore */ }
	| varglobal { }
;
varglobal: 
	TK_IDENTIFICADOR { free($1); }
	| TK_IDENTIFICADOR '[' TK_LIT_INT ']' { free($1); free($3); }
	| TK_IDENTIFICADOR '[' '+' TK_LIT_INT ']' { free($1); free($4); }
;

funcao : 
	func_header func_block { $$ = $2; }
;
func_header : 
    tipo TK_IDENTIFICADOR func_params { free($2); }
    | TK_PR_STATIC tipo TK_IDENTIFICADOR func_params { free($3); }
;

func_params : 
    '(' func_prim_arg ')' { }
    | '('')' { }
; 

func_prim_arg : 
    tipo TK_IDENTIFICADOR ',' func_prim_arg { free($2); }
    | TK_PR_CONST tipo TK_IDENTIFICADOR ',' func_prim_arg { free($3); }
    | tipo TK_IDENTIFICADOR { free($2); }
    | TK_PR_CONST tipo TK_IDENTIFICADOR { free($3); }
; 

func_block :
    '{' func_commands '}' { $$ = $2; }
    | '{''}' { $$ = NULL; }
;

func_commands : 
    comando';' func_commands { $$ = join_nodes($1, $3); } 
    | comando';' { $$ = join_nodes($1, NULL); } // por default tem null como next_cmd
    | cmd_fluxo { $$ = join_nodes($1, NULL); }
    | cmd_fluxo func_commands { $$ = join_nodes($1, $2); }
;

comando : 
    cmd_decl_var { $$ = $1; }
    | cmd_attrib { $$ = $1; }
    | cmd_io { $$ = $1; }
    | cmd_func_call { $$ = $1; }
    | cmd_shift { $$ = $1; }
    | cmd_simple_keyword { $$ = $1; }
;

cmd_decl_var :
    tipo lista_decl_var { $$ = $2; }
    | TK_PR_STATIC tipo lista_decl_var { $$ = $3; }
    | TK_PR_STATIC TK_PR_CONST tipo lista_decl_var { $$ = $4; }
    | TK_PR_CONST tipo lista_decl_var { $$ = $3; }
;

lista_decl_var :
    TK_IDENTIFICADOR inic_decl_var { $$ = cria_nodo("<=",NULL); 
        char str2[16]; sprintf(str2,"%s",$1->valor.s); node_t* aux = cria_nodo(str2,$1);
         add_child($$, aux); add_child($$, $2);  }
    | TK_IDENTIFICADOR { free($1); $$ = NULL; }
    | TK_IDENTIFICADOR inic_decl_var ',' lista_decl_var { $$ = cria_nodo("<=",NULL); 
        char str2[16]; sprintf(str2,"%s",$1->valor.s); node_t* aux = cria_nodo(str2,$1);
         add_child($$, aux); add_child($$, $2);  
         $$ = join_nodes($$, $4); }
    | TK_IDENTIFICADOR ',' lista_decl_var { free($1); $$ = $3; }
;
inic_decl_var :
    TK_OC_LE TK_IDENTIFICADOR { free($1); char str[16]; sprintf(str,"%s",$2->valor.s); $$ = cria_nodo(str,$2); }
    | TK_OC_LE literais { free($1); $$ = $2; }
;
cmd_attrib : 
    TK_IDENTIFICADOR '=' exp { $$ = cria_nodo("=", NULL); 
        char str2[16]; sprintf(str2,"%s",$1->valor.s); node_t* aux = cria_nodo(str2,$1); 
        add_child($$, aux); add_child($$, $3); }
    | TK_IDENTIFICADOR'['exp']' '=' exp { char str[16]; sprintf(str,"%s",$1->valor.s); node_t* aux = cria_nodo(str,$1); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); add_child(aux2,$3); 
        $$ = cria_nodo("=", NULL);
        add_child($$, aux2); add_child($$, $6);
        }
;

cmd_io : 
    TK_PR_INPUT TK_IDENTIFICADOR { $$ = cria_nodo("input", NULL); 
        char str2[16]; sprintf(str2,"%s",$2->valor.s); node_t* aux = cria_nodo(str2,$2);
        add_child($$,aux); }
    | TK_PR_OUTPUT TK_IDENTIFICADOR { $$ = cria_nodo("output", NULL); 
        char str2[16]; sprintf(str2,"%s",$2->valor.s); node_t* aux = cria_nodo(str2,$2);
        add_child($$,aux); }
    | TK_PR_OUTPUT literais { $$ = cria_nodo("output", NULL); add_child($$,$2); }
;

cmd_func_call : 
    TK_IDENTIFICADOR '('cmd_func_call_args')' { char str[16]; sprintf(str,"call %s",$1->valor.s); $$ = cria_nodo(str,$1); add_child($$,$3); }
;

cmd_func_call_args :
    exp { $$ = $1; }
    | exp ',' cmd_func_call_args { $$ = join_nodes($1,$3); }
    | { }
;

cmd_shift :
    TK_IDENTIFICADOR shift_op TK_LIT_INT { char str[16]; sprintf(str,"call %s",$1->valor.s); node_t* aux = cria_nodo(str,$1); 
       char str2[16]; sprintf(str2,"%d",$3->valor.i); node_t* aux2 = cria_nodo(str2,$3); 
       add_child($2, aux); add_child($2, aux2); $$ = $2; }
    | TK_IDENTIFICADOR'['exp']' shift_op TK_LIT_INT { char str[16]; sprintf(str,"%s",$1->valor.s); node_t* aux = cria_nodo(str,$1); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); add_child(aux2,$3); 
        char str3[16]; sprintf(str3,"%d",$6->valor.i); node_t* aux3 = cria_nodo(str3,$6);
        add_child($5, aux2); add_child($5, aux3); $$ = $5;
        }
;
shift_op : 
    TK_OC_SL { $$ = cria_nodo("<<",$1); }
    | TK_OC_SR { $$ = cria_nodo(">>",$1); }
;
cmd_simple_keyword : 
	TK_PR_RETURN exp { $$ = cria_nodo("return", NULL); add_child($$,$2); }
	| TK_PR_BREAK { $$ = cria_nodo("break", NULL);  }
	| TK_PR_CONTINUE { $$ = cria_nodo("continue", NULL);  }
;

cmd_fluxo :
    TK_PR_IF '('exp')' func_block cmd_fluxo_else { 
        $$ = cria_nodo("if", NULL);
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $6);
        }
    | cmd_iter { $$ = $1; }
;

cmd_fluxo_else :
    TK_PR_ELSE func_block { $$ = $2;}
    | { $$ = NULL; }
;

cmd_iter :
    TK_PR_FOR '('cmd_attrib ':' exp ':' cmd_attrib ')' func_block {
        $$ = cria_nodo("for", NULL);
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $7);
        add_child($$, $9);
    }
    | TK_PR_WHILE '(' exp ')' TK_PR_DO func_block {
        $$ = cria_nodo("while", NULL);
        add_child($$, $3);
        add_child($$, $6);
    }
;
unary_op: 
    '+'  { $$ = cria_nodo("+", NULL); }
    | '-' { $$ = cria_nodo("-", NULL); }
    | '!' { $$ = cria_nodo("!", NULL); }
    | '&' { $$ = cria_nodo("&", NULL); }
    | '*' { $$ = cria_nodo("*", NULL); }
    | '?' { $$ = cria_nodo("?", NULL); }
    | '#' { $$ = cria_nodo("#", NULL); }
;
binary_op: 
    '+' { $$ = cria_nodo("+", NULL); }
    | '-' {  $$ = cria_nodo("-", NULL); }
    | '*' {  $$ = cria_nodo("*", NULL); }
    | '/' {  $$ = cria_nodo("/", NULL); }
    | '%' {  $$ = cria_nodo("%", NULL); }
    | '|' {  $$ = cria_nodo("|", NULL); }
    | '&' {  $$ = cria_nodo("&", NULL); }
    | '^' {  $$ = cria_nodo("^", NULL); }
    | TK_OC_LE { $$ = cria_nodo("<=",$1); }
    | TK_OC_GE { $$ = cria_nodo(">=",$1); }
    | TK_OC_EQ { $$ = cria_nodo("==",$1); }
    | TK_OC_NE { $$ = cria_nodo("!=",$1); }
    | TK_OC_AND { $$ = cria_nodo("&&",$1); }
    | TK_OC_OR { $$ = cria_nodo("||",$1); }
    | TK_OC_SR { $$ = cria_nodo(">>",$1); }
    | TK_OC_SL { $$ = cria_nodo("<<",$1); }
;
exp : 
    '(' exp ')' { $$ = $2; }
    | exp binary_op exp_unit { add_child($2,$1); add_child($2,$3); $$ = $2;  }
    | exp binary_op '(' exp ')' { add_child($2,$1); add_child($2,$4); $$ = $2;  }
    | exp '?' exp ':' exp_unit {  $$ = cria_nodo("?:", NULL); add_child($$,$1); add_child($$,$3); add_child($$,$5); }
    | exp '?' exp ':' '(' exp ')' { $$ = cria_nodo("?:", NULL); add_child($$,$1); add_child($$,$3); add_child($$,$6); }
    | exp_unit { $$ = $1; }
;
exp_unit: 
    exp_value { $$ = $1; }
    | unary_op exp_value { add_child($1,$2); $$ = $1; }
;
exp_value: 
    TK_IDENTIFICADOR { char str[16]; sprintf(str,"%s",$1->valor.s); $$ = cria_nodo(str,$1); }
    | TK_IDENTIFICADOR '[' exp ']' { char str[16]; sprintf(str,"%s",$1->valor.s); node_t* aux = cria_nodo(str,$1); 
    	$$ = cria_nodo("[]",NULL); add_child($$,aux); add_child($$,$3); }
    | cmd_func_call { $$ = $1; }
    | TK_LIT_INT { char str[16]; sprintf(str,"%d",$1->valor.i); $$ = cria_nodo(str,$1); }
    | TK_LIT_FLOAT { char str[16]; sprintf(str,"%f",$1->valor.f); $$ = cria_nodo(str,$1); }
    | TK_LIT_FALSE { char str[16]; sprintf(str,"%d",$1->valor.b); $$ = cria_nodo(str,$1); }
    | TK_LIT_TRUE { char str[16]; sprintf(str,"%d",$1->valor.b); $$ = cria_nodo(str,$1); }
;

%%
/*
    TODO: REESCREVER ISSO AQUI QUE TIROU PONTO NA ETAPA2
*/
int yyerror(const char *str)
{
    fprintf(stderr,"error: %s in line %d\n", str, yylineno);
    return 1;
}


