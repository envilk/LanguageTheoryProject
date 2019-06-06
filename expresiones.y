
%{

#include <iostream>
#include <math.h>
#include <string.h>
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

bucle: REPEAT NUMERO {fprintf(yyout, "for(int i_%i=0;i_%i<%i;i_%i++){\n", nBucles, nBucles, $2, nBucles);nBucles++;} '[' accion {fprintf(yyout, "}\n");} CIERRE 	
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
	;

definicion: asignacion ';'		{floatNumber = false; moduloReal = false;}
	| variable 
	|sensorDef ';'
	|actuadorDef ';'
	|error ';'			{yyerrok;}  
	;

instruccion: sensorInstr ';'
	|actuadorInstr ';'
	|time ';'
	|error ';'			{yyerrok;}  
	;

time: PAUSE NUMERO		{if(execute) fprintf(yyout, "entornoPausa(%i);\n", $2);}
	| PAUSE 		{if(execute) fprintf(yyout, "entornoPulsarTecla();\n");}
	| START 		{iniciar();}
	;
		
variable: INT ID		{insertarVariables(variables, $2, 0, false, tabla); tipo=0;}
	| FLOAT ID		{insertarVariables(variables, $2, 1, false, tabla); tipo=1;}
	| STRING ID		{insertarVariables(variables, $2, 2, false, tabla); tipo=2;}
	| POS ID		{insertarVariables(variables, $2, 3, false, tabla); tipo=3;}
	| variable ',' ID	{insertarVariables(variables, $3, tipo, false, tabla);}
	| ';'			{insertarVariables(variables, "", tipo, true, tabla);}
	| error 		{yyerrok;}  
	;

asignacion: ID '=' expr		{if(buscar(tabla, $1, id))
				{
				 if(floatNumber){tipo=1; id.valor.valor_real = $3;} 
				 else{tipo=0; id.valor.valor_entero = $3;}
				 strcpy(id.nombre, $1);
				 id.tipo = tipo;
				 insertar (tabla, id);
				}}
	| ID '=' CADENA 	{if(buscar(tabla, $1, id))
				{
				 strcpy(id.valor.valor_cad, $3);
				 strcpy(id.nombre, $1);
				 id.tipo = 2;
				 insertar (tabla, id);
				}}
	| ID'=''<'expr','expr'>'{if(buscar(tabla, $1, id))
				{
				 id.valor.valor_pos[0] = $4;
				 id.valor.valor_pos[1] = $6;
				 strcpy(id.nombre, $1);
				 id.tipo = 3;
				 insertar (tabla, id);
				}}
	;

sensorDef: TEMP ID '<'expr','expr'>' CADENA 	{strcpy(id.nombre, $2);
						id.tipo = 10;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id);}
	| TEMP ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 10;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id);
						}}
	| LIGHT ID '<'expr','expr'>' CADENA	{strcpy(id.nombre, $2);
						id.tipo = 11;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id); }
	| LIGHT ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 11;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id);
						}}
	| SMOKE ID '<'expr','expr'>' CADENA	{strcpy(id.nombre, $2);
						id.tipo = 12;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id);}
	| SMOKE ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 12;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id);
						}}
	;

sensorInstr: ID expr				{if(buscar(tabla, $1, id)  && execute)
						{
						 if(id.tipo == 10)
						  fprintf(yyout, "entornoPonerSensor(%i,%i, S_temperature, %f, %s);\n",id.pos[0],id.pos[1],$2,id.alias);
						 if(id.tipo == 11)
						  fprintf(yyout, "entornoPonerSensor(%i,%i, S_light, %f, %s);\n",id.pos[0],id.pos[1],$2,id.alias);
						 if(id.tipo == 12)
						  fprintf(yyout, "entornoPonerSensor(%i,%i, S_smoke, %f, %s);\n",id.pos[0],id.pos[1],$2,id.alias);
						 id.valor.valor_real = $2;
						 insertar(tabla, id);
						}}
	;

actuadorDef: ALARM ID				{strcpy(id.nombre, $2);
						id.tipo = 20;
						insertar (tabla, id);}
	| SWITCH ID '<'expr','expr'>' CADENA	{strcpy(id.nombre, $2);
						id.tipo = 21;
						id.pos[0] = $4;
						id.pos[1] = $6;
						strcpy(id.alias, $8);
						insertar (tabla, id); }
	| SWITCH ID ID CADENA			{if(buscar(tabla, $3, id))
						{
						 strcpy(id.nombre, $2);
						 id.tipo = 21;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, $4);
						 insertar(tabla, id);
						}}
	| MSG ID				{strcpy(id.nombre, $2);
						id.tipo = 22;
						insertar (tabla, id);}
	;

actuadorInstr: ID ON 				{if(buscar(tabla, $1, id) && execute)
						 {
						  if(id.tipo == 20)
						   fprintf(yyout, "entornoAlarma();\n");
						  if(id.tipo == 21)
						   fprintf(yyout, "entornoPonerAct_Switch(%i, %i, true, %s);\n",id.pos[0],id.pos[1],id.alias);
						 }}
	| ID OFF				{if(buscar(tabla, $1, id) && execute)
						 {
						  if(id.tipo == 21)
						   fprintf(yyout, "entornoPonerAct_Switch(%i, %i, false, %s);\n",id.pos[0],id.pos[1],id.alias);
						 }}
	| ID ON CADENA				{if(buscar(tabla, $1, id) && execute)
						  fprintf(yyout, "entornoMostrarMensaje(%s);\n",$3);}
	| ID ON ID				{if(buscar(tabla, $1, id) && execute){
						  buscar(tabla, $3, id);
						  fprintf(yyout, "entornoMostrarMensaje(%s);\n",id.valor.valor_cad);
						 }}
	;

expr:    NUMERO	 		{$$=$1;}
        | REAL			{$$=$1; floatNumber = true;} 	
	| ID			{if(buscar(tabla, $1, id)) 
				 {
				  if(id.tipo == 0)
				   $$ = id.valor.valor_entero; 	
				  else if(id.tipo == 1)
				   $$ = id.valor.valor_real;
				  else if(id.tipo == 10)
				   $$ = id.valor.valor_real;
				  else if(id.tipo == 11)
				   $$ = id.valor.valor_real;
				  else if(id.tipo == 12)
				   $$ = id.valor.valor_real;
				 }}
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
     		n_lineas = 0;


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
         	return 0;
	}
}







