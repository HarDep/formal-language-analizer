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
    OP_ASSIGN = 258,               /* OP_ASSIGN  */
    OP_ADD_ASSIGN = 259,           /* OP_ADD_ASSIGN  */
    OP_SUB_ASSIGN = 260,           /* OP_SUB_ASSIGN  */
    OP_MUL_ASSIGN = 261,           /* OP_MUL_ASSIGN  */
    OP_DIV_ASSIGN = 262,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 263,           /* OP_MOD_ASSIGN  */
    OP_AND = 264,                  /* OP_AND  */
    OP_OR = 265,                   /* OP_OR  */
    OP_EQ = 266,                   /* OP_EQ  */
    OP_NEQ = 267,                  /* OP_NEQ  */
    OP_GT = 268,                   /* OP_GT  */
    OP_LT = 269,                   /* OP_LT  */
    OP_GTE = 270,                  /* OP_GTE  */
    OP_LTE = 271,                  /* OP_LTE  */
    OP_ADD = 272,                  /* OP_ADD  */
    OP_SUB = 273,                  /* OP_SUB  */
    OP_MUL = 274,                  /* OP_MUL  */
    OP_DIV = 275,                  /* OP_DIV  */
    OP_MOD = 276,                  /* OP_MOD  */
    OP_NOT = 277,                  /* OP_NOT  */
    UMINUS = 278,                  /* UMINUS  */
    THROW_KW = 279,                /* THROW_KW  */
    NULL_KW = 280,                 /* NULL_KW  */
    OP_INC = 281,                  /* OP_INC  */
    OP_DEC = 282,                  /* OP_DEC  */
    LEFT_PARENT = 283,             /* LEFT_PARENT  */
    RIGHT_PARENT = 284,            /* RIGHT_PARENT  */
    LEFT_BRACKET = 285,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 286,           /* RIGHT_BRACKET  */
    LEFT_SQUARE = 287,             /* LEFT_SQUARE  */
    RIGHT_SQUARE = 288,            /* RIGHT_SQUARE  */
    COMMA = 289,                   /* COMMA  */
    DOT = 290,                     /* DOT  */
    D_COLON = 291,                 /* D_COLON  */
    COLON = 292,                   /* COLON  */
    FOR_KW = 293,                  /* FOR_KW  */
    WHILE_KW = 294,                /* WHILE_KW  */
    DO_KW = 295,                   /* DO_KW  */
    BREAK_KW = 296,                /* BREAK_KW  */
    RETURN_KW = 297,               /* RETURN_KW  */
    TRUE_KW = 298,                 /* TRUE_KW  */
    FALSE_KW = 299,                /* FALSE_KW  */
    FUNCTION_KW = 300,             /* FUNCTION_KW  */
    TRY_KW = 301,                  /* TRY_KW  */
    CATCH_KW = 302,                /* CATCH_KW  */
    FINALLY_KW = 303,              /* FINALLY_KW  */
    CHAR_KW = 304,                 /* CHAR_KW  */
    INT_KW = 305,                  /* INT_KW  */
    FLOAT_KW = 306,                /* FLOAT_KW  */
    BOOL_KW = 307,                 /* BOOL_KW  */
    STRING_KW = 308,               /* STRING_KW  */
    VOID_KW = 309,                 /* VOID_KW  */
    IF_KW = 310,                   /* IF_KW  */
    ELSE_KW = 311,                 /* ELSE_KW  */
    SWITCH_KW = 312,               /* SWITCH_KW  */
    CASE_KW = 313,                 /* CASE_KW  */
    DEFAULT_KW = 314,              /* DEFAULT_KW  */
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
