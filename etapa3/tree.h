typedef struct str_node {
    // cada nodo tem: um valor e uma lista encadeada de filhos
    char *label; // label precisa pra impressão, mas sera q n devia ser o TOKEN? not sure
    struct str_node** children;
    int n_child; // numero de filhos (pq é um array de ponteiros) 
    struct str_node* parent;
    struct str_node* next_cmd; // todos os nodos da árvore tem próximo comando, se não é nodo folha. 
    // Separado assim faz mais sentido já que o IF (por ex) pode ter OU não 3 filhos.
    // Se tiver 3 filhos como sabemos se o último é o comando do THEN ou o próximo nodo?
} node_t;

node_t* cria_nodo(char *label);

void exporta(node_t* tree);

void libera(node_t* tree);

node_t* add_child(node_t* tree, char* label);

node_t* join_nodes(node_t* parent, node_t* child);

node_t* add_next_cmd(node_t* tree, char* label);