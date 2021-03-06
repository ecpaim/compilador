#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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

node_t* cria_nodo(char *label){
    node_t *nodo = malloc(sizeof(node_t));
    nodo->n_child = 0;
    nodo->label = strdup(label);
    nodo->children = NULL;
    nodo->parent = NULL;
    nodo->next_cmd = NULL;
    
    return nodo;
}

void exporta(node_t* tree){
    if (tree->label != NULL){
        printf("%p [label=\"%s\"]\n", tree, tree->label);
    }

    for (int i=0; i < tree->n_child; i++){
        printf("%p, %p\n", tree, tree->children[i]);
        exporta(tree->children[i]);
    } 
    if (tree->next_cmd != NULL){
        exporta(tree->next_cmd);
    }  
}

void libera(node_t* tree){ // essa função provavelmente tá errada
    for (int i=0; i < tree->n_child; i++){
        libera(tree->children[i]);
    } 
    if (tree->next_cmd != NULL){
        libera(tree->next_cmd);
    }

    free(tree->next_cmd);
    free(tree->children);
    free(tree->label);
    free(tree);
}

node_t* add_child(node_t* tree, char* label){
    node_t* new_node = cria_nodo(label);
    new_node->parent = tree;

    tree->children = realloc(tree->children, (tree->n_child + 2) * sizeof(*new_node)); // aumento o numero de filhos no ponteiro. o +2 é oq quanto ta em 0 eu vou por 1 preciso de espaço p +2 (null e ptr)
    tree->children[tree->n_child++] = new_node;
    tree->children[tree->n_child] = NULL;
    
    return new_node;
}

node_t* add_next_cmd(node_t* tree, char* label){
    node_t* new_node = cria_nodo(label);
    new_node->parent = tree;

    tree->next_cmd = new_node;
    
    return new_node;
}

int main(){
    char n[] = "diego";
    void* arvore = cria_nodo(n);
    add_child(arvore, "diego junior");
    node_t* filha = add_child(arvore, "diega");
    add_child(filha, "dieguinho");
    exporta(arvore);
    libera(arvore);
}