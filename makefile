#fichero Makefile

OBJ = DSPL.o lexico.o semantico.o

execute: DSPL
	./DSPL pruebaDSPL.dsp ejemplo.cpp

DSPL : $(OBJ)     #segunda fase de la tradicción. Generación del código ejecutable 
	g++ -oDSPL $(OBJ)

DSPL.o : DSPL.c       #primera fase de la traducción del analizador sintáctico
	g++ -c -oDSPL.o  DSPL.c 
	
semantico.o: semantico.cpp
	g++ -c -osemantico.o semantico.cpp

lexico.o : lex.yy.c		#primera fase de la traducción del analizador léxico
	g++ -c -olexico.o  lex.yy.c 	

DSPL.c : DSPL.y       #obtenemos el analizador sintáctico en C
	bison -d -oDSPL.c DSPL.y

lex.yy.c: lexico.l	#obtenemos el analizador léxico en C
	flex lexico.l

clean : 
	rm  -f  *.c *.o 

