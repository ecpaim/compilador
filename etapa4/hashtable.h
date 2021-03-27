#ifndef HASH_HEADER
#define HASH_HEADER
#include "token_info.h"

enum conteudo_tipo{C_INT, C_FLOAT, C_BOOLEAN, C_CHAR, C_STRING, C_UNDEFINED}; // os nodos da arvore tambem tem esses tipos
enum conteudo_nat{ C_LIT, C_VAR, C_FUNC, C_VET};

typedef struct conteudo{
    int linha; //essa informação já vai estar no yylval
    int natureza; // literal, variavel, funcao ou vetor
    int tipo; // int, float....
    int static_var;
    int const_var;
    int tamanho; // baseado no tipo
    void *argumentos; // isso vai ter que ser uma lista
    TOKEN_INFO *valor; // o yylval

} CONTEUDO;

struct hash_entry
{                           // table entry:
    struct hash_entry *next; // prox entrada
    char *name;             // chave única do conteúdo
    CONTEUDO *content;          // conteúdo da entrada, mudar pra o que precisamos mais pra frente, talvez criar uma struct aqui?
};


typedef struct hash_entry HASH_TBL;

#define HASHSIZE 100

unsigned hash(char *s);

HASH_TBL *lookup(HASH_TBL *hashtab[], char *s);

void add_to_table(HASH_TBL *hashtab[], char *name, void *content);

void free_entry(HASH_TBL *entry);

void clear_table(HASH_TBL *hashtab[], int hash_tab_size);


#endif
