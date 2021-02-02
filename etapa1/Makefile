all:
	flex scanner.l
	gcc main.c lex.yy.c -o etapa1 -lfl

teste:
	./etapa1 < teste.c

clean:
	rm -rf etapa1 lex.yy.c