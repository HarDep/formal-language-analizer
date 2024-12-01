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
#define LINE_NUM_TYPE int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern YYTXT yytext;
extern LINE_NUM_TYPE lineNumber;
extern bool hasErrors;
extern int yylex(void);
extern FILE *yyin;
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
        printf("Incompatible type error at line %d: unsoported type assignment expression\n",lineNumber);
        hasErrors = true;
    } else if (a != b) {
        printf("Incompatible type error at line %d: unsoported type assignment expression\n",lineNumber);
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
        printf("Incompatible type error at line %d: unsoported assignment expression with data type %s\n", lineNumber, a == 4 ? "bool" : "char");
        hasErrors = true;
        return 0;
    }
    b = a == 5 ? 5 : b;
    if(b == 5 && a != 5) {
        printf("Incompatible type error at line %d: unsoported assignment expression with data type string\n", lineNumber);
        hasErrors = true;
        return 0;
    }
    if(b == 3 && a == 2) {
        printf("Incompatible type error at line %d: unsoported assignment expression with data type float\n", lineNumber);
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

#line 285 "sintax_analizer.tab.c"

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
  YYSYMBOL_exp = 69,                       /* exp  */
  YYSYMBOL_exp_wth_bl = 70,                /* exp_wth_bl  */
  YYSYMBOL_func = 71,                      /* func  */
  YYSYMBOL_std_block_d = 72,               /* std_block_d  */
  YYSYMBOL_73_1 = 73,                      /* $@1  */
  YYSYMBOL_func_dec = 74,                  /* func_dec  */
  YYSYMBOL_block = 75,                     /* block  */
  YYSYMBOL_block_line = 76,                /* block_line  */
  YYSYMBOL_block_exp = 77,                 /* block_exp  */
  YYSYMBOL_rtrn = 78,                      /* rtrn  */
  YYSYMBOL_throw_dec = 79,                 /* throw_dec  */
  YYSYMBOL_loop = 80,                      /* loop  */
  YYSYMBOL_for_decl = 81,                  /* for_decl  */
  YYSYMBOL_for_vrs_dec = 82,               /* for_vrs_dec  */
  YYSYMBOL_for_var = 83,                   /* for_var  */
  YYSYMBOL_for_cond = 84,                  /* for_cond  */
  YYSYMBOL_for_sec = 85,                   /* for_sec  */
  YYSYMBOL_for_iter = 86,                  /* for_iter  */
  YYSYMBOL_while_exp = 87,                 /* while_exp  */
  YYSYMBOL_conditional = 88,               /* conditional  */
  YYSYMBOL_if_els_stmt = 89,               /* if_els_stmt  */
  YYSYMBOL_if_stmt = 90,                   /* if_stmt  */
  YYSYMBOL_91_2 = 91,                      /* $@2  */
  YYSYMBOL_else_stmt = 92,                 /* else_stmt  */
  YYSYMBOL_els_if_stmt = 93,               /* els_if_stmt  */
  YYSYMBOL_switch_stmt = 94,               /* switch_stmt  */
  YYSYMBOL_95_3 = 95,                      /* $@3  */
  YYSYMBOL_switch_block = 96,              /* switch_block  */
  YYSYMBOL_switch_line = 97,               /* switch_line  */
  YYSYMBOL_98_4 = 98,                      /* $@4  */
  YYSYMBOL_99_5 = 99,                      /* $@5  */
  YYSYMBOL_exception = 100,                /* exception  */
  YYSYMBOL_try_catch = 101,                /* try_catch  */
  YYSYMBOL_func_type = 102,                /* func_type  */
  YYSYMBOL_func_params = 103,              /* func_params  */
  YYSYMBOL_params_sec = 104,               /* params_sec  */
  YYSYMBOL_param = 105,                    /* param  */
  YYSYMBOL_instance = 106,                 /* instance  */
  YYSYMBOL_inst_id = 107,                  /* inst_id  */
  YYSYMBOL_type = 108,                     /* type  */
  YYSYMBOL_value_data = 109,               /* value_data  */
  YYSYMBOL_var_value = 110,                /* var_value  */
  YYSYMBOL_exp_op = 111,                   /* exp_op  */
  YYSYMBOL_inc_dec = 112,                  /* inc_dec  */
  YYSYMBOL_ops_inc_dec = 113,              /* ops_inc_dec  */
  YYSYMBOL_func_call = 114,                /* func_call  */
  YYSYMBOL_func_args = 115,                /* func_args  */
  YYSYMBOL_func_arg = 116,                 /* func_arg  */
  YYSYMBOL_asingn = 117,                   /* asingn  */
  YYSYMBOL_ops_asingn = 118                /* ops_asingn  */
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
#define YYLAST   597

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

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
       0,   242,   242,   242,   244,   244,   244,   246,   246,   246,
     246,   248,   248,   248,   248,   250,   257,   257,   259,   261,
     261,   263,   263,   265,   265,   265,   265,   265,   265,   265,
     265,   266,   281,   283,   283,   285,   285,   287,   288,   289,
     291,   293,   293,   295,   306,   314,   314,   316,   316,   318,
     325,   325,   327,   327,   327,   329,   329,   336,   338,   338,
     338,   340,   340,   345,   347,   347,   359,   359,   360,   360,
     370,   370,   372,   374,   374,   376,   376,   378,   378,   378,
     380,   380,   388,   388,   398,   400,   401,   402,   403,   404,
     406,   407,   408,   409,   410,   411,   412,   414,   415,   417,
     438,   446,   454,   467,   480,   488,   496,   504,   512,   520,
     528,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   553,   555,   555,   557,   557,   559,   560,
     562,   562,   562,   564,   564,   566,   567,   568,   570,   570,
     570,   570
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
  "NUM_DEC", "IDENTIFIER", "EOL", "$accept", "in", "line", "exp",
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

#define YYPACT_NINF (-181)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -181,   140,  -181,  -181,  -181,   -53,    -3,     7,   -15,   -41,
       6,  -181,  -181,  -181,  -181,  -181,    10,    16,    20,  -181,
    -181,    25,  -181,  -181,   -15,  -181,   -15,  -181,  -181,    -6,
    -181,  -181,    33,  -181,    90,    34,    56,  -181,   -23,  -181,
    -181,  -181,    37,   256,  -181,    60,    75,  -181,   256,   256,
     244,  -181,  -181,  -181,    -8,  -181,    48,    76,   256,  -181,
     256,   256,  -181,  -181,  -181,  -181,  -181,   256,  -181,  -181,
     129,   104,    97,   105,   256,   256,   256,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,   123,   493,  -181,  -181,  -181,  -181,
     -21,   101,   308,   556,   514,  -181,    -4,   556,   118,   114,
    -181,  -181,    -8,  -181,  -181,   556,   556,   556,   556,   256,
     -15,   256,    37,  -181,  -181,   535,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,  -181,   340,  -181,   116,   127,
     117,    35,  -181,    94,   107,  -181,   256,  -181,  -181,    96,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,   130,
     132,   256,  -181,   196,  -181,   372,   556,  -181,   126,   556,
    -181,  -181,   556,   556,   556,   556,   556,   556,   567,   567,
     576,   576,   125,   125,   125,   125,    11,    11,  -181,  -181,
    -181,  -181,   122,  -181,   -37,  -181,  -181,   141,   149,   556,
    -181,   -15,   103,   556,   267,  -181,  -181,   -10,   178,   119,
    -181,   -19,   120,  -181,   -13,  -181,  -181,   148,  -181,  -181,
     256,  -181,  -181,   158,   159,  -181,   256,   157,    36,  -181,
     -10,   556,  -181,   168,    59,  -181,   169,  -181,  -181,  -181,
    -181,  -181,  -181,   404,  -181,   436,  -181,   436
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   126,   127,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,     0,     0,    97,     4,
       3,     0,     6,    14,     0,    11,     0,    12,    50,    52,
      51,    13,    70,     7,    82,     0,     0,     8,     0,     9,
      10,    98,     0,     0,    16,     0,     0,    19,     0,     0,
       0,     5,    15,    38,     0,    53,    54,     0,     0,    84,
       0,     0,   138,   139,   140,   141,   124,     0,    97,   125,
       0,     0,     0,    41,     0,     0,     0,    93,    94,    90,
      95,    91,    92,   121,    96,     0,   123,   122,    19,    39,
       0,     0,     0,    55,     0,   128,    97,   134,     0,   130,
      57,    58,     0,    60,    19,    83,   135,   136,   137,     0,
       0,     0,     0,   104,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,    76,     0,     0,
      77,     0,    18,     0,     0,    24,    34,    21,    20,     0,
      31,    32,    28,    29,    30,    23,    25,    26,    27,     0,
       0,     0,   129,     0,    59,     0,    43,    37,     0,    44,
      42,   120,   114,   115,   116,   117,   118,   119,   111,   112,
     109,   110,   105,   106,   107,   108,    99,   100,   101,   102,
     103,    17,     0,    75,     0,    74,    73,     0,     0,    33,
      22,     0,     0,   133,     0,   131,    71,     0,    80,     0,
      78,     0,     0,    56,     0,   132,    40,    45,    47,    48,
       0,    79,    36,     0,     0,    63,     0,     0,    61,    64,
       0,    81,    35,     0,     0,    68,     0,    65,    46,    19,
      66,    19,    62,     0,    19,    69,    72,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,  -181,  -181,    -5,  -181,  -181,   -84,
    -181,  -181,  -181,  -181,   198,  -181,    89,  -181,  -181,   -28,
    -181,   164,   202,  -181,   -47,  -181,   154,  -181,  -181,  -181,
    -181,   -16,  -181,  -181,   212,  -181,  -181,  -181,  -180,  -181,
     214,  -181,  -136,  -181,    -1,    -9,     0,   -27,     5,  -151,
    -181,     1,  -181
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,    21,    22,    23,   100,    88,    24,    92,
     148,   149,   150,   151,   152,    71,    72,    73,   168,   216,
     217,    26,   153,    28,    29,   159,    55,    56,    30,   236,
     228,   229,   244,   241,   154,    32,   142,    91,   139,   140,
     155,    34,    35,    83,    84,    97,    86,    38,    87,    98,
      99,   158,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    37,    40,    45,   136,   196,    39,   101,   137,    66,
     222,    41,   205,     5,   210,    44,     3,     4,   225,    52,
     165,    53,    44,    46,    50,    42,     5,   138,   209,   221,
     132,   133,   134,   161,    85,    43,    47,    69,    48,    93,
      94,    68,   223,   138,    49,   226,   227,    16,    50,   105,
      54,   106,   107,   215,    68,   164,   208,    66,   108,    60,
      61,    62,    63,    64,    65,   113,   114,   115,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    57,     3,     4,    11,    12,    13,    14,    15,   195,
      51,    36,   156,    58,   226,   227,   240,   157,    59,     7,
     166,    70,   169,    90,   102,   167,   104,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   116,   117,   118,   119,
     120,   121,   109,   110,   111,    36,   156,   199,   141,   112,
       2,   157,   130,   131,   132,   133,   134,   162,   163,     3,
       4,   194,   203,   192,   198,   243,   193,   245,   197,   201,
     247,   200,   202,   207,    36,   156,     3,     4,   214,   211,
     157,    11,    12,    13,    14,    15,     5,   212,     6,     7,
       8,   220,   230,   138,   224,     9,    10,   232,   233,    11,
      12,    13,    14,    15,   235,    16,   213,    17,   239,    25,
     242,   170,   238,    27,    18,    19,    36,   218,   219,    89,
     103,   231,   237,    31,    74,    33,     0,   234,    75,     0,
       0,     0,     3,     4,    76,     0,     0,     0,     0,    36,
     218,   219,     5,     0,     0,     0,     0,     0,     0,    77,
      78,     0,    36,   156,    36,   156,    36,   156,   157,     0,
     157,     0,   157,     0,     0,     0,    79,    80,    81,    82,
      96,   204,    74,     0,     0,     0,    75,     0,     0,     0,
       3,     4,    76,    95,    74,     0,     0,     0,    75,     0,
       5,     0,     3,     4,    76,    74,     0,    77,    78,    75,
       0,     0,     5,     3,     4,    76,     0,     0,     0,    77,
      78,     0,     0,     5,    79,    80,    81,    82,    96,     0,
      77,    78,     0,     0,     0,     0,    79,    80,    81,    82,
      18,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    96,   143,     0,     3,     4,     0,     0,     0,   144,
       0,     0,     0,     0,     5,     0,     6,     7,     8,   145,
     146,     0,     0,     0,    10,     0,     0,    11,    12,    13,
      14,    15,     0,    16,   143,    17,     3,     4,     0,     0,
       0,   191,    18,   147,     0,     0,     5,     0,     6,     7,
       8,   145,   146,     0,     0,     0,    10,     0,     0,    11,
      12,    13,    14,    15,     0,    16,   143,    17,     3,     4,
       0,     0,     0,   206,    18,   147,     0,     0,     5,     0,
       6,     7,     8,   145,   146,     0,     0,     0,    10,     0,
       0,    11,    12,    13,    14,    15,     0,    16,   143,    17,
       3,     4,     0,     0,     0,   246,    18,   147,     0,     0,
       5,     0,     6,     7,     8,   145,   146,     0,     0,     0,
      10,     0,     0,    11,    12,    13,    14,    15,     0,    16,
     143,    17,     3,     4,     0,     0,     0,     0,    18,   147,
       0,     0,     5,     0,     6,     7,     8,   145,   146,     0,
       0,     0,    10,     0,     0,    11,    12,    13,    14,    15,
       0,    16,     0,    17,     0,     0,     0,     0,     0,     0,
      18,   147,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,   135,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,   160,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,   171,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   126,
     127,   128,   129,   130,   131,   132,   133,   134
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     8,    88,   141,     1,    54,    29,    36,
      29,    64,   163,    36,   194,    30,    26,    27,    31,    24,
     104,    26,    30,    64,    28,    28,    36,    64,    65,   209,
      19,    20,    21,    37,    43,    28,    30,    38,    28,    48,
      49,    64,    61,    64,    28,    58,    59,    55,    28,    58,
      56,    60,    61,   204,    64,   102,   192,    84,    67,     3,
       4,     5,     6,     7,     8,    74,    75,    76,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    48,    26,    27,    49,    50,    51,    52,    53,    54,
      65,    92,    92,     3,    58,    59,    37,    92,    64,    39,
     109,    64,   111,    28,    56,   110,    30,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     3,     4,     5,     6,
       7,     8,     3,    29,    37,   136,   136,   146,    37,    34,
       0,   136,    17,    18,    19,    20,    21,    29,    34,    26,
      27,    34,   161,    37,    47,   239,    29,   241,    64,    29,
     244,    65,    30,    37,   165,   165,    26,    27,    65,    28,
     165,    49,    50,    51,    52,    53,    36,    28,    38,    39,
      40,     3,    34,    64,    64,    45,    46,    29,    29,    49,
      50,    51,    52,    53,    37,    55,   201,    57,    30,     1,
      31,   112,   230,     1,    64,    65,   207,   207,   207,    45,
      56,   220,   228,     1,    18,     1,    -1,   226,    22,    -1,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,   230,
     230,   230,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,   243,   243,   245,   245,   247,   247,   243,    -1,
     245,    -1,   247,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    18,    -1,    -1,    -1,    22,    -1,
      36,    -1,    26,    27,    28,    18,    -1,    43,    44,    22,
      -1,    -1,    36,    26,    27,    28,    -1,    -1,    -1,    43,
      44,    -1,    -1,    36,    60,    61,    62,    63,    64,    -1,
      43,    44,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    24,    57,    26,    27,    -1,    -1,
      -1,    31,    64,    65,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    24,    57,    26,    27,
      -1,    -1,    -1,    31,    64,    65,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    24,    57,
      26,    27,    -1,    -1,    -1,    31,    64,    65,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    -1,    55,
      24,    57,    26,    27,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    13,
      14,    15,    16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,     0,    26,    27,    36,    38,    39,    40,    45,
      46,    49,    50,    51,    52,    53,    55,    57,    64,    65,
      68,    69,    70,    71,    74,    80,    87,    88,    89,    90,
      94,   100,   101,   106,   107,   108,   110,   112,   113,   114,
     117,    64,    28,    28,    30,    72,    64,    30,    28,    28,
      28,    65,    72,    72,    56,    92,    93,    48,     3,    64,
       3,     4,     5,     6,     7,     8,   113,   118,    64,   110,
      64,    81,    82,    83,    18,    22,    28,    43,    44,    60,
      61,    62,    63,   109,   110,   111,   112,   114,    73,    87,
      28,   103,    75,   111,   111,    29,    64,   111,   115,   116,
      72,    90,    56,    92,    30,   111,   111,   111,   111,     3,
      29,    37,    34,   111,   111,   111,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    29,    75,    29,    64,   104,
     105,    37,   102,    24,    31,    41,    42,    65,    76,    77,
      78,    79,    80,    88,   100,   106,   112,   114,   117,    91,
      29,    37,    29,    34,    90,    75,   111,    72,    84,   111,
      82,    29,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,    31,    37,    29,    34,    54,   108,    64,    47,   111,
      65,    29,    30,   111,    65,   115,    31,    37,   108,    65,
     104,    28,    28,    72,    65,   115,    85,    86,   112,   117,
       3,   104,    29,    61,    64,    31,    58,    59,    96,    97,
      34,   111,    29,    29,   111,    37,    95,    97,    85,    30,
      37,    99,    31,    75,    98,    75,    31,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    73,    72,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    82,    82,    83,    84,    85,    85,    86,    86,    87,
      88,    88,    89,    89,    89,    91,    90,    92,    93,    93,
      93,    95,    94,    94,    96,    96,    98,    97,    99,    97,
     100,   100,   101,   102,   102,   103,   103,   104,   104,   104,
     105,   105,   106,   106,   107,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   116,   116,   117,   117,   117,   118,   118,
     118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     4,     0,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     5,     4,     5,     2,     3,
       5,     1,     3,     3,     1,     1,     3,     1,     1,     4,
       1,     1,     1,     2,     2,     0,     6,     2,     2,     3,
       2,     0,     9,     7,     1,     2,     0,     5,     0,     4,
       1,     5,    11,     2,     2,     3,     2,     1,     3,     4,
       3,     5,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     2,     1,     1,     3,     4,
       1,     3,     4,     3,     1,     3,     3,     3,     1,     1,
       1,     1
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
  case 15: /* func: func_dec std_block_d  */
#line 250 "sintax_analizer.y"
                                     {
    if (functType != -1 && !hasReturn) {
        printf("Missing return error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1649 "sintax_analizer.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 257 "sintax_analizer.y"
                             { initBlock(); }
#line 1655 "sintax_analizer.tab.c"
    break;

  case 17: /* std_block_d: LEFT_BRACKET $@1 block RIGHT_BRACKET  */
#line 257 "sintax_analizer.y"
                                                                  { endBlock(); }
#line 1661 "sintax_analizer.tab.c"
    break;

  case 18: /* func_dec: FUNCTION_KW IDENTIFIER func_params func_type  */
#line 259 "sintax_analizer.y"
                                                             { addSymb((yyvsp[-2].sval), (yyvsp[0].ival), true); }
#line 1667 "sintax_analizer.tab.c"
    break;

  case 31: /* block_exp: rtrn  */
#line 266 "sintax_analizer.y"
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
#line 1688 "sintax_analizer.tab.c"
    break;

  case 33: /* rtrn: RETURN_KW exp_op  */
#line 283 "sintax_analizer.y"
                                 { (yyval.ival) = (yyvsp[0].sdata).type; }
#line 1694 "sintax_analizer.tab.c"
    break;

  case 34: /* rtrn: RETURN_KW  */
#line 283 "sintax_analizer.y"
                                                               { (yyval.ival) = -1; }
#line 1700 "sintax_analizer.tab.c"
    break;

  case 43: /* for_var: IDENTIFIER OP_ASSIGN exp_op  */
#line 295 "sintax_analizer.y"
                                            {
    if ((yyvsp[0].sdata).type != 2 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: the variable used in for iteration is not a int value\n", 
            lineNumber);
    } else {
        if ((yyvsp[0].sdata).type != 0) {
            addForNumber((yyvsp[-2].sval));
        }
    }
}
#line 1715 "sintax_analizer.tab.c"
    break;

  case 44: /* for_cond: exp_op  */
#line 306 "sintax_analizer.y"
                       {
    if((yyvsp[0].sdata).type != 4 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition used in for iteration is not a bool value\n", 
            lineNumber);
        hasErrors = true;
    }
}
#line 1727 "sintax_analizer.tab.c"
    break;

  case 49: /* while_exp: WHILE_KW LEFT_PARENT exp_op RIGHT_PARENT  */
#line 318 "sintax_analizer.y"
                                                         {
    if ((yyvsp[-1].sdata).type != 4 && (yyvsp[-1].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1738 "sintax_analizer.tab.c"
    break;

  case 55: /* $@2: %empty  */
#line 329 "sintax_analizer.y"
                                         {
    if ((yyvsp[0].sdata).type != 4 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1749 "sintax_analizer.tab.c"
    break;

  case 61: /* $@3: %empty  */
#line 340 "sintax_analizer.y"
                                                                                        {
    if ((yyvsp[-4].sdata).type != (yyvsp[0].ival) && (yyvsp[0].ival) != 0 && (yyvsp[-4].sdata).type != 0) {
        printf("Incompatible type error at line %d: the cases type are not compatible with the switch value type\n", lineNumber);
        hasErrors = true;
    }
}
#line 1760 "sintax_analizer.tab.c"
    break;

  case 62: /* switch_stmt: SWITCH_KW LEFT_PARENT exp_op RIGHT_PARENT LEFT_BRACKET EOL switch_block $@3 RIGHT_BRACKET  */
#line 345 "sintax_analizer.y"
                { hasDefaultCase = false; }
#line 1766 "sintax_analizer.tab.c"
    break;

  case 64: /* switch_block: switch_line  */
#line 347 "sintax_analizer.y"
                            { (yyval.ival) = (yyvsp[0].ival) == -1 ? 0 : (yyvsp[0].ival); }
#line 1772 "sintax_analizer.tab.c"
    break;

  case 65: /* switch_block: switch_block switch_line  */
#line 347 "sintax_analizer.y"
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
#line 1788 "sintax_analizer.tab.c"
    break;

  case 66: /* $@4: %empty  */
#line 359 "sintax_analizer.y"
                                     { initBlock(); }
#line 1794 "sintax_analizer.tab.c"
    break;

  case 67: /* switch_line: CASE_KW exp_op COLON $@4 block  */
#line 359 "sintax_analizer.y"
                                                            { endBlock(); (yyval.ival) = (yyvsp[-3].sdata).type; }
#line 1800 "sintax_analizer.tab.c"
    break;

  case 68: /* $@5: %empty  */
#line 360 "sintax_analizer.y"
                                 { initBlock(); }
#line 1806 "sintax_analizer.tab.c"
    break;

  case 69: /* switch_line: DEFAULT_KW COLON $@5 block  */
#line 360 "sintax_analizer.y"
                                                        {
    endBlock();
    if (hasDefaultCase) {
        printf("Definition error at line %d: the switch has more than one default case\n", lineNumber);
        hasErrors = true;
    }
    hasDefaultCase = true;
    (yyval.ival) = -1;
}
#line 1820 "sintax_analizer.tab.c"
    break;

  case 73: /* func_type: COLON type  */
#line 374 "sintax_analizer.y"
                           { functType = (yyvsp[0].ival); hasReturn = false; (yyval.ival) = (yyvsp[0].ival); }
#line 1826 "sintax_analizer.tab.c"
    break;

  case 74: /* func_type: COLON VOID_KW  */
#line 374 "sintax_analizer.y"
                                                                                           { functType = -1; (yyval.ival) = -1; }
#line 1832 "sintax_analizer.tab.c"
    break;

  case 80: /* param: IDENTIFIER COLON type  */
#line 380 "sintax_analizer.y"
                                      { addFunctionParam((yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 1838 "sintax_analizer.tab.c"
    break;

  case 81: /* param: IDENTIFIER COLON type OP_ASSIGN exp_op  */
#line 380 "sintax_analizer.y"
                                                                                                             {
    addFunctionParam((yyvsp[-4].sval), (yyvsp[-2].ival));
    if ((yyvsp[0].sdata).type != (yyvsp[-2].ival) && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: data value of parameter %s is not compatible with data type\n",lineNumber, (yyvsp[-4].sval));
        hasErrors = true;
    }
}
#line 1850 "sintax_analizer.tab.c"
    break;

  case 83: /* instance: inst_id OP_ASSIGN exp_op  */
#line 388 "sintax_analizer.y"
                                                   {
    if ((yyvsp[-2].ival) == 5 && (yyvsp[0].sdata).type != 5 && (yyvsp[0].sdata).type != 1 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber - 1);
        hasErrors = true;
    } else if ((yyvsp[-2].ival) != (yyvsp[0].sdata).type && (yyvsp[-2].ival) != 5 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber - 1);
        hasErrors = true;
    }
}
#line 1864 "sintax_analizer.tab.c"
    break;

  case 84: /* inst_id: type IDENTIFIER  */
#line 398 "sintax_analizer.y"
                                { addSymb((yyvsp[0].sval), (yyvsp[-1].ival), false); (yyval.ival) = (yyvsp[-1].ival); }
#line 1870 "sintax_analizer.tab.c"
    break;

  case 85: /* type: CHAR_KW  */
#line 400 "sintax_analizer.y"
                            { (yyval.ival) = 1; }
#line 1876 "sintax_analizer.tab.c"
    break;

  case 86: /* type: INT_KW  */
#line 401 "sintax_analizer.y"
                            { (yyval.ival) = 2; }
#line 1882 "sintax_analizer.tab.c"
    break;

  case 87: /* type: FLOAT_KW  */
#line 402 "sintax_analizer.y"
                            { (yyval.ival) = 3; }
#line 1888 "sintax_analizer.tab.c"
    break;

  case 88: /* type: BOOL_KW  */
#line 403 "sintax_analizer.y"
                            { (yyval.ival) = 4; }
#line 1894 "sintax_analizer.tab.c"
    break;

  case 89: /* type: STRING_KW  */
#line 404 "sintax_analizer.y"
                            { (yyval.ival) = 5; }
#line 1900 "sintax_analizer.tab.c"
    break;

  case 90: /* value_data: CHAR  */
#line 406 "sintax_analizer.y"
                            { (yyval.sdata).type = 1; (yyval.sdata).hasVal = 0; }
#line 1906 "sintax_analizer.tab.c"
    break;

  case 91: /* value_data: NUM  */
#line 407 "sintax_analizer.y"
                            { (yyval.sdata).type = 2; (yyval.sdata).hasVal = 1; (yyval.sdata).val = (yyvsp[0].dval); }
#line 1912 "sintax_analizer.tab.c"
    break;

  case 92: /* value_data: NUM_DEC  */
#line 408 "sintax_analizer.y"
                            { (yyval.sdata).type = 3; (yyval.sdata).hasVal = 1; (yyval.sdata).val = (yyvsp[0].dval); }
#line 1918 "sintax_analizer.tab.c"
    break;

  case 93: /* value_data: TRUE_KW  */
#line 409 "sintax_analizer.y"
                            { (yyval.sdata).type = 4; (yyval.sdata).hasVal = 0; }
#line 1924 "sintax_analizer.tab.c"
    break;

  case 94: /* value_data: FALSE_KW  */
#line 410 "sintax_analizer.y"
                            { (yyval.sdata).type = 4; (yyval.sdata).hasVal = 0; }
#line 1930 "sintax_analizer.tab.c"
    break;

  case 95: /* value_data: STRING  */
#line 411 "sintax_analizer.y"
                            { (yyval.sdata).type = 5; (yyval.sdata).hasVal = 0; }
#line 1936 "sintax_analizer.tab.c"
    break;

  case 96: /* value_data: var_value  */
#line 412 "sintax_analizer.y"
                            { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0; }
#line 1942 "sintax_analizer.tab.c"
    break;

  case 97: /* var_value: IDENTIFIER  */
#line 414 "sintax_analizer.y"
                            { (yyval.ival) = getSymbType((yyvsp[0].sval), false); }
#line 1948 "sintax_analizer.tab.c"
    break;

  case 98: /* var_value: D_COLON IDENTIFIER  */
#line 415 "sintax_analizer.y"
                                   { (yyval.ival) = getGlobalSymbType((yyvsp[0].sval)); }
#line 1954 "sintax_analizer.tab.c"
    break;

  case 99: /* exp_op: exp_op OP_ADD exp_op  */
#line 417 "sintax_analizer.y"
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
#line 1980 "sintax_analizer.tab.c"
    break;

  case 100: /* exp_op: exp_op OP_SUB exp_op  */
#line 438 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val - (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 1993 "sintax_analizer.tab.c"
    break;

  case 101: /* exp_op: exp_op OP_MUL exp_op  */
#line 446 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val * (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2006 "sintax_analizer.tab.c"
    break;

  case 102: /* exp_op: exp_op OP_DIV exp_op  */
#line 454 "sintax_analizer.y"
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
#line 2024 "sintax_analizer.tab.c"
    break;

  case 103: /* exp_op: exp_op OP_MOD exp_op  */
#line 467 "sintax_analizer.y"
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
#line 2042 "sintax_analizer.tab.c"
    break;

  case 104: /* exp_op: OP_SUB exp_op  */
#line 480 "sintax_analizer.y"
                                           { (yyval.sdata).type = checkNumsOperation((yyvsp[0].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = -(yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2055 "sintax_analizer.tab.c"
    break;

  case 105: /* exp_op: exp_op OP_GT exp_op  */
#line 488 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f > %.*f is always %s\n", lineNumber, dec1, (yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val > (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2068 "sintax_analizer.tab.c"
    break;

  case 106: /* exp_op: exp_op OP_LT exp_op  */
#line 496 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f < %.*f is always %s\n", lineNumber, dec1, (yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val < (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2081 "sintax_analizer.tab.c"
    break;

  case 107: /* exp_op: exp_op OP_GTE exp_op  */
#line 504 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f >= %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val >= (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2094 "sintax_analizer.tab.c"
    break;

  case 108: /* exp_op: exp_op OP_LTE exp_op  */
#line 512 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f <= %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val <= (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2107 "sintax_analizer.tab.c"
    break;

  case 109: /* exp_op: exp_op OP_EQ exp_op  */
#line 520 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkValuesComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f == %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val == (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2120 "sintax_analizer.tab.c"
    break;

  case 110: /* exp_op: exp_op OP_NEQ exp_op  */
#line 528 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkValuesComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f != %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val != (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2133 "sintax_analizer.tab.c"
    break;

  case 111: /* exp_op: exp_op OP_AND exp_op  */
#line 536 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkLogicOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2139 "sintax_analizer.tab.c"
    break;

  case 112: /* exp_op: exp_op OP_OR exp_op  */
#line 537 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkLogicOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2145 "sintax_analizer.tab.c"
    break;

  case 113: /* exp_op: OP_NOT exp_op  */
#line 538 "sintax_analizer.y"
                              { (yyval.sdata).type = checkLogicOperation((yyvsp[0].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2151 "sintax_analizer.tab.c"
    break;

  case 114: /* exp_op: var_value OP_ASSIGN exp_op  */
#line 539 "sintax_analizer.y"
                                           { (yyval.sdata).type = singleAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2157 "sintax_analizer.tab.c"
    break;

  case 115: /* exp_op: var_value OP_ADD_ASSIGN exp_op  */
#line 540 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2163 "sintax_analizer.tab.c"
    break;

  case 116: /* exp_op: var_value OP_SUB_ASSIGN exp_op  */
#line 541 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2169 "sintax_analizer.tab.c"
    break;

  case 117: /* exp_op: var_value OP_MUL_ASSIGN exp_op  */
#line 542 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2175 "sintax_analizer.tab.c"
    break;

  case 118: /* exp_op: var_value OP_DIV_ASSIGN exp_op  */
#line 543 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2181 "sintax_analizer.tab.c"
    break;

  case 119: /* exp_op: var_value OP_MOD_ASSIGN exp_op  */
#line 544 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2187 "sintax_analizer.tab.c"
    break;

  case 120: /* exp_op: LEFT_PARENT exp_op RIGHT_PARENT  */
#line 545 "sintax_analizer.y"
                                                { (yyval.sdata).type = (yyvsp[-1].sdata).type; (yyval.sdata).hasVal=(yyvsp[-1].sdata).hasVal; if((yyvsp[-1].sdata).hasVal) { (yyval.sdata).val = (yyvsp[-1].sdata).val; } }
#line 2193 "sintax_analizer.tab.c"
    break;

  case 121: /* exp_op: value_data  */
#line 546 "sintax_analizer.y"
                           { (yyval.sdata).type = (yyvsp[0].sdata).type; (yyval.sdata).hasVal = (yyvsp[0].sdata).hasVal; if((yyvsp[0].sdata).hasVal) { (yyval.sdata).val = (yyvsp[0].sdata).val; }; }
#line 2199 "sintax_analizer.tab.c"
    break;

  case 122: /* exp_op: func_call  */
#line 547 "sintax_analizer.y"
                          { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0;
    if ((yyvsp[0].ival) == -1) {
        printf("Incompatible type error at line %d: the function called has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 2210 "sintax_analizer.tab.c"
    break;

  case 123: /* exp_op: inc_dec  */
#line 553 "sintax_analizer.y"
                        { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0; }
#line 2216 "sintax_analizer.tab.c"
    break;

  case 124: /* inc_dec: var_value ops_inc_dec  */
#line 555 "sintax_analizer.y"
                                      { (yyval.ival) = checkIncrementDecrement((yyvsp[-1].ival)); }
#line 2222 "sintax_analizer.tab.c"
    break;

  case 125: /* inc_dec: ops_inc_dec var_value  */
#line 555 "sintax_analizer.y"
                                                                                                    { (yyval.ival) = checkIncrementDecrement((yyvsp[0].ival)); }
#line 2228 "sintax_analizer.tab.c"
    break;

  case 128: /* func_call: IDENTIFIER LEFT_PARENT RIGHT_PARENT  */
#line 559 "sintax_analizer.y"
                                                    { (yyval.ival) = getSymbType((yyvsp[-2].sval), true); }
#line 2234 "sintax_analizer.tab.c"
    break;

  case 129: /* func_call: IDENTIFIER LEFT_PARENT func_args RIGHT_PARENT  */
#line 560 "sintax_analizer.y"
                                                              { (yyval.ival) = getSymbType((yyvsp[-3].sval), true); }
#line 2240 "sintax_analizer.tab.c"
    break;

  case 135: /* asingn: var_value OP_ASSIGN exp_op  */
#line 566 "sintax_analizer.y"
                                           { singleAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2246 "sintax_analizer.tab.c"
    break;

  case 136: /* asingn: var_value OP_ADD_ASSIGN exp_op  */
#line 567 "sintax_analizer.y"
                                               { checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2252 "sintax_analizer.tab.c"
    break;

  case 137: /* asingn: var_value ops_asingn exp_op  */
#line 568 "sintax_analizer.y"
                                            { checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2258 "sintax_analizer.tab.c"
    break;


#line 2262 "sintax_analizer.tab.c"

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

#line 571 "sintax_analizer.y"


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
