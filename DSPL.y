
%{

#include <iostream>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "semantico.h"

using namespace std;

//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
extern FILE* yyin;
extern FILE* yyout;
bool floatNumber = false;
bool moduloReal = false;
bool execute = true;
bool errorFichero = false;
tipo_tabla tabla;
tipo_datoTS id;
tipo_valor valor;

//Indica el tipo al definir varias variables con el mismo tipo;
int tipo;

//Indica el numero de bucles anidados
int nBucles=0;

//typedef char tipo_cadena[50];
//typedef tipo_cadena variables[50];
tipo_variables variables;

//definición de procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "Error sintáctico en la línea "<< n_lineas <<endl;	
	errorFichero = true;
} 

void errorSemanticoDefinido(){         /*    llamada por error semantico de la tabla de simbolos */
	cout << "Error semántico en la línea "<< n_lineas <<" por no estar definida la variable, sensor o actuador"<<endl;
} 

void errorSemanticoTipoReal(){         /*    llamada por error semantico de la tabla de simbolos */
	cout << "Error semántico en la línea "<< n_lineas <<" por utilizar valores de tipo real al definir una posición o en una instrucción repeat o pause"<<endl;	
} 

void errorSemanticoOperacionInvalida(){       /*    llamada por error semantico de la tabla de simbolos */
	cout << "Error semántico en la línea "<< n_lineas <<" por realizar operaciones aritméticas con variables de tipo position o string"<<endl;	
}

void errorSemanticoPosicionInvalida(){       /*    llamada por error semantico de la tabla de simbolos */
	cout << "Error semántico en la línea "<< n_lineas <<" por utilizar posiciones fuera de la zona de trabajo permitida (400 * 600) que está definida en la librerı́a entorno dspl"<<endl;	
}

void iniciar()
{
 for(int i=0;i<tabla.max;i++)
 {
  if(tabla.tabla[i].tipo == 10)
   fprintf(yyout, "entornoPonerSensor(%i,%i,S_temperature,0,%s);\n", tabla.tabla[i].pos[0], tabla.tabla[i].pos[1], tabla.tabla[i].alias);
  if(tabla.tabla[i].tipo == 11)
   fprintf(yyout, "entornoPonerSensor(%i,%i,S_temperature,0,%s);\n", tabla.tabla[i].pos[0], tabla.tabla[i].pos[1], tabla.tabla[i].alias);
  if(tabla.tabla[i].tipo == 12)
   fprintf(yyout, "entornoPonerSensor(%i,%i,S_temperature,0,%s);\n", tabla.tabla[i].pos[0], tabla.tabla[i].pos[1], tabla.tabla[i].alias);
  if(tabla.tabla[i].tipo == 21)
   fprintf(yyout, "entornoPonerAct_Switch(%i,%i,false,%s);\n", tabla.tabla[i].pos[0], tabla.tabla[i].pos[1], tabla.tabla[i].alias);
 }
}

%}

%union {
	char cadena [100];
	int numero;
	float real;
	bool bolean;
}

%start programa

%token <cadena> SCENE

%token <cadena> IF ELSE THEN REPEAT
%token <cadena> PAUSE START
%token <cadena> ON OFF

%token <cadena> TEMP LIGHT SMOKE
%token <cadena> ALARM SWITCH MSG
%token <cadena> FLOAT INT STRING POS

%token <bolean> TRUE FALSE 
%token OR AND EQUAL NOTEQUAL GREATEREQUAL MINOREQUAL

%token <cadena> ID CADENA 
%token <cadena> SEPARADOR CIERRE

%token <numero> NUMERO
%token <real> REAL
%type <real> expr
%type <bolean> exprLog

%left OR
%left AND
%right '!'
%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%'   /* asociativo por la izquierda, prioridad alta */
%right '^'	/* asociativo por la derecha, la prioridad más alta */
%nonassoc '(' ')'	/* asociativo por la izquierda, prioridad mas alta que '*', '/' y '%' */
 
%left menos


%%

programa: zona1 SEPARADOR zona2 {fprintf(yyout, "entornoBorrarMensaje();\n"); fprintf(yyout, "entornoTerminar();\n");}
	;


zona1: definicion 
	|zona1 definicion
	;

zona2: escenario 
	|zona2 escenario
	;

escenario: SCENE ID '[' {fprintf(yyout, "entornoPonerEscenario(\"%s\");\n", $2);} accion CIERRE
	;

bucle: REPEAT expr {if(!floatNumber){
		       fprintf(yyout, "for(int i_%i=0;i_%i<%lf;i_%i++){\n", nBucles, nBucles, $2, nBucles);
		       nBucles++;}
	 	      else
		       errorSemanticoTipoReal();} 
		      '[' accion 
		      {if(!floatNumber)
			fprintf(yyout, "}\n"); nBucles=0;}
		       CIERRE 	
 	;

cond: IF exprLog THEN '[' {if($2) execute = true; else execute = false;} accion cuerpoCond
	;

cuerpoCond: CIERRE {execute = true;}
 	| ']' ELSE '[' {if(!execute) execute = true; else execute = false;} accion CIERRE {execute = true;}
	;

accion:	instruccion
	| bucle
	| cond
	| accion instruccion
	| accion bucle 
	| accion cond 
	| error 		{yyerrok;}  
	;

definicion: asignacion ';'		{floatNumber = false; moduloReal = false;}
	| variable 
	|sensorDef ';'			{floatNumber = false; moduloReal = false;}
	|actuadorDef ';'		{floatNumber = false; moduloReal = false;}
	|error ';'			{yyerrok;}  
	;

instruccion: sensorInstr ';'		{floatNumber = false; moduloReal = false;}
	|actuadorInstr ';'
	|time ';'
	|error ';'			{yyerrok;}  
	;

time: PAUSE expr		{if(execute){
  				   if(!floatNumber)
				    fprintf(yyout, "entornoPausa(%lf);\n", $2);
				   else {errorSemanticoTipoReal();}
				 }}
	| PAUSE 		{if(execute) fprintf(yyout, "entornoPulsarTecla();\n");}
	| START 		{iniciar();}
	;
		
variable: INT ID		{insertarVariables(variables, $2); tipo=0;}
	| FLOAT ID		{insertarVariables(variables, $2); tipo=1;}
	| STRING ID		{insertarVariables(variables, $2); tipo=2;}
	| POS ID		{insertarVariables(variables, $2); tipo=3;}
	| variable ',' ID	{insertarVariables(variables, $3);}
	| ';'			{insertarVariablesFinal(variables, tipo, tabla, n_lineas);}
	;

asignacion: ID '=' expr		{if(buscar(tabla, $1, id))
				{
				 if(floatNumber){tipo=1; id.valor.valor_real = $3;} 
				 else{tipo=0; id.valor.valor_entero = $3;}
				 strcpy(id.nombre, $1);
				 id.tipo = tipo;
				 insertar (tabla, id, n_lineas);
				}
				else
				 errorSemanticoDefinido();}
	| ID '=' CADENA 	{if(buscar(tabla, $1, id))
				{
				 strcpy(id.valor.valor_cad, $3);
				 strcpy(id.nombre, $1);
				 id.tipo = 2;
				 insertar (tabla, id, n_lineas);
				}
				else
				 errorSemanticoDefinido();}
	| ID'=''<'expr','expr'>'{if(buscar(tabla, $1, id))
				{
				 if(!floatNumber){
				  if($4<=400 && $6<=600){
			           id.valor.valor_pos[0] = $4;
				   id.valor.valor_pos[1] = $6;
				   strcpy(id.nombre, $1);
				   id.tipo = 3;
				   insertar (tabla, id, n_lineas);
				  }
				  else
				   errorSemanticoPosicionInvalida();
				 }
				 else
				  errorSemanticoTipoReal();
				}
				else
				 errorSemanticoDefinido();}
	;

sensorDef: TEMP ID '<'expr','expr'>' CADENA   {if($4<=400 && $6<=600){
						strcpy(id.nombre, $2);
						id.tipo = 10;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id, n_lineas);}
					       else
						errorSemanticoPosicionInvalida();} 
	| TEMP ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 10;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id, n_lineas);
						}
						 else
						  errorSemanticoDefinido();}
	| LIGHT ID '<'expr','expr'>' CADENA   {if($4<=400 && $6<=600){
						strcpy(id.nombre, $2);
						id.tipo = 11;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id, n_lineas); }
					       else
						errorSemanticoPosicionInvalida();}
	| LIGHT ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 11;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id, n_lineas);
						}
						 else
						  errorSemanticoDefinido();}
	| SMOKE ID '<'expr','expr'>' CADENA    {if($4<=400 && $6<=600){
						strcpy(id.nombre, $2);
						id.tipo = 12;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id, n_lineas);}
					       else
						errorSemanticoPosicionInvalida();}
	| SMOKE ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 12;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id, n_lineas);
						}
						 else
						  errorSemanticoDefinido();}
	;

sensorInstr: ID expr				{if(buscar(tabla, $1, id))
						{
						 if(execute){
						  if(id.tipo == 10)
						   fprintf(yyout, "entornoPonerSensor(%i,%i, S_temperature, %f, %s);\n",id.pos[0],id.pos[1],$2,id.alias);
						  if(id.tipo == 11)
						   fprintf(yyout, "entornoPonerSensor(%i,%i, S_light, %f, %s);\n",id.pos[0],id.pos[1],$2,id.alias);
						  if(id.tipo == 12)
						   fprintf(yyout, "entornoPonerSensor(%i,%i, S_smoke, %f, %s);\n",id.pos[0],id.pos[1],$2,id.alias);
						   id.valor.valor_real = $2;
						   insertar(tabla, id, n_lineas);
 						 }
						}
						 else
						  errorSemanticoDefinido();}
	;

actuadorDef: ALARM ID				{strcpy(id.nombre, $2);
						id.tipo = 20;
						insertar (tabla, id, n_lineas);}
	| SWITCH ID '<'expr','expr'>' CADENA  {if($4<=400 && $6<=600){
						strcpy(id.nombre, $2);
						id.tipo = 21;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id, n_lineas); }
					       else
						errorSemanticoPosicionInvalida();}
	| SWITCH ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 21;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id, n_lineas);
						}
						 else
						  errorSemanticoDefinido();}
	| MSG ID				{strcpy(id.nombre, $2);
						id.tipo = 22;
						insertar (tabla, id, n_lineas);}
	;

actuadorInstr: ID ON 				{if(buscar(tabla, $1, id))
						 {
						 if(execute){
						  if(id.tipo == 20)
						   fprintf(yyout, "entornoAlarma();\n");
						  if(id.tipo == 21)
						   fprintf(yyout, "entornoPonerAct_Switch(%i, %i, true, %s);\n",id.pos[0],id.pos[1],id.alias);
						  }
						 }
						 else
						  errorSemanticoDefinido();}
	| ID OFF				{if(buscar(tabla, $1, id)){
						 if(execute){
						  if(id.tipo == 21)
						   fprintf(yyout, "entornoPonerAct_Switch(%i, %i, false, %s);\n",id.pos[0],id.pos[1],id.alias);
						  }
						 }
						 else
						  errorSemanticoDefinido();}
	| ID ON CADENA				{if(buscar(tabla, $1, id)){
						 if(execute)
						  fprintf(yyout, "entornoMostrarMensaje(%s);\n",$3);}
						 else
						  errorSemanticoDefinido();}
	| ID ON ID				{if(buscar(tabla, $1, id)){
						 if(execute){
						  buscar(tabla, $3, id);
						  fprintf(yyout, "entornoMostrarMensaje(%s);\n",id.valor.valor_cad);
						  }
						 }
						 else
						  errorSemanticoDefinido();}
	;

expr:    NUMERO	 		{$$=$1;}
        | REAL			{$$=$1; floatNumber = true;} 	
	| ID			{if(buscar(tabla, $1, id)) 
				 {
				  if(id.tipo == 0)
				   $$ = id.valor.valor_entero; 	
				  else if(id.tipo == 1)
				   $$ = id.valor.valor_real;
				  else if(id.tipo == 2)
				   errorSemanticoOperacionInvalida();
				  else if(id.tipo == 3)
 				   errorSemanticoOperacionInvalida();
				  else if(id.tipo == 10)
				   $$ = id.valor.valor_real;
				  else if(id.tipo == 11)
				   $$ = id.valor.valor_real;
				  else if(id.tipo == 12)
				   $$ = id.valor.valor_real;
				 }
				 else
				  errorSemanticoDefinido();}
        | expr '+' expr 	{$$=$1+$3;}       	       
        | expr '-' expr    	{$$=$1-$3;}             
        | expr '*' expr         {$$=$1*$3;}
        | expr '/' expr         {if(!floatNumber) $$=(int)$1/(int)$3; else $$=$1/$3;}
        | expr '%' expr		{if(!floatNumber) $$=(int)$1%(int)$3; else moduloReal = true;}
        | expr '^' expr		{$$=pow($1,$3);}
        |'-' expr %prec menos   {$$=-$2;}
        |'(' expr ')' 		{$$=$2;} 	
        ;


exprLog: TRUE			{$$=$1;}
	|FALSE			{$$=$1;}
	| exprLog EQUAL exprLog	{$$=$1==$3;}
	| exprLog NOTEQUAL exprLog{$$=$1!=$3;}
	| exprLog OR exprLog	{$$=$1||$3;}
	| exprLog AND exprLog	{$$=$1&&$3;}
	| '!' exprLog  		{$$=!$2;}
	| '(' exprLog ')'	{$$=$2;}
	| expr EQUAL expr	{$$=$1==$3;}
	| expr NOTEQUAL expr	{$$=$1!=$3;}
	| expr '<' expr		{$$=$1<$3;}
	| expr MINOREQUAL expr	{$$=$1<=$3;}
	| expr '>' expr		{$$=$1>$3;}
	| expr GREATEREQUAL expr{$$=$1>=$3;}
	;

%%

int main( int argc, char *argv[] ){     
	if (argc != 3) 
		cout <<"error en los argumentos" <<endl;
	else {
     		yyin=fopen(argv[1],"rt");
		yyout=fopen(argv[2],"w");
     		n_lineas = 1;


		fprintf(yyout, "#include <iostream>\n");
		fprintf(yyout, "#include \"entorno_dspl.h\"\n");
		fprintf(yyout, "using namespace std;\n");
		fprintf(yyout, "int main() {\n");
		fprintf(yyout, 	"if (entornoIniciar()){\n");

       		yyparse();

		fprintf(yyout, "\t}\n");
		fprintf(yyout, "return 0;\n");
		fprintf(yyout, "}\n");

		fclose(yyin);
		fclose(yyout);
		if(errorFichero){
			cout<<"El fichero "<<argv[2]<<" no se creará debido a un error..."<<endl;
			if(0 > execl("/bin/rm", "rm", argv[2], NULL)){
				cout<<"ERROR AL BORRAR FICHERO "<<argv[2]<<endl;
			}
		}
         	return 0;
	}
}







