%{
#include "expresiones.h"
#include <math.h>
int n_lineas;
%}



letra [a-zA-Z_]

digito [0-9]

entero {digito}+

caracter [a-zA-Z0-9_]

palabra {caracter}+

real {entero}[.]{entero}?|{entero}?[.]{entero}

identificador {letra}{caracter}*

cientifico [e][+-]?{entero}

cad ["][^"]*["]


%option noyywrap
 
%x  COM1 COM2

%%

"#"                     BEGIN(COM1); 
<COM1>\n                BEGIN(0);
<COM1>.           	;

scene					strcpy(yylval.cadena, yytext); return SCENE;

if					strcpy(yylval.cadena, yytext); return IF;
else					strcpy(yylval.cadena, yytext); return ELSE;
then 					strcpy(yylval.cadena, yytext); return THEN;
repeat					strcpy(yylval.cadena, yytext); return REPEAT;

pause					strcpy(yylval.cadena, yytext); return PAUSE;
start					strcpy(yylval.cadena, yytext); return START;

ON					strcpy(yylval.cadena, yytext); return ON;
OFF					strcpy(yylval.cadena, yytext); return OFF;

temperature				strcpy(yylval.cadena, yytext); return TEMP;
light					strcpy(yylval.cadena, yytext); return LIGHT;
smoke					strcpy(yylval.cadena, yytext); return SMOKE;

alarm					strcpy(yylval.cadena, yytext); return ALARM;
switch					strcpy(yylval.cadena, yytext); return SWITCH;
message					strcpy(yylval.cadena, yytext); return MSG;
']'';'	
float					strcpy(yylval.cadena, yytext); return FLOAT;
int					strcpy(yylval.cadena, yytext); return INT;
string					strcpy(yylval.cadena, yytext); return STRING;
position				strcpy(yylval.cadena, yytext); return POS;

[%][%]					strcpy(yylval.cadena, yytext); return SEPARADOR;

[]][;]					strcpy(yylval.cadena, yytext); return CIERRE;

true					yylval.bolean = true; return TRUE;
false					yylval.bolean = false; return FALSE;
[|][|]					strcpy(yylval.cadena, yytext); return OR;
[&][&]					strcpy(yylval.cadena, yytext); return AND;
[=][=]					strcpy(yylval.cadena, yytext); return EQUAL;
[!][=]					strcpy(yylval.cadena, yytext); return NOTEQUAL;
[<][=]					strcpy(yylval.cadena, yytext); return MINOREQUAL;
[>][=]					strcpy(yylval.cadena, yytext); return GREATEREQUAL;
{identificador}				strcpy(yylval.cadena, yytext); return ID;
[0-9]+					yylval.numero = atoi(yytext); return NUMERO;
{cad} 					strcpy(yylval.cadena, yytext); return CADENA;
{real}					yylval.real = atof(yytext); return REAL;
[\t ]					;	
[\n]					n_lineas++;
. 					return (yytext[0]);
%%
