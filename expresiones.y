
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
	cout << "Error sintáctico en la línea "<< n_lineas<<endl;	
} 

%}

%union {
	char cadena [100];
	int numero;
	float real;
	bool bolean;
}

%start programa

%token <cadena> TEMP LIGHT SMOKE
%token <cadena> ALARM SWITCH MSG
%token <cadena> FLOAT INT STRING POS

%token <bolean> TRUE FALSE
%token OR AND EQUAL NOTEQUAL GREATEREQUAL MINOREQUAL

%type <cadena> variable asignacion sensor actuador

%token <cadena> ID CADENA
%token <cadena> escenario SEPARADOR
%token <real> REAL NUMERO
%type <real> expr
//%type <bolean> exprLog

%left OR
%left AND
%right '!'
%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%'   /* asociativo por la izquierda, prioridad alta */
%right '^'	/* asociativo por la derecha, la prioridad más alta */
%nonassoc '(' ')'	/* asociativo por la izquierda, prioridad mas alta que '*', '/' y '%' */
 
%left menos


%%

programa: zona1 SEPARADOR 
	;


zona1: instruccion
	|zona1 instruccion
	;

instruccion:expr ';'		{floatNumber=false; moduloReal = false;}
	//|exprLog ';'		
	|asignacion ';'		{floatNumber = false; moduloReal = false;}
	|variable ';'
	|sensor ';'
	|actuador ';'
	|error 			{yyerrok;}  
	;

variable: INT ID		{cout <<$1<<" "<<$2<<";"<<endl;}
	| FLOAT ID		{cout <<$1<<" "<<$2<<";"<<endl;}
	| STRING ID		{cout <<$1<<" "<<$2<<";"<<endl;}
	| POS ID		{cout <<$1<<" "<<$2<<";"<<endl;}
	| variable ',' ID	{cout<<$1<<","<<$3;}
	|error 			{yyerrok;}  
	;

asignacion: ID '=' expr		{cout <<$1<<" = "<<$3<<";"<<endl;}
	| ID'=''<'expr','expr'>'{cout <<$1<<" = <"<<$4<<","<<$6<<">"<<";"<<endl;}
	| ID '=' CADENA 	{cout <<$1<<" = "<<$3<<";"<<endl;}
	;

sensor: TEMP ID '<'expr','expr'>' CADENA 	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<";"<<endl;}
	| TEMP ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<";"<<endl;}
	| LIGHT ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<";"<<endl;}
	| LIGHT ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<";"<<endl;}
	| LIGHT ID				{cout <<$1<<" "<<$2<<";"<<endl;}
	| SMOKE ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<";"<<endl;}
	| SMOKE ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<";"<<endl;}
	| SMOKE ID				{cout <<$1<<" "<<$2<<";"<<endl;}
	;

actuador: ALARM ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<";"<<endl;}
	| ALARM ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<";"<<endl;}
	| ALARM ID				{cout <<$1<<" "<<$2<<";"<<endl;}
	| SWITCH ID '<'expr','expr'>' CADENA	{cout <<$1<<" "<<$2<<" = <"<<$4<<","<<$6<<"> "<<$8<<";"<<endl;}
	| SWITCH ID ID CADENA			{cout <<$1<<" "<<$2<<" "<<$3<<" "<<$4<<";"<<endl;}
	| SWITCH ID				{cout <<$1<<" "<<$2<<";"<<endl;}
	| MSG ID				{cout <<$1<<" "<<$2<<";"<<endl;}
	;

expr:    NUMERO	 		{$$=$1;}   
        | REAL			{$$=$1; floatNumber = true;} 	
	| ID			{$$=0.0;}
        | expr '+' expr 	{$$=$1+$3;}       	       
        | expr '-' expr    	{$$=$1-$3;}             
        | expr '*' expr         {$$=$1*$3;}
        | expr '/' expr         {if(!floatNumber) $$=(int)$1/(int)$3; else $$=$1/$3;}
        | expr '%' expr		{if(!floatNumber) $$=(int)$1%(int)$3; else moduloReal = true;}
        | expr '^' expr		{$$=pow($1,$3);}
        |'-' expr %prec menos   {$$=-$2;}
        |'(' expr ')' 		{$$=$2;} 	
        ;

/*
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
*/
%%

int main( int argc, char *argv[] ){     
	if (argc != 2) 
		cout <<"error en los argumentos"<<endl;
	else {
     		yyin=fopen(argv[1],"rt");
     		n_lineas = 0;
       		yyparse();
         	return 0;
	}
}







