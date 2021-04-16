all:
	bison -d parser.y -v --report-file=debug
	flex scanner.l
	gcc -c main.c lex.yy.c parser.tab.c token_info.c tree.c stack.c hashtable.c symbol_table.c iloc_generator.c
	gcc -o etapa5 main.o lex.yy.o parser.tab.o token_info.o tree.o stack.o hashtable.o symbol_table.o iloc_generator.o -lfl

teste:
	./etapa5 < teste.c > saida

clean:
	rm -rf pilha saida grafico etapa5 lex.yy.c lex.yy.o main.o parser.tab.c parser.tab.o parser.tab.h debug token_info.o tree.o stack.o hashtable.o symbol_table.o iloc_generator.o


