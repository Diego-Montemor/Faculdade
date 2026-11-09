calc : calc.l calc.y;
	flex -o lexico.c calc.l;
	bison -o calc.c calc.y -v -d;
	gcc calc.c -o calc;