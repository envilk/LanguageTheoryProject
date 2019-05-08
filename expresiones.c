/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "expresiones.y"


#include <iostream>
#include <math.h>
#include <string.h>
#include "semantico.h"

using namespace std;

//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
extern FILE* yyin;
bool floatNumber = false;
bool moduloReal = false;
tipo_tabla tabla;
tipo_datoTS id;
tipo_valor valor;

//Indica el tipo al definir varias variables con el mismo tipo;
int tipo;

//typedef char tipo_cadena[50];
//typedef tipo_cadena variables[50];
tipo_variables variables;

//definición de procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "Error sintáctico en la línea "<< n_lineas <<endl;	
} 



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "expresiones.y"
{
	char cadena [100];
	int numero;
	float real;
	bool bolean;
}
/* Line 187 of yacc.c.  */
#line 208 "expresiones.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "expresiones.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    41,     2,     2,
      43,    44,    39,    37,    48,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      50,    49,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    12,    14,    17,    23,    29,
      36,    45,    47,    49,    51,    54,    57,    60,    63,    65,
      68,    71,    74,    77,    80,    83,    86,    89,    91,    93,
      96,    99,   102,   105,   109,   111,   113,   117,   121,   129,
     138,   143,   152,   157,   166,   171,   174,   177,   180,   189,
     194,   197,   200,   203,   207,   211,   213,   215,   217,   221,
     225,   229,   233,   237,   241,   244,   248,   250,   252,   254,
     258,   262,   266,   270,   273,   277,   281,   285,   289,   293,
     297
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    32,    55,    -1,    60,    -1,    54,
      60,    -1,    56,    -1,    55,    56,    -1,     3,    30,    46,
      59,    33,    -1,     7,    34,    46,    59,    33,    -1,     4,
      70,     6,    46,    59,    33,    -1,     4,    70,     6,    46,
      59,     5,    59,    33,    -1,    61,    -1,    57,    -1,    58,
      -1,    59,    61,    -1,    59,    57,    -1,    59,    58,    -1,
      64,    47,    -1,    63,    -1,    65,    47,    -1,    67,    47,
      -1,     1,    47,    -1,    66,    47,    -1,    68,    47,    -1,
      62,    47,    -1,     1,    47,    -1,     8,    34,    -1,     8,
      -1,     9,    -1,    19,    30,    -1,    18,    30,    -1,    20,
      30,    -1,    21,    30,    -1,    63,    48,    30,    -1,    47,
      -1,     1,    -1,    30,    49,    69,    -1,    30,    49,    31,
      -1,    30,    49,    50,    69,    48,    69,    51,    -1,    12,
      30,    50,    69,    48,    69,    51,    31,    -1,    12,    30,
      30,    31,    -1,    13,    30,    50,    69,    48,    69,    51,
      31,    -1,    13,    30,    30,    31,    -1,    14,    30,    50,
      69,    48,    69,    51,    31,    -1,    14,    30,    30,    31,
      -1,    30,    35,    -1,    30,    34,    -1,    15,    30,    -1,
      16,    30,    50,    69,    48,    69,    51,    31,    -1,    16,
      30,    30,    31,    -1,    17,    30,    -1,    30,    10,    -1,
      30,    11,    -1,    30,    10,    31,    -1,    30,    10,    30,
      -1,    34,    -1,    35,    -1,    30,    -1,    69,    37,    69,
      -1,    69,    38,    69,    -1,    69,    39,    69,    -1,    69,
      40,    69,    -1,    69,    41,    69,    -1,    69,    42,    69,
      -1,    38,    69,    -1,    43,    69,    44,    -1,    22,    -1,
      23,    -1,    30,    -1,    70,    26,    70,    -1,    70,    27,
      70,    -1,    70,    24,    70,    -1,    70,    25,    70,    -1,
      36,    70,    -1,    43,    70,    44,    -1,    69,    26,    69,
      -1,    69,    27,    69,    -1,    69,    50,    69,    -1,    69,
      29,    69,    -1,    69,    51,    69,    -1,    69,    28,    69,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    82,    83,    86,    87,    90,    93,    96,
      97,   100,   101,   102,   103,   104,   105,   108,   109,   110,
     111,   112,   115,   116,   117,   118,   121,   122,   123,   126,
     127,   128,   129,   130,   131,   132,   135,   147,   158,   172,
     180,   194,   202,   216,   224,   240,   241,   244,   249,   257,
     271,   278,   279,   280,   281,   284,   285,   286,   295,   296,
     297,   298,   299,   300,   301,   302,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCENE", "IF", "ELSE", "THEN", "REPEAT",
  "PAUSE", "START", "ON", "OFF", "TEMP", "LIGHT", "SMOKE", "ALARM",
  "SWITCH", "MSG", "FLOAT", "INT", "STRING", "POS", "TRUE", "FALSE", "OR",
  "AND", "EQUAL", "NOTEQUAL", "GREATEREQUAL", "MINOREQUAL", "ID", "CADENA",
  "SEPARADOR", "CIERRE", "NUMERO", "REAL", "'!'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "'('", "')'", "menos", "'['", "';'", "','", "'='",
  "'<'", "'>'", "$accept", "programa", "zona1", "zona2", "escenario",
  "bucle", "cond", "accion", "definicion", "instruccion", "time",
  "variable", "asignacion", "sensorDef", "sensorInstr", "actuadorDef",
  "actuadorInstr", "expr", "exprLog", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    33,    43,    45,    42,
      47,    37,    94,    40,    41,   291,    91,    59,    44,    61,
      60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     1,     2,     5,     5,     6,
       8,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     2,
       2,     2,     2,     3,     1,     1,     3,     3,     7,     8,
       4,     8,     4,     8,     4,     2,     2,     2,     8,     4,
       2,     2,     2,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     3,    18,     0,     0,
       0,    21,     0,     0,     0,    47,     0,    50,    30,    29,
      31,    32,     0,     1,     0,     4,     0,    17,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,    57,    37,
      55,    56,     0,     0,     0,    36,     0,     2,     5,    33,
      40,     0,    42,     0,    44,     0,    49,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,    65,     0,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    12,    13,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    38,    25,    66,    67,    57,     0,
       0,     0,     0,     0,    26,    51,    52,    46,    45,     7,
      15,    16,    14,    24,    22,    23,    39,    41,    43,    48,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    53,    74,    75,    76,
      80,    78,    77,    79,     0,    71,    72,    69,    70,     0,
       0,     8,     0,     9,     0,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    57,    58,   103,   104,   105,    16,   106,
     107,    17,    18,    19,   108,    20,   109,   121,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -105
static const yytype_int16 yypact[] =
{
      15,   -45,   -26,   -18,   -16,   -11,    23,    39,    43,    46,
      52,    57,    54,  -105,   108,    77,  -105,    62,    74,    82,
      92,  -105,   -13,   -12,    -4,  -105,    21,  -105,  -105,  -105,
    -105,  -105,   195,  -105,   147,  -105,   117,  -105,  -105,  -105,
     124,   246,   125,   246,   128,   246,   134,   246,  -105,  -105,
    -105,  -105,   246,   246,   246,   321,   138,   147,  -105,  -105,
    -105,   253,  -105,   265,  -105,   277,  -105,   289,  -105,   313,
     301,   246,   246,   246,   246,   246,   246,   112,  -105,   246,
     246,   246,   246,  -105,   246,    19,    19,   132,   132,   132,
     132,    76,   202,   209,   217,   224,   232,   120,   185,   142,
     143,  -105,   107,  -105,  -105,   127,  -105,   133,   140,   146,
     148,   168,   175,   178,  -105,  -105,  -105,  -105,    80,   185,
     185,   163,    75,   164,  -105,    33,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
     106,   144,   -19,   246,   246,   246,   246,   246,   246,   165,
     185,   185,   185,   185,    76,  -105,  -105,  -105,   321,   321,
     321,   321,   321,   321,    76,   171,   106,   137,   137,   136,
     118,  -105,    76,  -105,   145,  -105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,  -105,   155,  -104,  -102,   -34,   201,   -95,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,   -32,   -96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -69
static const yytype_int16 yytable[] =
{
      55,   130,    21,   131,    22,   150,   151,   152,   153,    61,
     132,    63,    23,    65,    24,    67,     1,    40,    42,    25,
      68,    69,    70,   140,   142,   157,    44,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    41,    43,    85,
      86,    87,    88,    89,    90,    12,    45,    92,    93,    94,
      95,    46,    96,    26,   165,   166,   167,   168,    73,    74,
      75,    76,    13,   155,   156,   130,   130,   131,   131,    27,
     130,    47,   131,    28,   132,   132,    29,    97,     1,   132,
      98,   149,    30,    99,   100,   101,   -68,    31,   141,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   150,
     151,   152,   153,    32,   -68,   -68,   102,    12,    33,    34,
      36,   158,   159,   160,   161,   162,   163,   125,   126,    97,
     169,    37,    98,   172,    13,    99,   100,   101,    97,    38,
     170,    98,   152,   153,    99,   100,   101,    97,   174,    39,
      98,   127,   128,    99,   100,   101,    97,    59,   102,    98,
      56,   173,    99,   100,   101,    60,    62,   102,    91,    64,
     129,   150,   151,   152,   153,    66,   102,   115,    77,   171,
     143,   144,   145,   146,    76,   102,   123,   124,   175,   136,
     133,    71,    72,    73,    74,    75,    76,   134,    83,   143,
     144,   145,   146,   135,   147,   148,   151,   152,   153,   137,
      71,    72,    73,    74,    75,    76,   138,   116,   117,   139,
     154,   164,    78,   147,   148,   118,    35,     0,     0,    50,
      51,   119,     0,    52,     0,    48,    49,     0,   120,    50,
      51,     0,     0,    52,     0,     0,     0,     0,    53,    71,
      72,    73,    74,    75,    76,    54,    71,    72,    73,    74,
      75,    76,     0,   110,    71,    72,    73,    74,    75,    76,
     111,    71,    72,    73,    74,    75,    76,     0,   112,    71,
      72,    73,    74,    75,    76,   113,    48,     0,     0,     0,
      50,    51,     0,   114,    52,     0,     0,     0,     0,    53,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,    79,    71,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,    80,    71,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,    81,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,    82,    71,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,    84,
      71,    72,    73,    74,    75,    76,     0,    83,    71,    72,
      73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      32,   105,    47,   105,    30,    24,    25,    26,    27,    41,
     105,    43,    30,    45,    30,    47,     1,    30,    30,    30,
      52,    53,    54,   119,   120,    44,    30,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    50,    50,    71,
      72,    73,    74,    75,    76,    30,    50,    79,    80,    81,
      82,    30,    84,    30,   150,   151,   152,   153,    39,    40,
      41,    42,    47,    30,    31,   169,   170,   169,   170,    30,
     174,    50,   174,    30,   169,   170,    30,     1,     1,   174,
       4,     6,    30,     7,     8,     9,     6,    30,   120,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    24,
      25,    26,    27,    49,    24,    25,    30,    30,     0,    32,
      48,   143,   144,   145,   146,   147,   148,    10,    11,     1,
     154,    47,     4,     5,    47,     7,     8,     9,     1,    47,
     164,     4,    26,    27,     7,     8,     9,     1,   172,    47,
       4,    34,    35,     7,     8,     9,     1,    30,    30,     4,
       3,    33,     7,     8,     9,    31,    31,    30,    46,    31,
      33,    24,    25,    26,    27,    31,    30,    47,    30,    33,
      26,    27,    28,    29,    42,    30,    34,    34,    33,    31,
      47,    37,    38,    39,    40,    41,    42,    47,    44,    26,
      27,    28,    29,    47,    50,    51,    25,    26,    27,    31,
      37,    38,    39,    40,    41,    42,    31,    22,    23,    31,
      46,    46,    57,    50,    51,    30,    15,    -1,    -1,    34,
      35,    36,    -1,    38,    -1,    30,    31,    -1,    43,    34,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    37,
      38,    39,    40,    41,    42,    50,    37,    38,    39,    40,
      41,    42,    -1,    51,    37,    38,    39,    40,    41,    42,
      51,    37,    38,    39,    40,    41,    42,    -1,    51,    37,
      38,    39,    40,    41,    42,    51,    30,    -1,    -1,    -1,
      34,    35,    -1,    51,    38,    -1,    -1,    -1,    -1,    43,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      37,    38,    39,    40,    41,    42,    -1,    44,    37,    38,
      39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    30,    47,    53,    54,    60,    63,    64,    65,
      67,    47,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    49,     0,    32,    60,    48,    47,    47,    47,
      30,    50,    30,    50,    30,    50,    30,    50,    30,    31,
      34,    35,    38,    43,    50,    69,     3,    55,    56,    30,
      31,    69,    31,    69,    31,    69,    31,    69,    69,    69,
      69,    37,    38,    39,    40,    41,    42,    30,    56,    48,
      48,    48,    48,    44,    48,    69,    69,    69,    69,    69,
      69,    46,    69,    69,    69,    69,    69,     1,     4,     7,
       8,     9,    30,    57,    58,    59,    61,    62,    66,    68,
      51,    51,    51,    51,    51,    47,    22,    23,    30,    36,
      43,    69,    70,    34,    34,    10,    11,    34,    35,    33,
      57,    58,    61,    47,    47,    47,    31,    31,    31,    31,
      70,    69,    70,    26,    27,    28,    29,    50,    51,     6,
      24,    25,    26,    27,    46,    30,    31,    44,    69,    69,
      69,    69,    69,    69,    46,    70,    70,    70,    70,    59,
      59,    33,     5,    33,    59,    33
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 90 "expresiones.y"
    {cout<<"-- scene "<<(yyvsp[(2) - (5)].cadena);}
    break;

  case 8:
#line 93 "expresiones.y"
    {cout<<"-- repeat "<<(yyvsp[(2) - (5)].numero)<<" times";}
    break;

  case 9:
#line 96 "expresiones.y"
    {cout<<"-- if condicion then";}
    break;

  case 10:
#line 97 "expresiones.y"
    {cout<<"-- if condicion else then";}
    break;

  case 17:
#line 108 "expresiones.y"
    {floatNumber = false; moduloReal = false;;}
    break;

  case 21:
#line 112 "expresiones.y"
    {yyerrok;;}
    break;

  case 25:
#line 118 "expresiones.y"
    {yyerrok;;}
    break;

  case 26:
#line 121 "expresiones.y"
    {cout<<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].numero)<<"; ";;}
    break;

  case 27:
#line 122 "expresiones.y"
    {cout<<(yyvsp[(1) - (1)].cadena)<<"; ";;}
    break;

  case 28:
#line 123 "expresiones.y"
    {cout<<(yyvsp[(1) - (1)].cadena)<<"; ";;}
    break;

  case 29:
#line 126 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena); insertarVariables(variables, (yyvsp[(2) - (2)].cadena), 0, false, tabla); tipo=0;;}
    break;

  case 30:
#line 127 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena); insertarVariables(variables, (yyvsp[(2) - (2)].cadena), 1, false, tabla); tipo=1;;}
    break;

  case 31:
#line 128 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena); insertarVariables(variables, (yyvsp[(2) - (2)].cadena), 2, false, tabla); tipo=2;;}
    break;

  case 32:
#line 129 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena); insertarVariables(variables, (yyvsp[(2) - (2)].cadena), 3, false, tabla); tipo=3;;}
    break;

  case 33:
#line 130 "expresiones.y"
    {cout<<","<<(yyvsp[(3) - (3)].cadena); insertarVariables(variables, (yyvsp[(3) - (3)].cadena), tipo, false, tabla);;}
    break;

  case 34:
#line 131 "expresiones.y"
    {cout<<";"<<endl; insertarVariables(variables, "", tipo, true, tabla); mostrar(tabla);;}
    break;

  case 35:
#line 132 "expresiones.y"
    {yyerrok;;}
    break;

  case 36:
#line 135 "expresiones.y"
    {cout <<(yyvsp[(1) - (3)].cadena)<<" = "<<(yyvsp[(3) - (3)].real)<<"; "; 	
				if(buscar(tabla, (yyvsp[(1) - (3)].cadena), id))
				{
				 if(floatNumber){tipo=1; id.valor.valor_real = (yyvsp[(3) - (3)].real);} 
				 else{tipo=0; id.valor.valor_entero = (yyvsp[(3) - (3)].real);}
				 strcpy(id.nombre, (yyvsp[(1) - (3)].cadena));
				 id.tipo = tipo;
				 insertar (tabla, id);
				}
				else
				 cout<<"ERROR SEMANTICO"<<endl;
				mostrar(tabla);;}
    break;

  case 37:
#line 147 "expresiones.y"
    {cout <<(yyvsp[(1) - (3)].cadena)<<" = "<<(yyvsp[(3) - (3)].cadena)<<"; "; 
				if(buscar(tabla, (yyvsp[(1) - (3)].cadena), id))
				{
				 strcpy(id.valor.valor_cad, (yyvsp[(3) - (3)].cadena));
				 strcpy(id.nombre, (yyvsp[(1) - (3)].cadena));
				 id.tipo = 2;
				 insertar (tabla, id);
				}
				else
				 cout<<"ERROR SEMANTICO"<<endl;
				mostrar(tabla);;}
    break;

  case 38:
#line 158 "expresiones.y"
    {cout <<(yyvsp[(1) - (7)].cadena)<<" = <"<<(yyvsp[(4) - (7)].real)<<","<<(yyvsp[(6) - (7)].real)<<">"<<"; "; 
				if(buscar(tabla, (yyvsp[(1) - (7)].cadena), id))
				{
				 id.valor.valor_pos[0] = (yyvsp[(4) - (7)].real);
				 id.valor.valor_pos[1] = (yyvsp[(6) - (7)].real);
				 strcpy(id.nombre, (yyvsp[(1) - (7)].cadena));
				 id.tipo = 3;
				 insertar (tabla, id);
				}
				else
				 cout<<"ERROR SEMANTICO"<<endl;
				mostrar(tabla);;}
    break;

  case 39:
#line 172 "expresiones.y"
    {cout <<(yyvsp[(1) - (8)].cadena)<<" "<<(yyvsp[(2) - (8)].cadena)<<" <"<<(yyvsp[(4) - (8)].real)<<","<<(yyvsp[(6) - (8)].real)<<"> "<<(yyvsp[(8) - (8)].cadena)<<"; "; 
						strcpy(id.nombre, (yyvsp[(2) - (8)].cadena));
						id.tipo = 10;
						id.pos[0] = (yyvsp[(4) - (8)].real);
						id.pos[1] = (yyvsp[(6) - (8)].real);
						strcpy(id.alias, (yyvsp[(8) - (8)].cadena));
						insertar (tabla, id); 
						mostrar(tabla);;}
    break;

  case 40:
#line 180 "expresiones.y"
    {cout <<(yyvsp[(1) - (4)].cadena)<<" "<<(yyvsp[(2) - (4)].cadena)<<" "<<(yyvsp[(3) - (4)].cadena)<<" "<<(yyvsp[(4) - (4)].cadena)<<"; ";
						if(buscar(tabla, (yyvsp[(3) - (4)].cadena), id))
						{
						 strcpy(id.nombre, (yyvsp[(2) - (4)].cadena));
						 id.tipo = 10;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, (yyvsp[(4) - (4)].cadena));
						 insertar(tabla, id);
						 mostrar(tabla);
						}
						else
						 cout<<"NO EXISTE ESA VARIABLE POS"<<endl;
						;}
    break;

  case 41:
#line 194 "expresiones.y"
    {cout <<(yyvsp[(1) - (8)].cadena)<<" "<<(yyvsp[(2) - (8)].cadena)<<" <"<<(yyvsp[(4) - (8)].real)<<","<<(yyvsp[(6) - (8)].real)<<"> "<<(yyvsp[(8) - (8)].cadena)<<"; ";
						strcpy(id.nombre, (yyvsp[(2) - (8)].cadena));
						id.tipo = 11;
						id.pos[0] = (yyvsp[(4) - (8)].real);
						id.pos[1] = (yyvsp[(6) - (8)].real);
						strcpy(id.alias, (yyvsp[(8) - (8)].cadena));
						insertar (tabla, id); 
						mostrar(tabla);;}
    break;

  case 42:
#line 202 "expresiones.y"
    {cout <<(yyvsp[(1) - (4)].cadena)<<" "<<(yyvsp[(2) - (4)].cadena)<<" "<<(yyvsp[(3) - (4)].cadena)<<" "<<(yyvsp[(4) - (4)].cadena)<<"; ";
						if(buscar(tabla, (yyvsp[(3) - (4)].cadena), id))
						{
						 strcpy(id.nombre, (yyvsp[(2) - (4)].cadena));
						 id.tipo = 11;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, (yyvsp[(4) - (4)].cadena));
						 insertar(tabla, id);
						 mostrar(tabla);
						}
						else
						 cout<<"NO EXISTE ESA VARIABLE POS"<<endl;
						;}
    break;

  case 43:
#line 216 "expresiones.y"
    {cout <<(yyvsp[(1) - (8)].cadena)<<" "<<(yyvsp[(2) - (8)].cadena)<<" <"<<(yyvsp[(4) - (8)].real)<<","<<(yyvsp[(6) - (8)].real)<<"> "<<(yyvsp[(8) - (8)].cadena)<<"; ";
						strcpy(id.nombre, (yyvsp[(2) - (8)].cadena));
						id.tipo = 12;
						id.pos[0] = (yyvsp[(4) - (8)].real);
						id.pos[1] = (yyvsp[(6) - (8)].real);
						strcpy(id.alias, (yyvsp[(8) - (8)].cadena));
						insertar (tabla, id); 
						mostrar(tabla);;}
    break;

  case 44:
#line 224 "expresiones.y"
    {cout <<(yyvsp[(1) - (4)].cadena)<<" "<<(yyvsp[(2) - (4)].cadena)<<" "<<(yyvsp[(3) - (4)].cadena)<<" "<<(yyvsp[(4) - (4)].cadena)<<"; ";
						if(buscar(tabla, (yyvsp[(3) - (4)].cadena), id))
						{
						 strcpy(id.nombre, (yyvsp[(2) - (4)].cadena));
						 id.tipo = 12;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, (yyvsp[(4) - (4)].cadena));
						 insertar(tabla, id);
						 mostrar(tabla);
						}
						else
						 cout<<"NO EXISTE ESA VARIABLE POS"<<endl;
						;}
    break;

  case 45:
#line 240 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].real)<<"; ";;}
    break;

  case 46:
#line 241 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].numero)<<"; ";;}
    break;

  case 47:
#line 244 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena)<<"; ";
						strcpy(id.nombre, (yyvsp[(2) - (2)].cadena));
						id.tipo = 20;
						insertar (tabla, id); 
						mostrar(tabla);;}
    break;

  case 48:
#line 249 "expresiones.y"
    {cout <<(yyvsp[(1) - (8)].cadena)<<" "<<(yyvsp[(2) - (8)].cadena)<<" <"<<(yyvsp[(4) - (8)].real)<<","<<(yyvsp[(6) - (8)].real)<<"> "<<(yyvsp[(8) - (8)].cadena)<<"; ";
						strcpy(id.nombre, (yyvsp[(2) - (8)].cadena));
						id.tipo = 21;
						id.pos[0] = (yyvsp[(4) - (8)].real);
						id.pos[1] = (yyvsp[(6) - (8)].real);
						strcpy(id.alias, (yyvsp[(8) - (8)].cadena));
						insertar (tabla, id); 
						mostrar(tabla);;}
    break;

  case 49:
#line 257 "expresiones.y"
    {cout <<(yyvsp[(1) - (4)].cadena)<<" "<<(yyvsp[(2) - (4)].cadena)<<" "<<(yyvsp[(3) - (4)].cadena)<<" "<<(yyvsp[(4) - (4)].cadena)<<"; ";
						if(buscar(tabla, (yyvsp[(3) - (4)].cadena), id))
						{
						 strcpy(id.nombre, (yyvsp[(2) - (4)].cadena));
						 id.tipo = 21;
						 id.pos[0] = id.valor.valor_pos[0];
						 id.pos[1] = id.valor.valor_pos[1];
						 strcpy(id.alias, (yyvsp[(4) - (4)].cadena));
						 insertar(tabla, id);
						 mostrar(tabla);
						}
						else
						 cout<<"NO EXISTE ESA VARIABLE POS"<<endl;
						;}
    break;

  case 50:
#line 271 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena)<<"; ";
						strcpy(id.nombre, (yyvsp[(2) - (2)].cadena));
						id.tipo = 22;
						insertar (tabla, id); 
						mostrar(tabla);;}
    break;

  case 51:
#line 278 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena)<<"; ";;}
    break;

  case 52:
#line 279 "expresiones.y"
    {cout <<(yyvsp[(1) - (2)].cadena)<<" "<<(yyvsp[(2) - (2)].cadena)<<"; ";;}
    break;

  case 53:
#line 280 "expresiones.y"
    {cout <<(yyvsp[(1) - (3)].cadena)<<" "<<(yyvsp[(2) - (3)].cadena)<<" "<<(yyvsp[(3) - (3)].cadena)<<"; ";;}
    break;

  case 54:
#line 281 "expresiones.y"
    {cout <<(yyvsp[(1) - (3)].cadena)<<" "<<(yyvsp[(2) - (3)].cadena)<<" "<<(yyvsp[(3) - (3)].cadena)<<"; ";;}
    break;

  case 55:
#line 284 "expresiones.y"
    {(yyval.real)=(yyvsp[(1) - (1)].numero);;}
    break;

  case 56:
#line 285 "expresiones.y"
    {(yyval.real)=(yyvsp[(1) - (1)].real); floatNumber = true;;}
    break;

  case 57:
#line 286 "expresiones.y"
    {if(buscar(tabla, (yyvsp[(1) - (1)].cadena), id)) 
				 {
				  if(id.tipo == 0)
				   (yyval.real) = id.valor.valor_entero; 	
				  else if(id.tipo == 1)
				   (yyval.real) = id.valor.valor_real;
				 }
				 else 
 				  cout<<"ERROR SEMANTICO"<<endl;;}
    break;

  case 58:
#line 295 "expresiones.y"
    {(yyval.real)=(yyvsp[(1) - (3)].real)+(yyvsp[(3) - (3)].real);;}
    break;

  case 59:
#line 296 "expresiones.y"
    {(yyval.real)=(yyvsp[(1) - (3)].real)-(yyvsp[(3) - (3)].real);;}
    break;

  case 60:
#line 297 "expresiones.y"
    {(yyval.real)=(yyvsp[(1) - (3)].real)*(yyvsp[(3) - (3)].real);;}
    break;

  case 61:
#line 298 "expresiones.y"
    {if(!floatNumber) (yyval.real)=(int)(yyvsp[(1) - (3)].real)/(int)(yyvsp[(3) - (3)].real); else (yyval.real)=(yyvsp[(1) - (3)].real)/(yyvsp[(3) - (3)].real);;}
    break;

  case 62:
#line 299 "expresiones.y"
    {if(!floatNumber) (yyval.real)=(int)(yyvsp[(1) - (3)].real)%(int)(yyvsp[(3) - (3)].real); else moduloReal = true;;}
    break;

  case 63:
#line 300 "expresiones.y"
    {(yyval.real)=pow((yyvsp[(1) - (3)].real),(yyvsp[(3) - (3)].real));;}
    break;

  case 64:
#line 301 "expresiones.y"
    {(yyval.real)=-(yyvsp[(2) - (2)].real);;}
    break;

  case 65:
#line 302 "expresiones.y"
    {(yyval.real)=(yyvsp[(2) - (3)].real);;}
    break;

  case 66:
#line 306 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (1)].bolean);;}
    break;

  case 67:
#line 307 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (1)].bolean);;}
    break;

  case 68:
#line 308 "expresiones.y"
    {(yyval.bolean)=false;;}
    break;

  case 69:
#line 309 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].bolean)==(yyvsp[(3) - (3)].bolean);;}
    break;

  case 70:
#line 310 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].bolean)!=(yyvsp[(3) - (3)].bolean);;}
    break;

  case 71:
#line 311 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].bolean)||(yyvsp[(3) - (3)].bolean);;}
    break;

  case 72:
#line 312 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].bolean)&&(yyvsp[(3) - (3)].bolean);;}
    break;

  case 73:
#line 313 "expresiones.y"
    {(yyval.bolean)=!(yyvsp[(2) - (2)].bolean);;}
    break;

  case 74:
#line 314 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(2) - (3)].bolean);;}
    break;

  case 75:
#line 315 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].real)==(yyvsp[(3) - (3)].real);;}
    break;

  case 76:
#line 316 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].real)!=(yyvsp[(3) - (3)].real);;}
    break;

  case 77:
#line 317 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].real)<(yyvsp[(3) - (3)].real);;}
    break;

  case 78:
#line 318 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].real)<=(yyvsp[(3) - (3)].real);;}
    break;

  case 79:
#line 319 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].real)>(yyvsp[(3) - (3)].real);;}
    break;

  case 80:
#line 320 "expresiones.y"
    {(yyval.bolean)=(yyvsp[(1) - (3)].real)>=(yyvsp[(3) - (3)].real);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2042 "expresiones.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 323 "expresiones.y"


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








