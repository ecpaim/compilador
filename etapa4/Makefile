all:
	bison -d parser.y -v --report-file=debug
	flex scanner.l
	gcc -c main.c lex.yy.c parser.tab.c token_info.c tree.c stack.c hashtable.c
	gcc -o etapa4 main.o lex.yy.o parser.tab.o token_info.o tree.o stack.o hashtable.o -lfl

teste:
	./etapa4 < teste.c > saida

clean:
	rm -rf pilha saida grafico etapa4 lex.yy.c lex.yy.o main.o parser.tab.c parser.tab.o parser.tab.h debug token_info.o tree.o


