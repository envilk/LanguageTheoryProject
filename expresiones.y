
%{

#include <iostream>
#include <math.h>

using namespace std;

//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
extern FILE* yyin;
bool floatNumber = false;
bool moduloReal = false;

//definición de procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "Error sintáctico en la línea "<< n_lineas <<endl;	
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

%token <real> REAL NUMERO
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

programa: zona1 SEPARADOR zona2
	;


zona1: instruccion
	|zona1 instruccion
	;

zona2: escenario
	|zona2 escenario
	;

escenario: SCENE ID '[' accion CIERRE		{cout<<"-- scene "<<$2}
	;

bucle: REPEAT NUMERO '[' accion CIERRE 		{cout<<"-- repeat "<<$2<<" times"}
 	;

cond: IF exprLog THEN '[' accion CIERRE		{cout<<"-- if condicion then"}
	| IF exprLog THEN '[' accion ELSE accion CIERRE {cout<<"-- if condicion else then"}
	;

accion:	instruccion
	| bucle
	| cond
	| accion instruccion
	| accion bucle 
	| accion cond 
	;

instruccion:expr ';'		{floatNumber=false; moduloReal = false;}
	|asignacion ';'		{floatNumber = false; moduloReal = false;}
	|variable ';'
	|sensor ';'
	|actuador ';'
	|time ';'
	|error 			{yyerrok;}  
	;

time: PAUSE NUMERO		{cout<<$1<<" "<<$2<<"; ";}
	| PAUSE 		{cout<<$1<<"; ";}
	| START 		{cout<<$1<<"; ";}
	;

variable: INT ID		{cout <<$1<<" "<<$2<<"; ";}
	| FLOAT ID		{cout <<$1<<" "<<$2<<"; ";}
	| STRING ID		{cout <<$1<<" "<<$2<<"; ";}
	| POS ID		{cout <<$1<<" "<<$2<<"; ";}
	| variable ',' ID	{cout<<","<<$3<<" ";}
	| error 		{yyerrok;}  
	;

asignacion: ID '=' expr		{cout <<$1<<" = "<<$3<<"; ";}
	| ID'=''<'expr','expr'>'{cout <<$1<<" = <"<<$4<<","<<$6<<">"<<"; ";}
	| ID '=' CADENA 	{cout <<$1<<" = "<<$3<<"; ";}
	;

sensor: TEMP ID '<'expr','expr'>' CADENA 	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<"; ";}
	| TEMP ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<"; ";}
	| LIGHT ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<"; ";}
	| LIGHT ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<"; ";}
	| LIGHT ID				{cout <<$1<<" "<<$2<<"; ";}
	| SMOKE ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<"; ";}
	| SMOKE ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<"; ";}
	| SMOKE ID				{cout <<$1<<" "<<$2<<"; ";}
	//
	| ID REAL				{cout <<$1<<" "<<$2<<"; ";}
	| ID NUMERO				{cout <<$1<<" "<<$2<<"; ";}
	;

actuador: ALARM ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<"; ";}
	| ALARM ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<"; ";}
	| ALARM ID				{cout <<$1<<" "<<$2<<"; ";}
	| SWITCH ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<"; ";}
	| SWITCH ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<"; ";}
	| SWITCH ID				{cout <<$1<<" "<<$2<<"; ";}
	| MSG ID				{cout <<$1<<" "<<$2<<"; ";}
	//
	| ID ON 				{cout <<$1<<" "<<$2<<"; ";}
	| ID OFF				{cout <<$1<<" "<<$2<<"; ";}
	| ID ON CADENA				{cout <<$1<<" "<<$2<<" "<<$3<<"; ";}
	| ID ON ID				{cout <<$1<<" "<<$2<<" "<<$3<<"; ";}
	;

expr:    NUMERO	 		{$$=$1;}
        | REAL			{$$=$1; floatNumber = true;} 	
	| ID			{$$=0.0;}//PARA PROBAR
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
	|ID			{$$=false;}//PARA PROBAR
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
	if (argc != 2) 
		cout <<"error en los argumentos" <<endl;
	else {
     		yyin=fopen(argv[1],"rt");
     		n_lineas = 0;
       		yyparse();
         	return 0;
	}
}







