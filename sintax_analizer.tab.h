/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTAX_ANALIZER_TAB_H_INCLUDED
# define YY_YY_SINTAX_ANALIZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR_KW = 258,                 /* CHAR_KW  */
    INT_KW = 259,                  /* INT_KW  */
    FLOAT_KW = 260,                /* FLOAT_KW  */
    BOOL_KW = 261,                 /* BOOL_KW  */
    STRING_KW = 262,               /* STRING_KW  */
    VOID_KW = 263,                 /* VOID_KW  */
    IF_KW = 264,                   /* IF_KW  */
    ELSE_KW = 265,                 /* ELSE_KW  */
    SWITCH_KW = 266,               /* SWITCH_KW  */
    CASE_KW = 267,                 /* CASE_KW  */
    DEFAULT_KW = 268,              /* DEFAULT_KW  */
    FOR_KW = 269,                  /* FOR_KW  */
    WHILE_KW = 270,                /* WHILE_KW  */
    DO_KW = 271,                   /* DO_KW  */
    BREAK_KW = 272,                /* BREAK_KW  */
    RETURN_KW = 273,               /* RETURN_KW  */
    TRUE_KW = 274,                 /* TRUE_KW  */
    FALSE_KW = 275,                /* FALSE_KW  */
    FUNCTION_KW = 276,             /* FUNCTION_KW  */
    TRY_KW = 277,                  /* TRY_KW  */
    CATCH_KW = 278,                /* CATCH_KW  */
    FINALLY_KW = 279,              /* FINALLY_KW  */
    THROW_KW = 280,                /* THROW_KW  */
    NULL_KW = 281,                 /* NULL_KW  */
    OP_INC = 282,                  /* OP_INC  */
    OP_DEC = 283,                  /* OP_DEC  */
    OP_ADD = 284,                  /* OP_ADD  */
    OP_SUB = 285,                  /* OP_SUB  */
    OP_MUL = 286,                  /* OP_MUL  */
    OP_DIV = 287,                  /* OP_DIV  */
    OP_MOD = 288,                  /* OP_MOD  */
    OP_AND = 289,                  /* OP_AND  */
    OP_OR = 290,                   /* OP_OR  */
    OP_NOT = 291,                  /* OP_NOT  */
    OP_EQ = 292,                   /* OP_EQ  */
    OP_NEQ = 293,                  /* OP_NEQ  */
    OP_GT = 294,                   /* OP_GT  */
    OP_LT = 295,                   /* OP_LT  */
    OP_GTE = 296,                  /* OP_GTE  */
    OP_LTE = 297,                  /* OP_LTE  */
    OP_ASSIGN = 298,               /* OP_ASSIGN  */
    OP_ADD_ASSIGN = 299,           /* OP_ADD_ASSIGN  */
    OP_SUB_ASSIGN = 300,           /* OP_SUB_ASSIGN  */
    OP_MUL_ASSIGN = 301,           /* OP_MUL_ASSIGN  */
    OP_DIV_ASSIGN = 302,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 303,           /* OP_MOD_ASSIGN  */
    UMINUS = 304,                  /* UMINUS  */
    LEFT_PARENT = 305,             /* LEFT_PARENT  */
    RIGHT_PARENT = 306,            /* RIGHT_PARENT  */
    LEFT_BRACKET = 307,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 308,           /* RIGHT_BRACKET  */
    LEFT_SQUARE = 309,             /* LEFT_SQUARE  */
    RIGHT_SQUARE = 310,            /* RIGHT_SQUARE  */
    COMMA = 311,                   /* COMMA  */
    DOT = 312,                     /* DOT  */
    D_COLON = 313,                 /* D_COLON  */
    COLON = 314,                   /* COLON  */
    CHAR = 315,                    /* CHAR  */
    STRING = 316,                  /* STRING  */
    NUM = 317,                     /* NUM  */
    NUM_DEC = 318,                 /* NUM_DEC  */
    IDENTIFIER = 319,              /* IDENTIFIER  */
    EOL = 320                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 189 "sintax_analizer.y"

    int ival;
    char *sval;

#line 134 "sintax_analizer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTAX_ANALIZER_TAB_H_INCLUDED  */
