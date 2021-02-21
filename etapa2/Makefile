all:
	bison -d parser.y -v --report-file=debug
	flex scanner.l
	gcc -c main.c lex.yy.c parser.tab.c
	gcc -o parser main.o lex.yy.o parser.tab.o -lfl

teste:
	./parser < teste.c

clean:
	rm -rf parser lex.yy.c lex.yy.o main.o parser.tab.c parser.tab.o parser.tab.h debug


