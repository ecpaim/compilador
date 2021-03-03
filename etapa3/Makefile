all:
	bison -d parser.y -v --report-file=debug
	flex scanner.l
	gcc -c main.c lex.yy.c parser.tab.c token_info.c
	gcc -o etapa3 main.o lex.yy.o parser.tab.o token_info.o -lfl

teste:
	./etapa3 < teste.c > saida

clean:
	rm -rf etapa3 lex.yy.c lex.yy.o main.o parser.tab.c parser.tab.o parser.tab.h debug token_info.o


