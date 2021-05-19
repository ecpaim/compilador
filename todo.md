# o que falta fazer
- [ ] Calculo de endereços na declaração de variáveis  
  - Endereço de variáveis locais são um deslocamento em relação ao registrador especial rfp
  - Endereço de variáveis globais são um deslocamento em relação ao registrador especial rbss

- [ ] Expressões aritméticas, com operações unárias, binárias e ternária
  - soma, subtração, divisão e multiplicação

- [ ] Expressões booleanas por controle de fluxo com curto-circuito
  - todos os operadores relacionais
  - todos os operadores lógicos (adote && para o e lógico, || para o ou lógico)

- [x] Comando de atribuição 

- Os seguintes comandos de fluxo de controle
  - [x] if com else opcional
  - [x] while
  - [ ] for

- [x] Chamada de função (com jumpI para um label)

13/05
- [ ] o operador && não tem menos precedência que os operadores aritmeticos (isso é necessário?
- [ ] algumas funções recursivas retornam o valor errado pois os valores dos registradores mudam entre chamadas de funções. Solução: salvar o estado de todos os registradores e carregar da memória quando voltar da função.
