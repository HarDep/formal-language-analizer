/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintax_analizer.y"

#include <stdbool.h>
#define YYHASERRORS bool
#define YYTXT char*
#define YYCURR_VAR char*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern YYTXT yytext;
extern bool hasErrors;
extern int yylex(void);
extern FILE *yyin;
int lineNumber = 1;
bool hasDefaultCase = false;
int scopeLevel = 0;
int functType = -1;
bool hasReturn = false;
void yyerror();
typedef struct {
    char *name;
    bool isFunc;
    int type;
    int scopeLevel;
} SYM;
SYM syms[100];
int symCount = 0;
int checkNumsOperation(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a <= 1 || a >= 4|| b <= 1 || b >= 4) {
        printf("Incompatible type expression at line %d: invalid operation expression, the values must be int or float\n", lineNumber);
        hasErrors = true;
        return 0;
    }
    return a == 3 || b == 3 ? 3 : 2;
}
int checkComparison(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a <= 1 || a >= 4|| b <= 1 || b >= 4) {
        printf("Incompatible type expression at line %d: invalid comparison expression, the values must be int or float\n", lineNumber);
        hasErrors = true;
    }
    return 4;
}
int checkValuesComparison(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == b) {
        return 4;
    }
    if (a == 5 || b == 5) {
        return 4;
    }
    if ((a == 2 && b == 3) || (a == 3 && b == 2)) {
        return 4;
    }
    printf("Incompatible type expression at line %d: invalid comparison expression, incompatible type comparation\n", lineNumber);
    hasErrors = true;
    return 4;
}
int checkAsignation(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a != b && (a != 3 || a != 2)) {
        printf("Incompatible type error at line %d: unsoported assignment expression, both values must be the same type, and the type must be int or float\n",
            lineNumber);
        hasErrors = true;
        return 0;
    }
    return a;
}
int singleAsignation(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 5 && b != 5 && b != 1) {
        printf("Incompatible type error at line %d: unsoported type assignment expression\n",
            lineNumber);
        hasErrors = true;
    } else if (a != b) {
        printf("Incompatible type error at line %d: unsoported type assignment expression\n",
            lineNumber);
        hasErrors = true;
        return 0;
    }
    return b;
}
int checkSumAsignation(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 4 || a == 1) {
        printf("Incompatible type error at line %d: unsoported assignment expression with data type %s\n", 
            lineNumber, a == 4 ? "bool" : "char");
        hasErrors = true;
        return 0;
    }
    b = a == 5 ? 5 : b;
    if(b == 5 && a != 5) {
        printf("Incompatible type error at line %d: unsoported assignment expression with data type string\n", 
            lineNumber);
        hasErrors = true;
        return 0;
    }
    if(a == 3 && (b != 2 || b != 3)) {
        printf("Incompatible type error at line %d: unsoported assignment expression with data type float\n", 
            lineNumber);
        hasErrors = true;
        return 0;
    }
    if (a != b) {
        printf("Incompatible type error at line %d: unsoported assignment expression, both values must be the same type\n", 
            lineNumber);
        hasErrors = true;
        return 0;
    }
    return a;
}
int checkLogicOperation(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a != 4 || b != 4) {
        printf("Incompatible type expression at line %d: invalid logic operation expression, the values must be bool\n", lineNumber);
        hasErrors = true;
    }
    return 4;
}
int getSymbType(char* name, bool isFunc) {
    int tempType = 0;
    for (int i = 0; i < symCount; i++) {
        if (strcmp(name, syms[i].name) == 0 && syms[i].isFunc == isFunc) {
            if (syms[i].scopeLevel == 0 && !isFunc) {
                tempType = syms[i].type;
            } else {
                return syms[i].type;
            }
        }
    }
    if (tempType != 0) {
        return tempType;
    }
    printf("Access error at line %d: %s %s is not defined\n", lineNumber, isFunc ? "function" : "variable", name);
    hasErrors = true;
    return 0;
}
int getGlobalSymbType(char* name) {
    for (int i = 0; i < symCount; i++) {
        if (strcmp(name, syms[i].name) == 0 && syms[i].scopeLevel == 0 && !syms[i].isFunc) {
            return syms[i].type;
        }
    }
    printf("Access error at line %d: global variable %s is not defined\n", lineNumber, name);
    hasErrors = true;
    return 0;
}
int checkIncrementDecrement(int type) {
    if (type == 0) {
        return 0;
    }
    if (type != 2 && type != 3) {
        printf("Incompatible type error at line %d: unsoported operation, the type must be int or float\n", lineNumber);
        hasErrors = true;
    }
    return type;
}
bool existSymb(char* name, bool isFunc) {
    for (int i = 0; i < symCount; i++) {
        if (strcmp(name, syms[i].name) == 0 && (isFunc || scopeLevel == 0 || syms[i].scopeLevel != 0)) {
            return true;
        }
    }
    return false;
}
void addSymb(char* name, int type, bool isFunc) {
    if (!existSymb(name, isFunc)) {
        syms[symCount] = (SYM) {name, isFunc, type, scopeLevel};
        symCount++;
        return;
    }
    printf("Definition error at line %d: %s %s is already defined\n", lineNumber, isFunc ? "function" : "variable", name);
    hasErrors = true;
}
void addFunctionParam(char* name, int type) {
    syms[symCount] = (SYM) {name, false, type, scopeLevel + 1};
    symCount++;
}
void addForNumber(char* name) {
    if (!existSymb(name, false)) {
        syms[symCount] = (SYM) {name, false, 2, scopeLevel + 1};
        symCount++;
        return;
    }
    printf("Definition error at line %d: variable define inside for %s is already defined\n", lineNumber, name);
    hasErrors = true;
}
void deleteSymbs() {
    int newCount = -1;
    for (int i = 0; i < symCount; i++) {
        if (syms[i].scopeLevel == scopeLevel && !syms[i].isFunc && newCount == -1) {
            newCount = i;
        }
        if (syms[i].isFunc && i > newCount && newCount != -1) {
            syms[newCount] = syms[i];
            newCount++;
        }
    }
    symCount = newCount != -1 ? newCount : symCount;
}
void initBlock() {
    scopeLevel++;
}
void endBlock() {
    deleteSymbs();
    scopeLevel--;
}

#line 295 "sintax_analizer.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintax_analizer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OP_ASSIGN = 3,                  /* OP_ASSIGN  */
  YYSYMBOL_OP_ADD_ASSIGN = 4,              /* OP_ADD_ASSIGN  */
  YYSYMBOL_OP_SUB_ASSIGN = 5,              /* OP_SUB_ASSIGN  */
  YYSYMBOL_OP_MUL_ASSIGN = 6,              /* OP_MUL_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 7,              /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 8,              /* OP_MOD_ASSIGN  */
  YYSYMBOL_OP_AND = 9,                     /* OP_AND  */
  YYSYMBOL_OP_OR = 10,                     /* OP_OR  */
  YYSYMBOL_OP_EQ = 11,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 12,                    /* OP_NEQ  */
  YYSYMBOL_OP_GT = 13,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 14,                     /* OP_LT  */
  YYSYMBOL_OP_GTE = 15,                    /* OP_GTE  */
  YYSYMBOL_OP_LTE = 16,                    /* OP_LTE  */
  YYSYMBOL_OP_ADD = 17,                    /* OP_ADD  */
  YYSYMBOL_OP_SUB = 18,                    /* OP_SUB  */
  YYSYMBOL_OP_MUL = 19,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 20,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 21,                    /* OP_MOD  */
  YYSYMBOL_OP_NOT = 22,                    /* OP_NOT  */
  YYSYMBOL_UMINUS = 23,                    /* UMINUS  */
  YYSYMBOL_THROW_KW = 24,                  /* THROW_KW  */
  YYSYMBOL_NULL_KW = 25,                   /* NULL_KW  */
  YYSYMBOL_OP_INC = 26,                    /* OP_INC  */
  YYSYMBOL_OP_DEC = 27,                    /* OP_DEC  */
  YYSYMBOL_LEFT_PARENT = 28,               /* LEFT_PARENT  */
  YYSYMBOL_RIGHT_PARENT = 29,              /* RIGHT_PARENT  */
  YYSYMBOL_LEFT_BRACKET = 30,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 31,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_SQUARE = 32,               /* LEFT_SQUARE  */
  YYSYMBOL_RIGHT_SQUARE = 33,              /* RIGHT_SQUARE  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_D_COLON = 36,                   /* D_COLON  */
  YYSYMBOL_COLON = 37,                     /* COLON  */
  YYSYMBOL_FOR_KW = 38,                    /* FOR_KW  */
  YYSYMBOL_WHILE_KW = 39,                  /* WHILE_KW  */
  YYSYMBOL_DO_KW = 40,                     /* DO_KW  */
  YYSYMBOL_BREAK_KW = 41,                  /* BREAK_KW  */
  YYSYMBOL_RETURN_KW = 42,                 /* RETURN_KW  */
  YYSYMBOL_TRUE_KW = 43,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 44,                  /* FALSE_KW  */
  YYSYMBOL_FUNCTION_KW = 45,               /* FUNCTION_KW  */
  YYSYMBOL_TRY_KW = 46,                    /* TRY_KW  */
  YYSYMBOL_CATCH_KW = 47,                  /* CATCH_KW  */
  YYSYMBOL_FINALLY_KW = 48,                /* FINALLY_KW  */
  YYSYMBOL_CHAR_KW = 49,                   /* CHAR_KW  */
  YYSYMBOL_INT_KW = 50,                    /* INT_KW  */
  YYSYMBOL_FLOAT_KW = 51,                  /* FLOAT_KW  */
  YYSYMBOL_BOOL_KW = 52,                   /* BOOL_KW  */
  YYSYMBOL_STRING_KW = 53,                 /* STRING_KW  */
  YYSYMBOL_VOID_KW = 54,                   /* VOID_KW  */
  YYSYMBOL_IF_KW = 55,                     /* IF_KW  */
  YYSYMBOL_ELSE_KW = 56,                   /* ELSE_KW  */
  YYSYMBOL_SWITCH_KW = 57,                 /* SWITCH_KW  */
  YYSYMBOL_CASE_KW = 58,                   /* CASE_KW  */
  YYSYMBOL_DEFAULT_KW = 59,                /* DEFAULT_KW  */
  YYSYMBOL_CHAR = 60,                      /* CHAR  */
  YYSYMBOL_STRING = 61,                    /* STRING  */
  YYSYMBOL_NUM = 62,                       /* NUM  */
  YYSYMBOL_NUM_DEC = 63,                   /* NUM_DEC  */
  YYSYMBOL_IDENTIFIER = 64,                /* IDENTIFIER  */
  YYSYMBOL_EOL = 65,                       /* EOL  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_in = 67,                        /* in  */
  YYSYMBOL_line = 68,                      /* line  */
  YYSYMBOL_n_line = 69,                    /* n_line  */
  YYSYMBOL_exp = 70,                       /* exp  */
  YYSYMBOL_exp_wth_bl = 71,                /* exp_wth_bl  */
  YYSYMBOL_func = 72,                      /* func  */
  YYSYMBOL_std_block_d = 73,               /* std_block_d  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_func_dec = 75,                  /* func_dec  */
  YYSYMBOL_block = 76,                     /* block  */
  YYSYMBOL_block_line = 77,                /* block_line  */
  YYSYMBOL_block_exp = 78,                 /* block_exp  */
  YYSYMBOL_rtrn = 79,                      /* rtrn  */
  YYSYMBOL_throw_dec = 80,                 /* throw_dec  */
  YYSYMBOL_loop = 81,                      /* loop  */
  YYSYMBOL_for_decl = 82,                  /* for_decl  */
  YYSYMBOL_for_vrs_dec = 83,               /* for_vrs_dec  */
  YYSYMBOL_for_var = 84,                   /* for_var  */
  YYSYMBOL_for_cond = 85,                  /* for_cond  */
  YYSYMBOL_for_sec = 86,                   /* for_sec  */
  YYSYMBOL_for_iter = 87,                  /* for_iter  */
  YYSYMBOL_while_exp = 88,                 /* while_exp  */
  YYSYMBOL_conditional = 89,               /* conditional  */
  YYSYMBOL_if_els_stmt = 90,               /* if_els_stmt  */
  YYSYMBOL_if_stmt = 91,                   /* if_stmt  */
  YYSYMBOL_92_2 = 92,                      /* $@2  */
  YYSYMBOL_else_stmt = 93,                 /* else_stmt  */
  YYSYMBOL_els_if_stmt = 94,               /* els_if_stmt  */
  YYSYMBOL_switch_stmt = 95,               /* switch_stmt  */
  YYSYMBOL_96_3 = 96,                      /* $@3  */
  YYSYMBOL_switch_block = 97,              /* switch_block  */
  YYSYMBOL_switch_line = 98,               /* switch_line  */
  YYSYMBOL_99_4 = 99,                      /* $@4  */
  YYSYMBOL_100_5 = 100,                    /* $@5  */
  YYSYMBOL_exception = 101,                /* exception  */
  YYSYMBOL_try_catch = 102,                /* try_catch  */
  YYSYMBOL_func_type = 103,                /* func_type  */
  YYSYMBOL_func_params = 104,              /* func_params  */
  YYSYMBOL_params_sec = 105,               /* params_sec  */
  YYSYMBOL_param = 106,                    /* param  */
  YYSYMBOL_instance = 107,                 /* instance  */
  YYSYMBOL_inst_id = 108,                  /* inst_id  */
  YYSYMBOL_type = 109,                     /* type  */
  YYSYMBOL_value_data = 110,               /* value_data  */
  YYSYMBOL_var_value = 111,                /* var_value  */
  YYSYMBOL_exp_op = 112,                   /* exp_op  */
  YYSYMBOL_inc_dec = 113,                  /* inc_dec  */
  YYSYMBOL_ops_inc_dec = 114,              /* ops_inc_dec  */
  YYSYMBOL_func_call = 115,                /* func_call  */
  YYSYMBOL_func_args = 116,                /* func_args  */
  YYSYMBOL_func_arg = 117,                 /* func_arg  */
  YYSYMBOL_asingn = 118,                   /* asingn  */
  YYSYMBOL_ops_asingn = 119                /* ops_asingn  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   252,   252,   252,   254,   254,   254,   256,   258,   258,
     258,   258,   260,   260,   260,   260,   262,   269,   269,   271,
     273,   273,   275,   275,   277,   277,   277,   277,   277,   277,
     277,   277,   278,   293,   295,   295,   297,   297,   299,   300,
     301,   303,   305,   305,   307,   315,   323,   323,   325,   325,
     327,   334,   334,   336,   336,   336,   338,   338,   345,   347,
     347,   347,   349,   349,   354,   356,   356,   368,   368,   369,
     369,   379,   379,   381,   383,   383,   385,   385,   387,   387,
     387,   389,   389,   397,   397,   407,   409,   410,   411,   412,
     413,   415,   416,   417,   418,   419,   420,   421,   423,   424,
     426,   447,   455,   463,   476,   489,   497,   505,   513,   521,
     529,   537,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   562,   564,   564,   566,   566,   568,
     569,   571,   571,   571,   573,   573,   575,   576,   577,   579,
     579,   579,   579
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OP_ASSIGN",
  "OP_ADD_ASSIGN", "OP_SUB_ASSIGN", "OP_MUL_ASSIGN", "OP_DIV_ASSIGN",
  "OP_MOD_ASSIGN", "OP_AND", "OP_OR", "OP_EQ", "OP_NEQ", "OP_GT", "OP_LT",
  "OP_GTE", "OP_LTE", "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD",
  "OP_NOT", "UMINUS", "THROW_KW", "NULL_KW", "OP_INC", "OP_DEC",
  "LEFT_PARENT", "RIGHT_PARENT", "LEFT_BRACKET", "RIGHT_BRACKET",
  "LEFT_SQUARE", "RIGHT_SQUARE", "COMMA", "DOT", "D_COLON", "COLON",
  "FOR_KW", "WHILE_KW", "DO_KW", "BREAK_KW", "RETURN_KW", "TRUE_KW",
  "FALSE_KW", "FUNCTION_KW", "TRY_KW", "CATCH_KW", "FINALLY_KW", "CHAR_KW",
  "INT_KW", "FLOAT_KW", "BOOL_KW", "STRING_KW", "VOID_KW", "IF_KW",
  "ELSE_KW", "SWITCH_KW", "CASE_KW", "DEFAULT_KW", "CHAR", "STRING", "NUM",
  "NUM_DEC", "IDENTIFIER", "EOL", "$accept", "in", "line", "n_line", "exp",
  "exp_wth_bl", "func", "std_block_d", "$@1", "func_dec", "block",
  "block_line", "block_exp", "rtrn", "throw_dec", "loop", "for_decl",
  "for_vrs_dec", "for_var", "for_cond", "for_sec", "for_iter", "while_exp",
  "conditional", "if_els_stmt", "if_stmt", "$@2", "else_stmt",
  "els_if_stmt", "switch_stmt", "$@3", "switch_block", "switch_line",
  "$@4", "$@5", "exception", "try_catch", "func_type", "func_params",
  "params_sec", "param", "instance", "inst_id", "type", "value_data",
  "var_value", "exp_op", "inc_dec", "ops_inc_dec", "func_call",
  "func_args", "func_arg", "asingn", "ops_asingn", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-183)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -183,   228,  -183,  -183,  -183,   -48,    -2,     4,    -7,   -27,
      20,  -183,  -183,  -183,  -183,  -183,    12,    31,    42,  -183,
    -183,  -183,    29,  -183,  -183,    -7,  -183,    -7,  -183,  -183,
      39,  -183,  -183,    48,  -183,    94,    36,    58,  -183,   -21,
    -183,  -183,  -183,    41,   280,  -183,    64,    73,  -183,   280,
     280,   268,  -183,  -183,  -183,   -16,  -183,    51,    78,   280,
    -183,   280,   280,  -183,  -183,  -183,  -183,  -183,   280,  -183,
    -183,   131,   106,   101,   107,   280,   280,   280,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,   125,   517,  -183,  -183,  -183,
    -183,   -19,   103,   332,   580,   538,  -183,    -4,   580,   119,
     115,  -183,  -183,   -16,  -183,  -183,   580,   580,   580,   580,
     280,    -7,   280,    41,  -183,  -183,   559,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,  -183,   364,  -183,   113,
     128,   121,    37,  -183,    95,   116,  -183,   280,  -183,  -183,
      29,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
     133,   130,   280,  -183,   160,  -183,   396,   580,  -183,   127,
     580,  -183,  -183,   580,   580,   580,   580,   580,   580,   591,
     591,   220,   220,   126,   126,   126,   126,    10,    10,  -183,
    -183,  -183,  -183,   123,  -183,   -30,  -183,  -183,   140,   141,
     580,  -183,    -7,    29,   580,   291,  -183,  -183,    -9,   167,
     117,  -183,   -17,   120,  -183,   -12,  -183,  -183,   143,  -183,
    -183,   280,  -183,  -183,   150,   151,  -183,   280,   146,   -10,
    -183,    -9,   580,  -183,   155,    62,  -183,   158,  -183,  -183,
    -183,  -183,  -183,  -183,   428,  -183,   460,  -183,   460
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   127,   128,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,    98,     7,
       3,     4,     0,     6,    15,     0,    12,     0,    13,    51,
      53,    52,    14,    71,     8,    83,     0,     0,     9,     0,
      10,    11,    99,     0,     0,    17,     0,     0,    20,     0,
       0,     0,     5,    16,    39,     0,    54,    55,     0,     0,
      85,     0,     0,   139,   140,   141,   142,   125,     0,    98,
     126,     0,     0,     0,    42,     0,     0,     0,    94,    95,
      91,    96,    92,    93,   122,    97,     0,   124,   123,    20,
      40,     0,     0,     0,    56,     0,   129,    98,   135,     0,
     131,    58,    59,     0,    61,    20,    84,   136,   137,   138,
       0,     0,     0,     0,   105,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    77,     0,
       0,    78,     0,    19,     0,     0,    25,    35,    22,    21,
       0,    32,    33,    29,    30,    31,    24,    26,    27,    28,
       0,     0,     0,   130,     0,    60,     0,    44,    38,     0,
      45,    43,   121,   115,   116,   117,   118,   119,   120,   112,
     113,   110,   111,   106,   107,   108,   109,   100,   101,   102,
     103,   104,    18,     0,    76,     0,    75,    74,     0,     0,
      34,    23,     0,     0,   134,     0,   132,    72,     0,    81,
       0,    79,     0,     0,    57,     0,   133,    41,    46,    48,
      49,     0,    80,    37,     0,     0,    64,     0,     0,    62,
      65,     0,    82,    36,     0,     0,    69,     0,    66,    47,
      20,    67,    20,    63,     0,    20,    70,    73,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,     3,  -183,  -183,  -183,    -5,  -183,  -183,
     -84,  -183,  -183,  -183,  -183,   189,  -183,    79,  -183,  -183,
     -40,  -183,   147,   193,  -183,   -47,  -183,   138,  -183,  -183,
    -183,  -183,   -29,  -183,  -183,   198,  -183,  -183,  -183,  -182,
    -183,   200,  -183,  -135,  -183,    -1,    -8,     0,   -28,     5,
    -153,  -183,     1,  -183
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,   148,    22,    23,    24,   101,    89,    25,
      93,   149,   150,   151,   152,   153,    72,    73,    74,   169,
     217,   218,    27,   154,    29,    30,   160,    56,    57,    31,
     237,   229,   230,   245,   242,   155,    33,   143,    92,   140,
     141,   156,    35,    36,    84,    85,    98,    87,    39,    88,
      99,   100,   159,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    38,    41,    46,    21,   137,    40,   197,   102,    67,
     138,   206,   223,   211,    45,     5,    42,     3,     4,   226,
      53,   166,    54,    45,    51,    52,    43,     5,   222,   133,
     134,   135,    44,   162,   139,    19,    86,    47,    70,    16,
      49,    94,    95,    69,   224,   139,   227,   228,   227,   228,
      48,   106,   216,   107,   108,    69,   165,    67,   209,    50,
     109,    61,    62,    63,    64,    65,    66,   114,   115,   116,
      51,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     3,     4,    11,    12,    13,    14,
      15,   196,    37,   157,    19,    55,    58,    59,   158,   241,
      60,    91,   167,     7,   170,    71,   168,   103,   105,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   117,   118,
     119,   120,   121,   122,   110,   111,    37,   157,   112,   200,
     142,   113,   158,   131,   132,   133,   134,   135,   163,   164,
     193,     3,     4,   201,   204,   195,   244,   194,   246,   198,
     203,   248,   202,   199,   208,    37,   157,   205,   212,   213,
     221,   158,    11,    12,    13,    14,    15,   231,    75,   233,
     234,   139,    76,   236,   225,   240,     3,     4,    77,   243,
      26,   239,   171,    90,    28,   104,     5,   214,   210,    32,
     238,    34,     0,    78,    79,     0,   215,    37,   219,   220,
       0,     0,     0,   232,     0,     0,     0,     0,     0,   235,
      80,    81,    82,    83,    97,    19,     0,     0,     2,     0,
      37,   219,   220,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,    37,   157,    37,   157,    37,   157,   158,
       0,   158,     0,   158,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     6,     7,     8,     0,
       0,     0,     0,     9,    10,     0,     0,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    75,     0,     0,     0,
      76,     0,    18,    19,     3,     4,    77,    96,    75,     0,
       0,     0,    76,     0,     5,     0,     3,     4,    77,    75,
       0,    78,    79,    76,     0,     0,     5,     3,     4,    77,
       0,     0,     0,    78,    79,     0,     0,     5,    80,    81,
      82,    83,    97,     0,    78,    79,     0,     0,     0,     0,
      80,    81,    82,    83,    18,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    97,   144,     0,     3,     4,
       0,     0,     0,   145,     0,     0,     0,     0,     5,     0,
       6,     7,     8,   146,   147,     0,     0,     0,    10,     0,
       0,    11,    12,    13,    14,    15,     0,    16,   144,    17,
       3,     4,     0,     0,     0,   192,    18,    19,     0,     0,
       5,     0,     6,     7,     8,   146,   147,     0,     0,     0,
      10,     0,     0,    11,    12,    13,    14,    15,     0,    16,
     144,    17,     3,     4,     0,     0,     0,   207,    18,    19,
       0,     0,     5,     0,     6,     7,     8,   146,   147,     0,
       0,     0,    10,     0,     0,    11,    12,    13,    14,    15,
       0,    16,   144,    17,     3,     4,     0,     0,     0,   247,
      18,    19,     0,     0,     5,     0,     6,     7,     8,   146,
     147,     0,     0,     0,    10,     0,     0,    11,    12,    13,
      14,    15,     0,    16,   144,    17,     3,     4,     0,     0,
       0,     0,    18,    19,     0,     0,     5,     0,     6,     7,
       8,   146,   147,     0,     0,     0,    10,     0,     0,    11,
      12,    13,    14,    15,     0,    16,     0,    17,     0,     0,
       0,     0,     0,     0,    18,    19,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,   136,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,   161,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,   172,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     8,     1,    89,     1,   142,    55,    37,
      29,   164,    29,   195,    30,    36,    64,    26,    27,    31,
      25,   105,    27,    30,    28,    22,    28,    36,   210,    19,
      20,    21,    28,    37,    64,    65,    44,    64,    39,    55,
      28,    49,    50,    64,    61,    64,    58,    59,    58,    59,
      30,    59,   205,    61,    62,    64,   103,    85,   193,    28,
      68,     3,     4,     5,     6,     7,     8,    75,    76,    77,
      28,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    26,    27,    49,    50,    51,    52,
      53,    54,    93,    93,    65,    56,    48,     3,    93,    37,
      64,    28,   110,    39,   112,    64,   111,    56,    30,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     3,     4,
       5,     6,     7,     8,     3,    29,   137,   137,    37,   147,
      37,    34,   137,    17,    18,    19,    20,    21,    29,    34,
      37,    26,    27,   150,   162,    34,   240,    29,   242,    64,
      30,   245,    29,    47,    37,   166,   166,   164,    28,    28,
       3,   166,    49,    50,    51,    52,    53,    34,    18,    29,
      29,    64,    22,    37,    64,    30,    26,    27,    28,    31,
       1,   231,   113,    46,     1,    57,    36,   202,   195,     1,
     229,     1,    -1,    43,    44,    -1,   203,   208,   208,   208,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,   227,
      60,    61,    62,    63,    64,    65,    -1,    -1,     0,    -1,
     231,   231,   231,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,   244,   244,   246,   246,   248,   248,   244,
      -1,   246,    -1,   248,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    -1,    57,    18,    -1,    -1,    -1,
      22,    -1,    64,    65,    26,    27,    28,    29,    18,    -1,
      -1,    -1,    22,    -1,    36,    -1,    26,    27,    28,    18,
      -1,    43,    44,    22,    -1,    -1,    36,    26,    27,    28,
      -1,    -1,    -1,    43,    44,    -1,    -1,    36,    60,    61,
      62,    63,    64,    -1,    43,    44,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    24,    57,
      26,    27,    -1,    -1,    -1,    31,    64,    65,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    -1,    55,
      24,    57,    26,    27,    -1,    -1,    -1,    31,    64,    65,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    24,    57,    26,    27,    -1,    -1,    -1,    31,
      64,    65,    -1,    -1,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    24,    57,    26,    27,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,     0,    26,    27,    36,    38,    39,    40,    45,
      46,    49,    50,    51,    52,    53,    55,    57,    64,    65,
      68,    69,    70,    71,    72,    75,    81,    88,    89,    90,
      91,    95,   101,   102,   107,   108,   109,   111,   113,   114,
     115,   118,    64,    28,    28,    30,    73,    64,    30,    28,
      28,    28,    69,    73,    73,    56,    93,    94,    48,     3,
      64,     3,     4,     5,     6,     7,     8,   114,   119,    64,
     111,    64,    82,    83,    84,    18,    22,    28,    43,    44,
      60,    61,    62,    63,   110,   111,   112,   113,   115,    74,
      88,    28,   104,    76,   112,   112,    29,    64,   112,   116,
     117,    73,    91,    56,    93,    30,   112,   112,   112,   112,
       3,    29,    37,    34,   112,   112,   112,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    29,    76,    29,    64,
     105,   106,    37,   103,    24,    31,    41,    42,    69,    77,
      78,    79,    80,    81,    89,   101,   107,   113,   115,   118,
      92,    29,    37,    29,    34,    91,    76,   112,    73,    85,
     112,    83,    29,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,    31,    37,    29,    34,    54,   109,    64,    47,
     112,    69,    29,    30,   112,    69,   116,    31,    37,   109,
      69,   105,    28,    28,    73,    69,   116,    86,    87,   113,
     118,     3,   105,    29,    61,    64,    31,    58,    59,    97,
      98,    34,   112,    29,    29,   112,    37,    96,    98,    86,
      30,    37,   100,    31,    76,    99,    76,    31,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    74,    73,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    82,    83,    83,    84,    85,    86,    86,    87,    87,
      88,    89,    89,    90,    90,    90,    92,    91,    93,    94,
      94,    94,    96,    95,    95,    97,    97,    99,    98,   100,
      98,   101,   101,   102,   103,   103,   104,   104,   105,   105,
     105,   106,   106,   107,   107,   108,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   117,   117,   118,   118,   118,   119,
     119,   119,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     4,
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     5,     4,     5,     2,
       3,     5,     1,     3,     3,     1,     1,     3,     1,     1,
       4,     1,     1,     1,     2,     2,     0,     6,     2,     2,
       3,     2,     0,     9,     7,     1,     2,     0,     5,     0,
       4,     1,     5,    11,     2,     2,     3,     2,     1,     3,
       4,     3,     5,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     2,     1,     1,     3,
       4,     1,     3,     4,     3,     1,     3,     3,     3,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* n_line: EOL  */
#line 256 "sintax_analizer.y"
                    { lineNumber++; }
#line 1659 "sintax_analizer.tab.c"
    break;

  case 16: /* func: func_dec std_block_d  */
#line 262 "sintax_analizer.y"
                                     {
    if (functType != -1 && !hasReturn) {
        printf("Missing return error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1670 "sintax_analizer.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 269 "sintax_analizer.y"
                             { initBlock(); }
#line 1676 "sintax_analizer.tab.c"
    break;

  case 18: /* std_block_d: LEFT_BRACKET $@1 block RIGHT_BRACKET  */
#line 269 "sintax_analizer.y"
                                                                  { endBlock(); }
#line 1682 "sintax_analizer.tab.c"
    break;

  case 19: /* func_dec: FUNCTION_KW IDENTIFIER func_params func_type  */
#line 271 "sintax_analizer.y"
                                                             { addSymb((yyvsp[-2].sval), (yyvsp[0].ival), true); }
#line 1688 "sintax_analizer.tab.c"
    break;

  case 32: /* block_exp: rtrn  */
#line 278 "sintax_analizer.y"
                   {
    if (scopeLevel == 1) {
        hasReturn = true;
    }
    if (functType != -1 && (yyvsp[0].ival) == -1 && (yyvsp[0].ival) != 0) {
        printf("Incompatible type error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    } else if (functType == -1 && (yyvsp[0].ival) != -1) {
        printf("Incompatible type error at line %d: the function is void and has a return value\n", lineNumber);
        hasErrors = true;
    } else if (functType != -1 && functType != (yyvsp[0].ival) && (yyvsp[0].ival) != 0) {
        printf("Incompatible type error at line %d: return data value of function is not compatible with function return type\n",
            lineNumber);
        hasErrors = true;
    }
}
#line 1709 "sintax_analizer.tab.c"
    break;

  case 34: /* rtrn: RETURN_KW exp_op  */
#line 295 "sintax_analizer.y"
                                 { (yyval.ival) = (yyvsp[0].sdata).type; }
#line 1715 "sintax_analizer.tab.c"
    break;

  case 35: /* rtrn: RETURN_KW  */
#line 295 "sintax_analizer.y"
                                                               { (yyval.ival) = -1; }
#line 1721 "sintax_analizer.tab.c"
    break;

  case 44: /* for_var: IDENTIFIER OP_ASSIGN exp_op  */
#line 307 "sintax_analizer.y"
                                            {
    if ((yyvsp[0].sdata).type != 2 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: the variable used in for iteration is not a int value\n", 
            lineNumber);
    }
    addForNumber((yyvsp[-2].sval));
}
#line 1733 "sintax_analizer.tab.c"
    break;

  case 45: /* for_cond: exp_op  */
#line 315 "sintax_analizer.y"
                       {
    if((yyvsp[0].sdata).type != 4 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition used in for iteration is not a bool value\n", 
            lineNumber);
        hasErrors = true;
    }
}
#line 1745 "sintax_analizer.tab.c"
    break;

  case 50: /* while_exp: WHILE_KW LEFT_PARENT exp_op RIGHT_PARENT  */
#line 327 "sintax_analizer.y"
                                                         {
    if ((yyvsp[-1].sdata).type != 4 && (yyvsp[-1].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1756 "sintax_analizer.tab.c"
    break;

  case 56: /* $@2: %empty  */
#line 338 "sintax_analizer.y"
                                         {
    if ((yyvsp[0].sdata).type != 4 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1767 "sintax_analizer.tab.c"
    break;

  case 62: /* $@3: %empty  */
#line 349 "sintax_analizer.y"
                                                                                           {
    if ((yyvsp[-4].sdata).type != (yyvsp[0].ival) && (yyvsp[0].ival) != 0 && (yyvsp[-4].sdata).type != 0) {
        printf("Incompatible type error at line %d: the cases type are not compatible with the switch value type\n", lineNumber);
        hasErrors = true;
    }
}
#line 1778 "sintax_analizer.tab.c"
    break;

  case 63: /* switch_stmt: SWITCH_KW LEFT_PARENT exp_op RIGHT_PARENT LEFT_BRACKET n_line switch_block $@3 RIGHT_BRACKET  */
#line 354 "sintax_analizer.y"
                { hasDefaultCase = false; }
#line 1784 "sintax_analizer.tab.c"
    break;

  case 65: /* switch_block: switch_line  */
#line 356 "sintax_analizer.y"
                            { (yyval.ival) = (yyvsp[0].ival) == -1 ? 0 : (yyvsp[0].ival); }
#line 1790 "sintax_analizer.tab.c"
    break;

  case 66: /* switch_block: switch_block switch_line  */
#line 356 "sintax_analizer.y"
                                                                                   {
    (yyvsp[-1].ival) = (yyvsp[-1].ival) == -1 ? (yyvsp[0].ival) : (yyvsp[-1].ival);
    (yyvsp[0].ival) = (yyvsp[0].ival) == -1 ? (yyvsp[-1].ival) : (yyvsp[0].ival);
    if ((yyvsp[-1].ival) != (yyvsp[0].ival)) {
        printf("Incompatible type error at line %d: the switch cases data types are not compatible\n", lineNumber);
        hasErrors = true;
        (yyval.ival) = 0;
    } else {
        (yyval.ival) = (yyvsp[0].ival);
    }
}
#line 1806 "sintax_analizer.tab.c"
    break;

  case 67: /* $@4: %empty  */
#line 368 "sintax_analizer.y"
                                     { initBlock(); }
#line 1812 "sintax_analizer.tab.c"
    break;

  case 68: /* switch_line: CASE_KW exp_op COLON $@4 block  */
#line 368 "sintax_analizer.y"
                                                            { endBlock(); (yyval.ival) = (yyvsp[-3].sdata).type; }
#line 1818 "sintax_analizer.tab.c"
    break;

  case 69: /* $@5: %empty  */
#line 369 "sintax_analizer.y"
                                 { initBlock(); }
#line 1824 "sintax_analizer.tab.c"
    break;

  case 70: /* switch_line: DEFAULT_KW COLON $@5 block  */
#line 369 "sintax_analizer.y"
                                                        {
    endBlock();
    if (hasDefaultCase) {
        printf("Definition error at line %d: the switch has more than one default case\n", lineNumber);
        hasErrors = true;
    }
    hasDefaultCase = true;
    (yyval.ival) = -1;
}
#line 1838 "sintax_analizer.tab.c"
    break;

  case 74: /* func_type: COLON type  */
#line 383 "sintax_analizer.y"
                           { functType = (yyvsp[0].ival); hasReturn = false; (yyval.ival) = (yyvsp[0].ival); }
#line 1844 "sintax_analizer.tab.c"
    break;

  case 75: /* func_type: COLON VOID_KW  */
#line 383 "sintax_analizer.y"
                                                                                           { functType = -1; (yyval.ival) = -1; }
#line 1850 "sintax_analizer.tab.c"
    break;

  case 81: /* param: IDENTIFIER COLON type  */
#line 389 "sintax_analizer.y"
                                      { addFunctionParam((yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 1856 "sintax_analizer.tab.c"
    break;

  case 82: /* param: IDENTIFIER COLON type OP_ASSIGN exp_op  */
#line 389 "sintax_analizer.y"
                                                                                                             {
    addFunctionParam((yyvsp[-4].sval), (yyvsp[-2].ival));
    if ((yyvsp[0].sdata).type != (yyvsp[-2].ival) && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: data value of parameter %s is not compatible with data type\n",lineNumber, (yyvsp[-4].sval));
        hasErrors = true;
    }
}
#line 1868 "sintax_analizer.tab.c"
    break;

  case 84: /* instance: inst_id OP_ASSIGN exp_op  */
#line 397 "sintax_analizer.y"
                                                   {
    if ((yyvsp[-2].ival) == 5 && (yyvsp[0].sdata).type != 5 && (yyvsp[0].sdata).type != 1 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber);
        hasErrors = true;
    } else if ((yyvsp[-2].ival) != (yyvsp[0].sdata).type && (yyvsp[-2].ival) != 5 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber);
        hasErrors = true;
    }
}
#line 1882 "sintax_analizer.tab.c"
    break;

  case 85: /* inst_id: type IDENTIFIER  */
#line 407 "sintax_analizer.y"
                                { addSymb((yyvsp[0].sval), (yyvsp[-1].ival), false); (yyval.ival) = (yyvsp[-1].ival); }
#line 1888 "sintax_analizer.tab.c"
    break;

  case 86: /* type: CHAR_KW  */
#line 409 "sintax_analizer.y"
                            { (yyval.ival) = 1; }
#line 1894 "sintax_analizer.tab.c"
    break;

  case 87: /* type: INT_KW  */
#line 410 "sintax_analizer.y"
                            { (yyval.ival) = 2; }
#line 1900 "sintax_analizer.tab.c"
    break;

  case 88: /* type: FLOAT_KW  */
#line 411 "sintax_analizer.y"
                            { (yyval.ival) = 3; }
#line 1906 "sintax_analizer.tab.c"
    break;

  case 89: /* type: BOOL_KW  */
#line 412 "sintax_analizer.y"
                            { (yyval.ival) = 4; }
#line 1912 "sintax_analizer.tab.c"
    break;

  case 90: /* type: STRING_KW  */
#line 413 "sintax_analizer.y"
                            { (yyval.ival) = 5; }
#line 1918 "sintax_analizer.tab.c"
    break;

  case 91: /* value_data: CHAR  */
#line 415 "sintax_analizer.y"
                            { (yyval.sdata).type = 1; (yyval.sdata).hasVal = 0; }
#line 1924 "sintax_analizer.tab.c"
    break;

  case 92: /* value_data: NUM  */
#line 416 "sintax_analizer.y"
                            { (yyval.sdata).type = 2; (yyval.sdata).hasVal = 1; (yyval.sdata).val = (yyvsp[0].dval); }
#line 1930 "sintax_analizer.tab.c"
    break;

  case 93: /* value_data: NUM_DEC  */
#line 417 "sintax_analizer.y"
                            { (yyval.sdata).type = 3; (yyval.sdata).hasVal = 1; (yyval.sdata).val = (yyvsp[0].dval); }
#line 1936 "sintax_analizer.tab.c"
    break;

  case 94: /* value_data: TRUE_KW  */
#line 418 "sintax_analizer.y"
                            { (yyval.sdata).type = 4; (yyval.sdata).hasVal = 0; }
#line 1942 "sintax_analizer.tab.c"
    break;

  case 95: /* value_data: FALSE_KW  */
#line 419 "sintax_analizer.y"
                            { (yyval.sdata).type = 4; (yyval.sdata).hasVal = 0; }
#line 1948 "sintax_analizer.tab.c"
    break;

  case 96: /* value_data: STRING  */
#line 420 "sintax_analizer.y"
                            { (yyval.sdata).type = 5; (yyval.sdata).hasVal = 0; }
#line 1954 "sintax_analizer.tab.c"
    break;

  case 97: /* value_data: var_value  */
#line 421 "sintax_analizer.y"
                            { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0; }
#line 1960 "sintax_analizer.tab.c"
    break;

  case 98: /* var_value: IDENTIFIER  */
#line 423 "sintax_analizer.y"
                            { (yyval.ival) = getSymbType((yyvsp[0].sval), false); }
#line 1966 "sintax_analizer.tab.c"
    break;

  case 99: /* var_value: D_COLON IDENTIFIER  */
#line 424 "sintax_analizer.y"
                                   { (yyval.ival) = getGlobalSymbType((yyvsp[0].sval)); }
#line 1972 "sintax_analizer.tab.c"
    break;

  case 100: /* exp_op: exp_op OP_ADD exp_op  */
#line 426 "sintax_analizer.y"
                                     {
    if ((yyvsp[-2].sdata).type == 4 && (yyvsp[0].sdata).type == 4) {
        printf("Incompatible type expression at line %d: invalid operation expression, cannot add bool values\n", lineNumber);
        hasErrors = true;
        (yyval.sdata).type = 0;
    } else {
        if ((yyvsp[-2].sdata).type != 0 && (yyvsp[0].sdata).type != 0) {
            (yyvsp[-2].sdata).type = (yyvsp[-2].sdata).type == 1 || (yyvsp[-2].sdata).type == 4 ? 5 : (yyvsp[-2].sdata).type;
            (yyvsp[0].sdata).type = (yyvsp[0].sdata).type == 1 || (yyvsp[0].sdata).type == 4 ? 5 : (yyvsp[0].sdata).type;
            (yyval.sdata).type = (yyvsp[-2].sdata).type == 5 || (yyvsp[0].sdata).type == 5 ? 5 : (yyvsp[-2].sdata).type == 3 || (yyvsp[0].sdata).type == 3 ? 3 : 2;
        }else{
            (yyval.sdata).type = 0;
        }
    }
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val + (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 1998 "sintax_analizer.tab.c"
    break;

  case 101: /* exp_op: exp_op OP_SUB exp_op  */
#line 447 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val - (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2011 "sintax_analizer.tab.c"
    break;

  case 102: /* exp_op: exp_op OP_MUL exp_op  */
#line 455 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val * (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2024 "sintax_analizer.tab.c"
    break;

  case 103: /* exp_op: exp_op OP_DIV exp_op  */
#line 463 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val != 0) {
            (yyval.sdata).hasVal = 1;
            (yyval.sdata).val = (yyvsp[-2].sdata).val / (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
    if((yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val == 0) {
        printf("Logical error at line %d: division by zero\n", lineNumber);
        hasErrors = true;
        (yyval.sdata).hasVal = 0;
    }
}
#line 2042 "sintax_analizer.tab.c"
    break;

  case 104: /* exp_op: exp_op OP_MOD exp_op  */
#line 476 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val != 0) {
            (yyval.sdata).hasVal = 1;
            (yyval.sdata).val = fmod((yyvsp[-2].sdata).val,(yyvsp[0].sdata).val);
    } else {
        (yyval.sdata).hasVal = 0;
    }
    if((yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val == 0) {
        printf("Logical error at line %d: division by zero on module operation\n", lineNumber);
        hasErrors = true;
        (yyval.sdata).hasVal = 0;
    }
}
#line 2060 "sintax_analizer.tab.c"
    break;

  case 105: /* exp_op: OP_SUB exp_op  */
#line 489 "sintax_analizer.y"
                                           { (yyval.sdata).type = checkNumsOperation((yyvsp[0].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = -(yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2073 "sintax_analizer.tab.c"
    break;

  case 106: /* exp_op: exp_op OP_GT exp_op  */
#line 497 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f > %.*f is always %s\n", lineNumber, dec1, (yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val > (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2086 "sintax_analizer.tab.c"
    break;

  case 107: /* exp_op: exp_op OP_LT exp_op  */
#line 505 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f < %.*f is always %s\n", lineNumber, dec1, (yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val < (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2099 "sintax_analizer.tab.c"
    break;

  case 108: /* exp_op: exp_op OP_GTE exp_op  */
#line 513 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f >= %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val >= (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2112 "sintax_analizer.tab.c"
    break;

  case 109: /* exp_op: exp_op OP_LTE exp_op  */
#line 521 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f <= %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val <= (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2125 "sintax_analizer.tab.c"
    break;

  case 110: /* exp_op: exp_op OP_EQ exp_op  */
#line 529 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkValuesComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f == %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val == (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2138 "sintax_analizer.tab.c"
    break;

  case 111: /* exp_op: exp_op OP_NEQ exp_op  */
#line 537 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkValuesComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f != %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val != (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2151 "sintax_analizer.tab.c"
    break;

  case 112: /* exp_op: exp_op OP_AND exp_op  */
#line 545 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkLogicOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2157 "sintax_analizer.tab.c"
    break;

  case 113: /* exp_op: exp_op OP_OR exp_op  */
#line 546 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkLogicOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2163 "sintax_analizer.tab.c"
    break;

  case 114: /* exp_op: OP_NOT exp_op  */
#line 547 "sintax_analizer.y"
                              { (yyval.sdata).type = checkLogicOperation((yyvsp[0].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2169 "sintax_analizer.tab.c"
    break;

  case 115: /* exp_op: var_value OP_ASSIGN exp_op  */
#line 548 "sintax_analizer.y"
                                           { (yyval.sdata).type = singleAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2175 "sintax_analizer.tab.c"
    break;

  case 116: /* exp_op: var_value OP_ADD_ASSIGN exp_op  */
#line 549 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2181 "sintax_analizer.tab.c"
    break;

  case 117: /* exp_op: var_value OP_SUB_ASSIGN exp_op  */
#line 550 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2187 "sintax_analizer.tab.c"
    break;

  case 118: /* exp_op: var_value OP_MUL_ASSIGN exp_op  */
#line 551 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2193 "sintax_analizer.tab.c"
    break;

  case 119: /* exp_op: var_value OP_DIV_ASSIGN exp_op  */
#line 552 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2199 "sintax_analizer.tab.c"
    break;

  case 120: /* exp_op: var_value OP_MOD_ASSIGN exp_op  */
#line 553 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2205 "sintax_analizer.tab.c"
    break;

  case 121: /* exp_op: LEFT_PARENT exp_op RIGHT_PARENT  */
#line 554 "sintax_analizer.y"
                                                { (yyval.sdata).type = (yyvsp[-1].sdata).type; (yyval.sdata).hasVal=(yyvsp[-1].sdata).hasVal; if((yyvsp[-1].sdata).hasVal) { (yyval.sdata).val = (yyvsp[-1].sdata).val; } }
#line 2211 "sintax_analizer.tab.c"
    break;

  case 122: /* exp_op: value_data  */
#line 555 "sintax_analizer.y"
                           { (yyval.sdata).type = (yyvsp[0].sdata).type; (yyval.sdata).hasVal = (yyvsp[0].sdata).hasVal; if((yyvsp[0].sdata).hasVal) { (yyval.sdata).val = (yyvsp[0].sdata).val; }; }
#line 2217 "sintax_analizer.tab.c"
    break;

  case 123: /* exp_op: func_call  */
#line 556 "sintax_analizer.y"
                          { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0;
    if ((yyvsp[0].ival) == -1) {
        printf("Incompatible type error at line %d: the function called has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 2228 "sintax_analizer.tab.c"
    break;

  case 124: /* exp_op: inc_dec  */
#line 562 "sintax_analizer.y"
                        { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0; }
#line 2234 "sintax_analizer.tab.c"
    break;

  case 125: /* inc_dec: var_value ops_inc_dec  */
#line 564 "sintax_analizer.y"
                                      { (yyval.ival) = checkIncrementDecrement((yyvsp[-1].ival)); }
#line 2240 "sintax_analizer.tab.c"
    break;

  case 126: /* inc_dec: ops_inc_dec var_value  */
#line 564 "sintax_analizer.y"
                                                                                                    { (yyval.ival) = checkIncrementDecrement((yyvsp[0].ival)); }
#line 2246 "sintax_analizer.tab.c"
    break;

  case 129: /* func_call: IDENTIFIER LEFT_PARENT RIGHT_PARENT  */
#line 568 "sintax_analizer.y"
                                                    { (yyval.ival) = getSymbType((yyvsp[-2].sval), true); }
#line 2252 "sintax_analizer.tab.c"
    break;

  case 130: /* func_call: IDENTIFIER LEFT_PARENT func_args RIGHT_PARENT  */
#line 569 "sintax_analizer.y"
                                                              { (yyval.ival) = getSymbType((yyvsp[-3].sval), true); }
#line 2258 "sintax_analizer.tab.c"
    break;

  case 136: /* asingn: var_value OP_ASSIGN exp_op  */
#line 575 "sintax_analizer.y"
                                           { singleAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2264 "sintax_analizer.tab.c"
    break;

  case 137: /* asingn: var_value OP_ADD_ASSIGN exp_op  */
#line 576 "sintax_analizer.y"
                                               { checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2270 "sintax_analizer.tab.c"
    break;

  case 138: /* asingn: var_value ops_asingn exp_op  */
#line 577 "sintax_analizer.y"
                                            { checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2276 "sintax_analizer.tab.c"
    break;


#line 2280 "sintax_analizer.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 580 "sintax_analizer.y"


void yyerror() {
    printf("Sintax error at line %d, the next sequence is not valid: %s\n", lineNumber, 
        strcmp(yytext, "\n") == 0 ? "EOL (end of line token)" : yytext);
    hasErrors = true;
}

int main(int argc, char **argv) {
    if (argc > 1)
        yyin = fopen(argv[1], "rt");
    else
        yyin = stdin;
    yyparse();
    if (!hasErrors)
        printf("Entrada valida\n");
    return 0;
}
