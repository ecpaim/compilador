
enum type{N_INT, N_FLOAT,N_BOOLEAN, N_CHAR, N_STRING, N_UNDEFINED}; // nodos de controle de fluxo como while têm tipo undefined

int add_var(STACK* stack, char *type, node_t* nodo1, node_t* nodo2, TOKEN_INFO *valor1, TOKEN_INFO *valor2);
int verify_type_io(STACK* stack, TOKEN_INFO* identificador, char* type);