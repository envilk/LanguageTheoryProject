/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define SCENE 258
#define IF 259
#define ELSE 260
#define THEN 261
#define REPEAT 262
#define PAUSE 263
#define START 264
#define ON 265
#define OFF 266
#define TEMP 267
#define LIGHT 268
#define SMOKE 269
#define ALARM 270
#define SWITCH 271
#define MSG 272
#define FLOAT 273
#define INT 274
#define STRING 275
#define POS 276
#define TRUE 277
#define FALSE 278
#define OR 279
#define AND 280
#define EQUAL 281
#define NOTEQUAL 282
#define GREATEREQUAL 283
#define MINOREQUAL 284
#define ID 285
#define CADENA 286
#define SEPARADOR 287
#define CIERRE 288
#define NUMERO 289
#define REAL 290
#define menos 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "expresiones.y"
{
	char cadena [100];
	int numero;
	float real;
	bool bolean;
}
/* Line 1489 of yacc.c.  */
#line 128 "expresiones.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

