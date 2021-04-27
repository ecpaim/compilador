#include "tree.h"
#include "token_info.h"
#include "stack.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node_t* cria_nodo(char *label, TOKEN_INFO *valor){
    node_t *nodo = malloc(sizeof(node_t));
    nodo->value = valor;
    nodo->n_child = 0;
    nodo->label = strdup(label);
    nodo->children = NULL;
    nodo->parent = NULL;
    nodo->next_cmd = NULL;
    nodo->code = NULL;
    
    return nodo;
}

void libera_nodo(node_t* nodo){

	free(nodo->label);
	free_token(nodo->value);
	free(nodo);
	
	return;
}

void exporta(node_t* tree){
    if (tree == NULL)
        return;


    for (int i=0; i < tree->n_child; i++){
        printf("%p, %p\n", tree, tree->children[i]);
        exporta(tree->children[i]);
    } 
    if (tree->next_cmd != NULL){
        printf("%p, %p\n", tree, tree->next_cmd);
        exporta(tree->next_cmd);
    }  

    if (tree->label != NULL){
        printf("%p [label=\"%s\"]\n", tree, tree->label);
    }
}

void libera(node_t* tree){ 
    if (tree == NULL)
        return;
    
    int n_child = tree->n_child;
    for (int i=0; i < n_child; i++){
        tree->n_child--;
        libera(tree->children[i]);
        
    } 
    if (tree->next_cmd != NULL){
        libera(tree->next_cmd);
        
    }

    if(tree != NULL) {
        if(tree->label != NULL)
            free(tree->label);
        if(tree->value != NULL){
            if(tree->value->tipo != LIT || tree->value->tipo_lit == STRING){ // libera o espaço da string que tem nos TOKEN_INFO
                free(tree->value->valor.s);
            }
            free(tree->value);
        }
        if(tree->n_child == 0){
            free(tree->children);
        }
        free(tree);
    }
}

node_t* add_child(node_t* tree, node_t* child){
    if (tree == NULL || child == NULL)
        return NULL;
    // não adiciona nodo filho em/de nodo nulo
    child->parent = tree;

    tree->children = realloc(tree->children, (tree->n_child + 2) * sizeof(*child)); // aumento o numero de filhos no ponteiro. o +2 é oq quanto ta em 0 eu vou por 1 preciso de espaço p +2 (null e ptr)
    tree->children[tree->n_child++] = child;
    tree->children[tree->n_child] = NULL;
    
    return child;
}

node_t* join_nodes(node_t* parent, node_t* child){ 
    if( parent == NULL) // se o parent for null retorna a child e vice versa. se os dois forem null tambem
        return child;
    else if (child == NULL)
        return parent;
    
    
    child->parent = parent;
    parent->next_cmd = child;
    
    return parent;
}
