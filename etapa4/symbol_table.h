
enum type{N_INT, N_FLOAT,N_BOOLEAN, N_CHAR, N_STRING, N_UNDEFINED}; // nodos de controle de fluxo como while têm tipo undefined


//verifies if list of global var is not declared nor a string vector and adds them to hashtable
int add_var(STACK* stack, char *type, node_t* nodo1, node_t* nodo2, TOKEN_INFO *valor1, TOKEN_INFO *valor2);

// checks if an identifier in an expression is a declared variable and sets node->tipo to its correct type
int verify_exp_ident(STACK *stack, char *type, node_t *nodo);

// sets parent->tipo according to the type conversions
int binary_type_inference(node_t *parent, node_t *left, node_t *right);

// sets parent->tipo according to the type conversions
int unary_type_inference(node_t *parent, node_t *son);

int verify_type_io(STACK *stack, TOKEN_INFO *token, char *type, int is_lit);

// function to add function declaration to hash table. Assumes the top of the stack is the scope of the function
int add_function_to_table(STACK *stack, TOKEN_INFO *indentificador, node_t *node, int static_func, node_t *func_params);

// function to variable declaration. ident is the identifier, var_value is the value used to initialize the variable in its declaration
int verify_var_declaration(STACK *stack, TOKEN_INFO *ident, int type, node_t *var_value, int is_static, int is_const);

// function to test if a used identifier is declared in the scope. returns the entry in the entry field
int verify_used_ident(STACK *stack, TOKEN_INFO *ident, HASH_TBL** entry, int, int);

int add_func_arg_to_table(STACK* stack, TOKEN_INFO* identificador, node_t *type, int is_const);

int function_call(STACK *stack, node_t* node);

int cmd_attrib(STACK* stack, TOKEN_INFO* ident, node_t *exp_value, int is_vector);

int get_var_size_by_type(int type);

int verify_function_return(STACK* stack, node_t *exp, int f_type);

int check_type_compatibility(int type1, int type2);

char* print_type(int type);
char *print_natureza(int type);