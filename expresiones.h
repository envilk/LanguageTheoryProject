/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_EXPRESIONES_H_INCLUDED
# define YY_YY_EXPRESIONES_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCENE = 258,
    IF = 259,
    ELSE = 260,
    THEN = 261,
    REPEAT = 262,
    PAUSE = 263,
    START = 264,
    ON = 265,
    OFF = 266,
    TEMP = 267,
    LIGHT = 268,
    SMOKE = 269,
    ALARM = 270,
    SWITCH = 271,
    MSG = 272,
    FLOAT = 273,
    INT = 274,
    STRING = 275,
    POS = 276,
    TRUE = 277,
    FALSE = 278,
    OR = 279,
    AND = 280,
    EQUAL = 281,
    NOTEQUAL = 282,
    GREATEREQUAL = 283,
    MINOREQUAL = 284,
    ID = 285,
    CADENA = 286,
    SEPARADOR = 287,
    CIERRE = 288,
    NUMERO = 289,
    REAL = 290,
    menos = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 70 "expresiones.y" /* yacc.c:1909  */

	char cadena [100];
	int numero;
	float real;
	bool bolean;

#line 98 "expresiones.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESIONES_H_INCLUDED  */
