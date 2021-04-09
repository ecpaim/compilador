%{
#include "stack.h"
#include "tree.h"
#include "token_info.h"
#include "symbol_table.h"

#include<stdio.h>
#include <stdlib.h>

#define YYERROR_VERBOSE 1

extern void *arvore;

extern int yylineno;
int yylex(void);
int yyerror (char const *s);

STACK* hash_stack;
int v_type;
int v_static;
int v_const;
int f_type;

%}

%initial-action
{
	hash_stack = create_stack();
};


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
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
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
%type<no> comando cmd_scope cmd_decl_var lista_decl_var inic_decl_var cmd_attrib cmd_io cmd_func_call cmd_func_call_args 
%type<no> cmd_shift shift_op cmd_simple_keyword cmd_fluxo cmd_fluxo_else cmd_iter
%type<no> unary_op low_precedence high_precedence
%type<no> exp exp_high exp_unit exp_value


%start programa_star
%%
programa_star: 
    programa { arvore = $1; pop_stack(hash_stack);  }
;
programa: 
    def programa { $$ = join_nodes($1, $2); }
    |  { $$ = NULL; }
;
def: 
    global { $$ = NULL; }
    | funcao { $$ = $1; }
;

tipo: 
	TK_PR_INT { $$ = cria_nodo("0", NULL); /* enum C_INT has value 0 */}
	| TK_PR_FLOAT { $$ = cria_nodo("1", NULL); /* C_FLOAT has value 1 */}
	| TK_PR_BOOL { $$ = cria_nodo("2", NULL); }
	| TK_PR_CHAR { $$ = cria_nodo("3", NULL); }
	| TK_PR_STRING { $$ = cria_nodo("4", NULL); }
; 
literais : 
	TK_LIT_CHAR { char str[16]; sprintf(str,"%c",$1->valor.c); $$ = cria_nodo(str,$1); $$->tipo = N_CHAR; }
	| TK_LIT_FALSE { char str[16]; sprintf(str,"false"); $$ = cria_nodo(str,$1); $$->tipo = N_BOOLEAN; }
	| TK_LIT_FLOAT { char str[16]; sprintf(str,"%f",$1->valor.f); $$ = cria_nodo(str,$1); $$->tipo = N_FLOAT;  }
	| TK_LIT_INT { char str[16]; sprintf(str,"%d",$1->valor.i); $$ = cria_nodo(str,$1); $$->tipo = N_INT;  }
	| TK_LIT_STRING { $$ = cria_nodo($1->valor.s,$1); $$->tipo = N_STRING; }
	| TK_LIT_TRUE { char str[16]; sprintf(str,"true"); $$ = cria_nodo(str,$1); $$->tipo = N_BOOLEAN;  }
;

global: 
	TK_PR_STATIC tipo lista ';' { int r = add_var(hash_stack, "global_static", $2, $3, NULL, NULL); if(r != 0) return r;}
	| tipo lista ';' { int r = add_var(hash_stack, "global_non_static", $1, $2, NULL, NULL);  if(r != 0) return r;  }
;
lista: 
	varglobal ',' lista { $$ = join_nodes($1, $3); }
	| varglobal { $$ = $1; }
;
varglobal: 
	TK_IDENTIFICADOR { $$ = cria_nodo($1->valor.s,$1); $$->tam = -1; }
	| TK_IDENTIFICADOR '[' TK_LIT_INT ']' { $$ = cria_nodo($1->valor.s,$1); $$->tam = $3->valor.i; free_token($3); }
	| TK_IDENTIFICADOR '[' '+' TK_LIT_INT ']' { $$ = cria_nodo($1->valor.s,$1); $$->tam = $4->valor.i; free_token($4); }
;

funcao : 
	func_header func_block { 
        add_child($1, $2); 
        $$ = $1; 
       
        }
;
func_header : 
    tipo TK_IDENTIFICADOR {  hash_stack = put_stack(hash_stack); } func_params 
    { 
        $$ = cria_nodo($2->valor.s, $2);
        f_type = atoi($1->label);
        int r = add_function_to_table(hash_stack, $2, $1, 0, $4); if(r!=0) return r;
         
      }
    | TK_PR_STATIC tipo TK_IDENTIFICADOR {  hash_stack = put_stack(hash_stack); } func_params 
    { 
        $$ = cria_nodo($3->valor.s, $3);
        f_type = atoi($2->label);
        int r = add_function_to_table(hash_stack, $3, $2, 1, $5); if(r!=0) return r;
        
     }
;

func_params : 
    '(' func_prim_arg ')' { $$ = $2; }
    | '('')' { $$ = NULL; }
; 

func_prim_arg : 
    tipo TK_IDENTIFICADOR ',' func_prim_arg { 
        node_t* aux_node = cria_nodo($2->valor.s, $2);
        int r = add_func_arg_to_table(hash_stack, $2, $1, 0); if(r!=0) return r;
        $$ = join_nodes(aux_node, $4); 
     }
    | TK_PR_CONST tipo TK_IDENTIFICADOR ',' func_prim_arg { 
        node_t* aux_node = cria_nodo($3->valor.s, $3);
        int r = add_func_arg_to_table(hash_stack, $3, $2, 1); if(r!=0) return r;
        $$ = join_nodes(aux_node, $5);
     }
    | tipo TK_IDENTIFICADOR { 
        int r = add_func_arg_to_table(hash_stack, $2, $1, 0); if(r!=0) return r;
        $$ = cria_nodo($2->valor.s, $2);
       
     }
    | TK_PR_CONST tipo TK_IDENTIFICADOR { 
        int r = add_func_arg_to_table(hash_stack, $3, $2, 1); if(r!=0) return r;
        $$ = cria_nodo($3->valor.s, $3);
     }
; 

func_block :
    '{' func_commands '}' { $$ = $2;   hash_stack = pop_stack(hash_stack); }
    | '{''}' { $$ = NULL;  hash_stack = pop_stack(hash_stack); } // se eu tenho for(a=1;a<10;a++){} eu criei tabela e preciso tirar ela dps
;

func_commands : 
    comando';' func_commands { $$ = join_nodes($1, $3); } 
    | comando ';' { $$ = $1; }
    | cmd_fluxo { $$ = $1; }
    | cmd_fluxo func_commands { $$ = join_nodes($1, $2); }
;

comando : 
    cmd_decl_var { $$ = $1;  }
    | cmd_scope { $$ = $1; }
    | cmd_attrib { $$ = $1; }
    | cmd_io { $$ = $1; }
    | cmd_func_call { $$ = $1; }
    | cmd_shift { $$ = $1; }
    | cmd_simple_keyword { $$ = $1; }
;

cmd_scope: 
    '{' {  hash_stack = put_stack(hash_stack); } func_commands '}' {  $$ = $3; hash_stack = pop_stack(hash_stack); }
;

cmd_decl_var :
    tipo {v_type = atoi($1->label);} lista_decl_var { 
       libera_nodo($1);
        $$ = $3; 
    }
    | TK_PR_STATIC tipo { v_type = atoi($2->label);} lista_decl_var { 
        v_static = 1;
        libera_nodo($2);
        $$ = $4; 
    }
    | TK_PR_STATIC TK_PR_CONST tipo { v_type = atoi($3->label); } lista_decl_var { 
        v_static = 1;
        v_const = 1;
        libera_nodo($3);
        $$ = $5; 
    }
    | TK_PR_CONST tipo {v_type = atoi($2->label);} lista_decl_var { 
        v_const = 1;
        libera_nodo($2);
        $$ = $4; 
    }
;

lista_decl_var :
    TK_IDENTIFICADOR inic_decl_var { 
        $$ = cria_nodo("<=",NULL); 
        node_t* aux = cria_nodo($1->valor.s, NULL);
        add_child($$, aux); 
        add_child($$, $2);  
        int r = verify_var_declaration(hash_stack, $1, v_type, $2, v_static, v_const);
        if( r != 0 ) {
            return r;
        }
    }
    | TK_IDENTIFICADOR { 
        int r = verify_var_declaration(hash_stack, $1, v_type, NULL, v_static, v_const);
        if( r != 0 ) {
            return r;
        }
        $$ = NULL;
    }
    | TK_IDENTIFICADOR inic_decl_var ',' lista_decl_var { 
        $$ = cria_nodo("<=",NULL); 
        node_t* aux = cria_nodo($1->valor.s, NULL);
        int r = verify_var_declaration(hash_stack, $1, v_type, $2, v_static, v_const); if(r != 0) return r;
        add_child($$, aux);
        add_child($$, $2);
        $$ = join_nodes($$, $4);
    }
    | TK_IDENTIFICADOR ',' lista_decl_var { 
        int r = verify_var_declaration(hash_stack, $1, v_type, NULL, v_static, v_const); if(r != 0) return r;
        $$ = $3; 
    }
;
inic_decl_var :
    TK_OC_LE TK_IDENTIFICADOR {
        char str[16]; 
        sprintf(str,"%s",$2->valor.s); 
        $$ = cria_nodo(str,$2); 
    }
    | TK_OC_LE literais {
        $$ = $2; 
    }
;
cmd_attrib : 
    TK_IDENTIFICADOR '=' exp { 
        
        $$ = cria_nodo("=", NULL); 
        node_t* aux = cria_nodo($1->valor.s,$1); 
        add_child($$, aux); 
        add_child($$, $3);
        
        int r = cmd_attrib(hash_stack, $1, $3, 0);
       
        if( r != 0) {
            return r;
        } 
        }
    | TK_IDENTIFICADOR'['exp']' '=' exp { 
        char str[16]; 
        sprintf(str,"%s",$1->valor.s); 
        node_t* aux = cria_nodo(str,$1); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); 
        add_child(aux2,$3); 
        $$ = cria_nodo("=", NULL);
        add_child($$, aux2); 
        add_child($$, $6);
        int r = cmd_attrib(hash_stack, $1, $6, 1);
        if( r != 0) {
            return r;
        } 
        }
;

cmd_io : 
    TK_PR_INPUT TK_IDENTIFICADOR { 
        $$ = cria_nodo("input", NULL); 
        char str2[16]; sprintf(str2,"%s",$2->valor.s); node_t* aux = cria_nodo(str2,$2);
        add_child($$,aux); 
        int r = verify_type_io(hash_stack, $2, "input", 0);
        if (r != 0) {
            return r;
        }
    }
    | TK_PR_OUTPUT TK_IDENTIFICADOR { 
        $$ = cria_nodo("output", NULL); 
        char str2[16]; sprintf(str2,"%s",$2->valor.s); node_t* aux = cria_nodo(str2,$2);
        add_child($$,aux);
        int r = verify_type_io(hash_stack, $2, "output", 0);
        if (r != 0) {
            return r;
        } 
    }
    | TK_PR_OUTPUT literais { 
        $$ = cria_nodo("output", NULL); 
        add_child($$,$2);
        int r = verify_type_io(hash_stack, $2->value, "output", 1);
        if (r != 0) {
            return r;
        } 
    }
;

cmd_func_call : 
    TK_IDENTIFICADOR '('cmd_func_call_args')' {
        $$ = cria_nodo($1->valor.s,$1); 
        add_child($$,$3); 
        int r = verify_exp_ident(hash_stack,"function", $$); if(r != 0) return r;
        r = function_call(hash_stack, $$); if (r != 0) return r;
    }
;

cmd_func_call_args :
    exp { $$ = $1; }
    | exp ',' cmd_func_call_args { $$ = join_nodes($1,$3); }
    | { $$ = NULL; }
;

cmd_shift :
    TK_IDENTIFICADOR shift_op TK_LIT_INT { char str[16]; sprintf(str,"%s",$1->valor.s); node_t* aux = cria_nodo(str,$1); 
       char str2[16]; sprintf(str2,"%d",$3->valor.i); node_t* aux2 = cria_nodo(str2,$3); 
       add_child($2, aux); add_child($2, aux2); $$ = $2; 
       int r = verify_shift_size($3); if(r !=0) return r;}
    | TK_IDENTIFICADOR'['exp']' shift_op TK_LIT_INT { char str[16]; sprintf(str,"%s",$1->valor.s); node_t* aux = cria_nodo(str,$1); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); add_child(aux2,$3); 
        char str3[16]; sprintf(str3,"%d",$6->valor.i); node_t* aux3 = cria_nodo(str3,$6);
        add_child($5, aux2); add_child($5, aux3); $$ = $5;
        int r = verify_shift_size($6); if(r !=0) return r;
        }
;
shift_op : 
    TK_OC_SL { $$ = cria_nodo("<<",NULL); }
    | TK_OC_SR { $$ = cria_nodo(">>", NULL); }
;
cmd_simple_keyword : 
	TK_PR_RETURN exp { $$ = cria_nodo("return", NULL); add_child($$,$2); 
    int r = verify_function_return(hash_stack, $2, f_type);
    if (r != 0) {
        return r;
    } }
	| TK_PR_BREAK { $$ = cria_nodo("break", NULL);  }
	| TK_PR_CONTINUE { $$ = cria_nodo("continue", NULL);  }
;

cmd_fluxo :
    TK_PR_IF { hash_stack = put_stack(hash_stack); } '('exp')' func_block cmd_fluxo_else { 
        $$ = cria_nodo("if", NULL);
        add_child($$, $4);
        add_child($$, $6);
        add_child($$, $7);
    }
    | cmd_iter { $$ = $1; }
;

cmd_fluxo_else :
    TK_PR_ELSE { hash_stack = put_stack(hash_stack); } func_block { $$ = $3;}
    | { $$ = NULL; }
;

cmd_iter :
    TK_PR_FOR { hash_stack = put_stack(hash_stack); } '('cmd_attrib ':' exp ':' cmd_attrib ')' func_block {
        $$ = cria_nodo("for", NULL);
        add_child($$, $4);
        add_child($$, $6);
        add_child($$, $8);
        add_child($$, $10);
	
    }
    | TK_PR_WHILE { hash_stack = put_stack(hash_stack); } '(' exp ')' TK_PR_DO func_block {
        $$ = cria_nodo("while", NULL);
        add_child($$, $4);
        add_child($$, $7);
	
    }
;
unary_op: 
    '+'  { $$ = cria_nodo("+", add_token(yylineno, CHAR_ESP, "+", OC_ID_SC)); }
    | '-' { $$ = cria_nodo("-", add_token(yylineno, CHAR_ESP, "-", OC_ID_SC)); }
    | '!' { $$ = cria_nodo("!", add_token(yylineno, CHAR_ESP, "|", OC_ID_SC)); }
    | '&' { $$ = cria_nodo("&", add_token(yylineno, CHAR_ESP, "&", OC_ID_SC)); }
    | '*' { $$ = cria_nodo("*", add_token(yylineno, CHAR_ESP, "*", OC_ID_SC)); }
    | '?' { $$ = cria_nodo("?", add_token(yylineno, CHAR_ESP, "?", OC_ID_SC)); }
    | '#' { $$ = cria_nodo("#", add_token(yylineno, CHAR_ESP, "#", OC_ID_SC)); }
;

low_precedence:
    '+' { $$ = cria_nodo("+", add_token(yylineno, CHAR_ESP, "+", OC_ID_SC)); }
    | '-' {  $$ = cria_nodo("-", add_token(yylineno, CHAR_ESP, "-", OC_ID_SC)); }
;
high_precedence:
     '*' {  $$ = cria_nodo("*", add_token(yylineno, CHAR_ESP, "*", OC_ID_SC)); }
    | '/' {  $$ = cria_nodo("/", add_token(yylineno, CHAR_ESP, "/", OC_ID_SC)); }
    | '%' {  $$ = cria_nodo("%", add_token(yylineno, CHAR_ESP, "%", OC_ID_SC)); }
    | '|' {  $$ = cria_nodo("|", add_token(yylineno, CHAR_ESP, "|", OC_ID_SC)); }
    | '&' {  $$ = cria_nodo("&", add_token(yylineno, CHAR_ESP, "&", OC_ID_SC)); }
    | '^' {  $$ = cria_nodo("^", add_token(yylineno, CHAR_ESP, "^", OC_ID_SC)); }
    | '<' {  $$ = cria_nodo("<", add_token(yylineno, CHAR_ESP, "<", OC_ID_SC)); }
    | '>' {  $$ = cria_nodo(">", add_token(yylineno, CHAR_ESP, ">", OC_ID_SC)); }
    | TK_OC_LE { $$ = cria_nodo("<=",add_token(yylineno, CHAR_ESP, "<=", OC_ID_SC)); }
    | TK_OC_GE { $$ = cria_nodo(">=",add_token(yylineno, CHAR_ESP, ">=", OC_ID_SC)); }
    | TK_OC_EQ { $$ = cria_nodo("==",add_token(yylineno, CHAR_ESP, "==", OC_ID_SC)); }
    | TK_OC_NE { $$ = cria_nodo("!=",add_token(yylineno, CHAR_ESP, "!=", OC_ID_SC)); }
    | TK_OC_AND { $$ = cria_nodo("&&",add_token(yylineno, CHAR_ESP, "&&", OC_ID_SC)); }
    | TK_OC_OR { $$ = cria_nodo("||",add_token(yylineno, CHAR_ESP, "||", OC_ID_SC)); }
;

exp:
    '(' exp ')' { $$ = $2; }
    | exp low_precedence exp_high { add_child($2,$1); add_child($2,$3); $$ = $2; int r = binary_type_inference($$, $1, $3); if(r != 0) return r;  }
    | exp  low_precedence '(' exp ')' { add_child($2,$1); add_child($2,$4); $$ = $2; int r = binary_type_inference($$, $1, $4); if(r != 0) return r;  }
    | exp '?' exp ':' exp_unit {  $$ = cria_nodo("?:", add_token(yylineno, CHAR_ESP, "?:", OC_ID_SC)); add_child($$,$1); add_child($$,$3); add_child($$,$5); int r = binary_type_inference($$, $3, $5); if(r != 0) return r;  }
    | exp '?' exp ':' '(' exp ')' { $$ = cria_nodo("?:", add_token(yylineno, CHAR_ESP, "?:", OC_ID_SC)); add_child($$,$1); add_child($$,$3); add_child($$,$6); int r = binary_type_inference($$, $3, $6); if(r != 0) return r;  }
    | exp_high { $$ = $1; }
;
exp_high:
     exp_high high_precedence exp_unit { add_child($2,$1); add_child($2,$3); $$ = $2; int r = binary_type_inference($$, $1, $3); if(r != 0) return r;  }
    | exp_high high_precedence '(' exp ')' { add_child($2,$1); add_child($2,$4); $$ = $2; int r = binary_type_inference($$, $1, $4); if(r != 0) return r;  }
    | '(' exp ')' high_precedence exp_unit { add_child($4,$2); add_child($4,$5); $$ = $4; int r = binary_type_inference($$, $2, $5); if(r != 0) return r;  }
    | exp_unit { $$ = $1; }
;
exp_unit: 
    exp_value { $$ = $1; }
    | unary_op exp_value { add_child($1,$2); $$ = $1; int r = unary_type_inference($$, $2); if(r != 0) return r; }
    | unary_op '(' exp ')' { add_child($1,$3); $$ = $1; int r = unary_type_inference($$, $3); if(r != 0) return r; }
;
exp_value: 
    TK_IDENTIFICADOR { $$ = cria_nodo($1->valor.s,$1); int r = verify_exp_ident(hash_stack,"var", $$); if(r != 0) return r; }
    | TK_IDENTIFICADOR '[' exp ']' { node_t* aux = cria_nodo($1->valor.s,$1); int r = verify_exp_ident(hash_stack,"vector", aux); if(r != 0) return r;
    	$$ = cria_nodo("[]",NULL); add_child($$,aux); add_child($$,$3); $$->tipo = aux->tipo; }
    | cmd_func_call { $$ = $1; /*TODO*/ }
    | TK_LIT_INT { char str[16]; sprintf(str,"%d",$1->valor.i); $$ = cria_nodo(str,$1); $$->tipo = N_INT; }
    | TK_LIT_FLOAT { char str[16]; sprintf(str,"%f",$1->valor.f); $$ = cria_nodo(str,$1); $$->tipo = N_FLOAT; }
    | TK_LIT_FALSE { $$ = cria_nodo("false",$1); $$->tipo = N_BOOLEAN; }
    | TK_LIT_TRUE { $$ = cria_nodo("true",$1); $$->tipo = N_BOOLEAN; }
    | TK_LIT_STRING { $$ = cria_nodo($1->valor.s,$1); $$->tipo = N_STRING;  }
    | TK_LIT_CHAR { char str[16]; sprintf(str,"%c",$1->valor.c); $$ = cria_nodo(str,$1); $$->tipo = N_CHAR; }
;

%%
int yyerror(const char *str)
{
    printf("error: %s in line %d\n", str, yylineno);
    return 1;
}


