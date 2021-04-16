#include "token_info.h"
#include "stack.h"


typedef struct str_node {
    // cada nodo tem: um valor e uma lista encadeada de filhos
    char *label; // label precisa pra impressão, mas sera q n devia ser o TOKEN? not sure
    TOKEN_INFO* value; // só é preenchido nos nodos folha
    int tam; // só é usado em nodos que representam vetores
    struct str_node** children;
    int n_child; // numero de filhos (pq é um array de ponteiros) 
    struct str_node* parent;
    struct str_node* next_cmd; // todos os nodos da árvore tem próximo comando, se não é nodo folha. 
    // Separado assim faz mais sentido já que o IF (por ex) pode ter OU não 3 filhos.
    int tipo; // etapa 4

    CODE_BLOCK* code;

} node_t;

node_t* cria_nodo(char *label, TOKEN_INFO *valor);

void libera_nodo(node_t* nodo);

void exporta(node_t* tree);

void libera(node_t* tree);

node_t* add_child(node_t* tree, node_t* child);

node_t* join_nodes(node_t* parent, node_t* child);

node_t* add_next_cmd(node_t* tree, char* label);
