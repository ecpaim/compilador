all:
	bison -d parser.y
	flex scanner.l
	gcc -o etapa2 lex.yy.c parser.tab.c main.c -lfl

teste:
	./etapa2 < teste.c

clean:
	rm -rf etapa2
	rm -rf lex.yy.o
	rm -rf lex.yy.c
	rm -rf parser.tab.o
	rm -rf parser.tab.c
	rm -rf parser.tab.h