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
bool isInException = false;
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

#line 296 "sintax_analizer.tab.c"

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
  YYSYMBOL_OP_INC = 25,                    /* OP_INC  */
  YYSYMBOL_OP_DEC = 26,                    /* OP_DEC  */
  YYSYMBOL_LEFT_PARENT = 27,               /* LEFT_PARENT  */
  YYSYMBOL_RIGHT_PARENT = 28,              /* RIGHT_PARENT  */
  YYSYMBOL_LEFT_BRACKET = 29,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 30,             /* RIGHT_BRACKET  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_D_COLON = 32,                   /* D_COLON  */
  YYSYMBOL_COLON = 33,                     /* COLON  */
  YYSYMBOL_FOR_KW = 34,                    /* FOR_KW  */
  YYSYMBOL_WHILE_KW = 35,                  /* WHILE_KW  */
  YYSYMBOL_DO_KW = 36,                     /* DO_KW  */
  YYSYMBOL_BREAK_KW = 37,                  /* BREAK_KW  */
  YYSYMBOL_RETURN_KW = 38,                 /* RETURN_KW  */
  YYSYMBOL_TRUE_KW = 39,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 40,                  /* FALSE_KW  */
  YYSYMBOL_FUNCTION_KW = 41,               /* FUNCTION_KW  */
  YYSYMBOL_TRY_KW = 42,                    /* TRY_KW  */
  YYSYMBOL_CATCH_KW = 43,                  /* CATCH_KW  */
  YYSYMBOL_FINALLY_KW = 44,                /* FINALLY_KW  */
  YYSYMBOL_CHAR_KW = 45,                   /* CHAR_KW  */
  YYSYMBOL_INT_KW = 46,                    /* INT_KW  */
  YYSYMBOL_FLOAT_KW = 47,                  /* FLOAT_KW  */
  YYSYMBOL_BOOL_KW = 48,                   /* BOOL_KW  */
  YYSYMBOL_STRING_KW = 49,                 /* STRING_KW  */
  YYSYMBOL_VOID_KW = 50,                   /* VOID_KW  */
  YYSYMBOL_IF_KW = 51,                     /* IF_KW  */
  YYSYMBOL_ELSE_KW = 52,                   /* ELSE_KW  */
  YYSYMBOL_SWITCH_KW = 53,                 /* SWITCH_KW  */
  YYSYMBOL_CASE_KW = 54,                   /* CASE_KW  */
  YYSYMBOL_DEFAULT_KW = 55,                /* DEFAULT_KW  */
  YYSYMBOL_CHAR = 56,                      /* CHAR  */
  YYSYMBOL_STRING = 57,                    /* STRING  */
  YYSYMBOL_NUM = 58,                       /* NUM  */
  YYSYMBOL_NUM_DEC = 59,                   /* NUM_DEC  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_EOL = 61,                       /* EOL  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_in = 63,                        /* in  */
  YYSYMBOL_line = 64,                      /* line  */
  YYSYMBOL_n_line = 65,                    /* n_line  */
  YYSYMBOL_exp = 66,                       /* exp  */
  YYSYMBOL_exp_wth_bl = 67,                /* exp_wth_bl  */
  YYSYMBOL_func = 68,                      /* func  */
  YYSYMBOL_std_block_d = 69,               /* std_block_d  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_func_dec = 71,                  /* func_dec  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_block_line = 73,                /* block_line  */
  YYSYMBOL_block_exp = 74,                 /* block_exp  */
  YYSYMBOL_rtrn = 75,                      /* rtrn  */
  YYSYMBOL_throw_dec = 76,                 /* throw_dec  */
  YYSYMBOL_loop = 77,                      /* loop  */
  YYSYMBOL_for_decl = 78,                  /* for_decl  */
  YYSYMBOL_for_vrs_dec = 79,               /* for_vrs_dec  */
  YYSYMBOL_for_var = 80,                   /* for_var  */
  YYSYMBOL_for_cond = 81,                  /* for_cond  */
  YYSYMBOL_for_sec = 82,                   /* for_sec  */
  YYSYMBOL_for_iter = 83,                  /* for_iter  */
  YYSYMBOL_while_exp = 84,                 /* while_exp  */
  YYSYMBOL_conditional = 85,               /* conditional  */
  YYSYMBOL_if_els_stmt = 86,               /* if_els_stmt  */
  YYSYMBOL_if_stmt = 87,                   /* if_stmt  */
  YYSYMBOL_88_2 = 88,                      /* $@2  */
  YYSYMBOL_else_stmt = 89,                 /* else_stmt  */
  YYSYMBOL_els_if_stmt = 90,               /* els_if_stmt  */
  YYSYMBOL_switch_stmt = 91,               /* switch_stmt  */
  YYSYMBOL_92_3 = 92,                      /* $@3  */
  YYSYMBOL_switch_block = 93,              /* switch_block  */
  YYSYMBOL_switch_line = 94,               /* switch_line  */
  YYSYMBOL_95_4 = 95,                      /* $@4  */
  YYSYMBOL_96_5 = 96,                      /* $@5  */
  YYSYMBOL_exception = 97,                 /* exception  */
  YYSYMBOL_try_catch = 98,                 /* try_catch  */
  YYSYMBOL_99_6 = 99,                      /* $@6  */
  YYSYMBOL_100_7 = 100,                    /* $@7  */
  YYSYMBOL_func_type = 101,                /* func_type  */
  YYSYMBOL_func_params = 102,              /* func_params  */
  YYSYMBOL_params_sec = 103,               /* params_sec  */
  YYSYMBOL_param = 104,                    /* param  */
  YYSYMBOL_instance = 105,                 /* instance  */
  YYSYMBOL_inst_id = 106,                  /* inst_id  */
  YYSYMBOL_type = 107,                     /* type  */
  YYSYMBOL_value_data = 108,               /* value_data  */
  YYSYMBOL_var_value = 109,                /* var_value  */
  YYSYMBOL_exp_op = 110,                   /* exp_op  */
  YYSYMBOL_inc_dec = 111,                  /* inc_dec  */
  YYSYMBOL_ops_inc_dec = 112,              /* ops_inc_dec  */
  YYSYMBOL_func_call = 113,                /* func_call  */
  YYSYMBOL_func_args = 114,                /* func_args  */
  YYSYMBOL_func_arg = 115,                 /* func_arg  */
  YYSYMBOL_asingn = 116,                   /* asingn  */
  YYSYMBOL_ops_asingn = 117                /* ops_asingn  */
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
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   253,   253,   253,   255,   255,   255,   257,   259,   259,
     259,   259,   261,   261,   261,   261,   263,   270,   270,   272,
     274,   274,   276,   276,   278,   278,   278,   278,   278,   278,
     278,   278,   279,   294,   296,   296,   298,   298,   300,   301,
     302,   304,   306,   306,   308,   316,   324,   324,   326,   326,
     328,   335,   335,   337,   337,   337,   339,   339,   346,   348,
     348,   348,   350,   350,   355,   357,   357,   369,   369,   370,
     370,   380,   380,   382,   382,   382,   384,   384,   386,   386,
     388,   388,   388,   390,   390,   398,   398,   408,   410,   411,
     412,   413,   414,   416,   417,   418,   419,   420,   421,   422,
     424,   425,   427,   448,   456,   464,   477,   490,   498,   506,
     514,   522,   530,   538,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   563,   565,   565,   567,
     567,   569,   570,   572,   572,   572,   574,   574,   576,   577,
     578,   580,   580,   580,   580
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
  "OP_NOT", "UMINUS", "THROW_KW", "OP_INC", "OP_DEC", "LEFT_PARENT",
  "RIGHT_PARENT", "LEFT_BRACKET", "RIGHT_BRACKET", "COMMA", "D_COLON",
  "COLON", "FOR_KW", "WHILE_KW", "DO_KW", "BREAK_KW", "RETURN_KW",
  "TRUE_KW", "FALSE_KW", "FUNCTION_KW", "TRY_KW", "CATCH_KW", "FINALLY_KW",
  "CHAR_KW", "INT_KW", "FLOAT_KW", "BOOL_KW", "STRING_KW", "VOID_KW",
  "IF_KW", "ELSE_KW", "SWITCH_KW", "CASE_KW", "DEFAULT_KW", "CHAR",
  "STRING", "NUM", "NUM_DEC", "IDENTIFIER", "EOL", "$accept", "in", "line",
  "n_line", "exp", "exp_wth_bl", "func", "std_block_d", "$@1", "func_dec",
  "block", "block_line", "block_exp", "rtrn", "throw_dec", "loop",
  "for_decl", "for_vrs_dec", "for_var", "for_cond", "for_sec", "for_iter",
  "while_exp", "conditional", "if_els_stmt", "if_stmt", "$@2", "else_stmt",
  "els_if_stmt", "switch_stmt", "$@3", "switch_block", "switch_line",
  "$@4", "$@5", "exception", "try_catch", "$@6", "$@7", "func_type",
  "func_params", "params_sec", "param", "instance", "inst_id", "type",
  "value_data", "var_value", "exp_op", "inc_dec", "ops_inc_dec",
  "func_call", "func_args", "func_arg", "asingn", "ops_asingn", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -173,    14,  -173,  -173,  -173,   -40,   -12,    27,    12,    -7,
      39,  -173,  -173,  -173,  -173,  -173,    51,    55,    56,  -173,
    -173,  -173,    42,  -173,  -173,    12,  -173,    12,  -173,  -173,
      54,  -173,  -173,    63,  -173,   118,    62,   105,  -173,    -9,
    -173,  -173,  -173,    65,   230,  -173,    88,    99,  -173,   230,
     230,   156,  -173,  -173,  -173,    -4,  -173,    80,    12,   230,
    -173,   230,   230,  -173,  -173,  -173,  -173,  -173,   230,  -173,
    -173,   130,   107,   106,   114,   230,   230,   230,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   214,   418,  -173,  -173,  -173,
    -173,   -15,   115,  -173,   478,   438,  -173,    -3,   478,   110,
     119,  -173,  -173,    -4,  -173,  -173,   478,   478,   478,   478,
     230,    12,   230,    65,  -173,  -173,   458,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,  -173,   278,  -173,   116,
     123,   122,   161,  -173,   310,   128,   144,   230,  -173,   102,
    -173,   478,  -173,   124,   478,  -173,  -173,   478,   478,   478,
     478,   478,   478,   404,   404,   151,   151,    98,    98,    98,
      98,    52,    52,  -173,  -173,  -173,   117,  -173,  -173,   230,
    -173,  -173,    42,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,   185,  -173,   -29,  -173,  -173,  -173,    12,    42,
     478,   241,  -173,    44,   148,   478,  -173,   173,   120,  -173,
     136,  -173,   -21,  -173,  -173,   154,  -173,  -173,   -20,   230,
    -173,   162,  -173,   230,   158,    26,  -173,    44,  -173,   165,
     478,   134,   393,  -173,   167,  -173,  -173,  -173,   170,  -173,
    -173,  -173,    12,  -173,   340,  -173,   340
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   129,   130,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,     0,     0,   100,     7,
       3,     4,     0,     6,    15,     0,    12,     0,    13,    51,
      53,    52,    14,    71,     8,    85,     0,     0,     9,     0,
      10,    11,   101,     0,     0,    17,     0,     0,    73,     0,
       0,     0,     5,    16,    39,     0,    54,    55,     0,     0,
      87,     0,     0,   141,   142,   143,   144,   127,     0,   100,
     128,     0,     0,     0,    42,     0,     0,     0,    96,    97,
      93,    98,    94,    95,   124,    99,     0,   126,   125,    20,
      40,     0,     0,    20,    56,     0,   131,   100,   137,     0,
     133,    58,    59,     0,    61,    72,    86,   138,   139,   140,
       0,     0,     0,     0,   107,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    79,     0,
       0,    80,     0,    19,     0,     0,     0,     0,   132,     0,
      60,    44,    38,     0,    45,    43,   123,   117,   118,   119,
     120,   121,   122,   114,   115,   112,   113,   108,   109,   110,
     111,   102,   103,   104,   105,   106,     0,    18,    25,    35,
      22,    21,     0,    32,    33,    29,    30,    31,    24,    26,
      27,    28,     0,    78,     0,    77,    76,    74,     0,     0,
     136,     0,   134,     0,     0,    34,    23,    83,     0,    81,
       0,    57,     0,   135,    41,    46,    48,    49,     0,     0,
      82,     0,    64,     0,     0,    62,    65,     0,    37,     0,
      84,     0,     0,    69,     0,    66,    47,    36,     0,    67,
      20,    63,     0,    20,    70,    75,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,     5,  -173,  -173,  -173,    -6,  -173,  -173,
     -88,  -173,  -173,  -173,  -173,   199,  -173,   111,  -173,  -173,
     -26,  -173,   177,   224,  -173,   -45,  -173,   171,  -173,  -173,
    -173,  -173,    10,  -173,  -173,   236,  -173,  -173,  -173,  -173,
    -173,  -172,  -173,   237,  -173,  -135,  -173,    -1,   -33,     0,
     -19,     3,  -137,  -173,     2,  -173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,   180,    22,    23,    24,   101,    89,    25,
     137,   181,   182,   183,   184,   185,    72,    73,    74,   153,
     214,   215,    27,   186,    29,    30,   145,    56,    57,    31,
     234,   225,   226,   243,   240,   187,    33,    93,   210,   143,
      92,   140,   141,   188,    35,    36,    84,    85,    98,    87,
      39,    88,    99,   100,   191,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    38,    46,    41,    40,   144,    21,   196,   228,   222,
     102,    86,   202,   138,     2,    43,    94,    95,    67,    53,
      42,    54,   209,     5,    51,    45,   106,    52,   107,   108,
     147,   139,    19,   223,   224,   109,   220,   229,    70,     3,
       4,    45,   114,   115,   116,   139,     5,    16,     6,     7,
       8,    69,   105,    47,    44,     9,    10,   207,   150,    11,
      12,    13,    14,    15,   213,    16,    67,    17,    48,     3,
       4,   133,   134,   135,    18,    19,     5,   151,    49,   154,
     223,   224,    50,    51,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    19,    69,   152,    55,    58,    61,    62,
      63,    64,    65,    66,   200,   131,   132,   133,   134,   135,
      75,    59,    60,     7,    76,    71,    91,     3,     4,    77,
       3,     4,   103,   110,     5,   111,    37,   189,   148,   112,
     190,    78,    79,    37,   189,   113,   205,   190,   142,   192,
     149,   193,   244,   194,   201,   246,   198,   203,    80,    81,
      82,    83,    97,    19,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   199,    75,   218,   219,   204,    76,   221,
     139,     3,     4,    77,    96,   227,   230,   206,     5,   231,
     232,   233,   211,   237,   238,    78,    79,   241,   242,   208,
      26,   236,    37,   216,   212,   217,    11,    12,    13,    14,
      15,   195,    80,    81,    82,    83,    97,   117,   118,   119,
     120,   121,   122,    90,   155,    28,    37,   216,   104,   217,
      11,    12,    13,    14,    15,   235,   245,    32,    34,     3,
       4,     0,     0,    37,   189,    37,   189,   190,    75,   190,
       0,     0,    76,     0,     0,     3,     4,    77,     0,    75,
       0,     0,     5,    76,     0,     0,     3,     4,    77,    78,
      79,     0,     0,     5,     0,     0,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,    80,    81,    82,    83,
      18,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    97,   176,     3,     4,     0,     0,     0,   177,     0,
       5,     0,     6,     7,     8,   178,   179,     0,     0,     0,
      10,     0,     0,    11,    12,    13,    14,    15,     0,    16,
       0,    17,     0,     0,   176,     3,     4,     0,    18,    19,
     197,     0,     5,     0,     6,     7,     8,   178,   179,     0,
       0,     0,    10,     0,     0,    11,    12,    13,    14,    15,
       0,    16,     0,    17,   176,     3,     4,     0,     0,     0,
      18,    19,     5,     0,     6,     7,     8,   178,   179,     0,
       0,     0,    10,     0,     0,    11,    12,    13,    14,    15,
       0,    16,     0,    17,     0,     0,     0,     0,     0,     0,
      18,    19,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   239,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,   136,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,   146,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,   156,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135
};

static const yytype_int16 yycheck[] =
{
       1,     1,     8,     1,     1,    93,     1,   142,    28,    30,
      55,    44,   149,    28,     0,    27,    49,    50,    37,    25,
      60,    27,   194,    32,    27,    29,    59,    22,    61,    62,
      33,    60,    61,    54,    55,    68,   208,    57,    39,    25,
      26,    29,    75,    76,    77,    60,    32,    51,    34,    35,
      36,    60,    58,    60,    27,    41,    42,   192,   103,    45,
      46,    47,    48,    49,   201,    51,    85,    53,    29,    25,
      26,    19,    20,    21,    60,    61,    32,   110,    27,   112,
      54,    55,    27,    27,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    61,    60,   111,    52,    44,     3,     4,
       5,     6,     7,     8,   147,    17,    18,    19,    20,    21,
      18,     3,    60,    35,    22,    60,    27,    25,    26,    27,
      25,    26,    52,     3,    32,    28,   137,   137,    28,    33,
     137,    39,    40,   144,   144,    31,   179,   144,    33,    33,
      31,    28,   240,    31,   149,   243,    28,    33,    56,    57,
      58,    59,    60,    61,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    29,    18,    27,     3,    60,    22,    43,
      60,    25,    26,    27,    28,    31,   219,   182,    32,    27,
     223,    33,   198,    28,    60,    39,    40,    30,    28,   194,
       1,   227,   203,   203,   199,   203,    45,    46,    47,    48,
      49,    50,    56,    57,    58,    59,    60,     3,     4,     5,
       6,     7,     8,    46,   113,     1,   227,   227,    57,   227,
      45,    46,    47,    48,    49,   225,   242,     1,     1,    25,
      26,    -1,    -1,   244,   244,   246,   246,   244,    18,   246,
      -1,    -1,    22,    -1,    -1,    25,    26,    27,    -1,    18,
      -1,    -1,    32,    22,    -1,    -1,    25,    26,    27,    39,
      40,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      32,    -1,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    -1,    -1,    45,    46,    47,    48,    49,    -1,    51,
      -1,    53,    -1,    -1,    24,    25,    26,    -1,    60,    61,
      30,    -1,    32,    -1,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    51,    -1,    53,    24,    25,    26,    -1,    -1,    -1,
      60,    61,    32,    -1,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    33,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,    25,    26,    32,    34,    35,    36,    41,
      42,    45,    46,    47,    48,    49,    51,    53,    60,    61,
      64,    65,    66,    67,    68,    71,    77,    84,    85,    86,
      87,    91,    97,    98,   105,   106,   107,   109,   111,   112,
     113,   116,    60,    27,    27,    29,    69,    60,    29,    27,
      27,    27,    65,    69,    69,    52,    89,    90,    44,     3,
      60,     3,     4,     5,     6,     7,     8,   112,   117,    60,
     109,    60,    78,    79,    80,    18,    22,    27,    39,    40,
      56,    57,    58,    59,   108,   109,   110,   111,   113,    70,
      84,    27,   102,    99,   110,   110,    28,    60,   110,   114,
     115,    69,    87,    52,    89,    69,   110,   110,   110,   110,
       3,    28,    33,    31,   110,   110,   110,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    28,    72,    28,    60,
     103,   104,    33,   101,    72,    88,    28,    33,    28,    31,
      87,   110,    69,    81,   110,    79,    28,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,    24,    30,    37,    38,
      65,    73,    74,    75,    76,    77,    85,    97,   105,   111,
     113,   116,    33,    28,    31,    50,   107,    30,    28,    29,
     110,    65,   114,    33,    60,   110,    65,   107,    65,   103,
     100,    69,    65,   114,    82,    83,   111,   116,    27,     3,
     103,    43,    30,    54,    55,    93,    94,    31,    28,    57,
     110,    27,   110,    33,    92,    94,    82,    28,    60,    33,
      96,    30,    28,    95,    72,    69,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    70,    69,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    78,    79,    79,    80,    81,    82,    82,    83,    83,
      84,    85,    85,    86,    86,    86,    88,    87,    89,    90,
      90,    90,    92,    91,    91,    93,    93,    95,    94,    96,
      94,    97,    97,    99,   100,    98,   101,   101,   102,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   107,   107,
     107,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     116,   117,   117,   117,   117
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
       4,     1,     3,     0,     0,    11,     2,     2,     3,     2,
       1,     3,     4,     3,     5,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     2,     1,
       1,     3,     4,     1,     3,     4,     3,     1,     3,     3,
       3,     1,     1,     1,     1
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
#line 257 "sintax_analizer.y"
                    { lineNumber++; }
#line 1632 "sintax_analizer.tab.c"
    break;

  case 16: /* func: func_dec std_block_d  */
#line 263 "sintax_analizer.y"
                                     {
    if (functType != -1 && !hasReturn) {
        printf("Missing return error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1643 "sintax_analizer.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 270 "sintax_analizer.y"
                             { initBlock(); }
#line 1649 "sintax_analizer.tab.c"
    break;

  case 18: /* std_block_d: LEFT_BRACKET $@1 block RIGHT_BRACKET  */
#line 270 "sintax_analizer.y"
                                                                  { endBlock(); }
#line 1655 "sintax_analizer.tab.c"
    break;

  case 19: /* func_dec: FUNCTION_KW IDENTIFIER func_params func_type  */
#line 272 "sintax_analizer.y"
                                                             { addSymb((yyvsp[-2].sval), (yyvsp[0].ival), true); }
#line 1661 "sintax_analizer.tab.c"
    break;

  case 32: /* block_exp: rtrn  */
#line 279 "sintax_analizer.y"
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
#line 1682 "sintax_analizer.tab.c"
    break;

  case 34: /* rtrn: RETURN_KW exp_op  */
#line 296 "sintax_analizer.y"
                                 { (yyval.ival) = (yyvsp[0].sdata).type; }
#line 1688 "sintax_analizer.tab.c"
    break;

  case 35: /* rtrn: RETURN_KW  */
#line 296 "sintax_analizer.y"
                                                               { (yyval.ival) = -1; }
#line 1694 "sintax_analizer.tab.c"
    break;

  case 44: /* for_var: IDENTIFIER OP_ASSIGN exp_op  */
#line 308 "sintax_analizer.y"
                                            {
    if ((yyvsp[0].sdata).type != 2 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: the variable used in for iteration is not a int value\n", 
            lineNumber);
    }
    addForNumber((yyvsp[-2].sval));
}
#line 1706 "sintax_analizer.tab.c"
    break;

  case 45: /* for_cond: exp_op  */
#line 316 "sintax_analizer.y"
                       {
    if((yyvsp[0].sdata).type != 4 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition used in for iteration is not a bool value\n", 
            lineNumber);
        hasErrors = true;
    }
}
#line 1718 "sintax_analizer.tab.c"
    break;

  case 50: /* while_exp: WHILE_KW LEFT_PARENT exp_op RIGHT_PARENT  */
#line 328 "sintax_analizer.y"
                                                         {
    if ((yyvsp[-1].sdata).type != 4 && (yyvsp[-1].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1729 "sintax_analizer.tab.c"
    break;

  case 56: /* $@2: %empty  */
#line 339 "sintax_analizer.y"
                                         {
    if ((yyvsp[0].sdata).type != 4 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1740 "sintax_analizer.tab.c"
    break;

  case 62: /* $@3: %empty  */
#line 350 "sintax_analizer.y"
                                                                                           {
    if ((yyvsp[-4].sdata).type != (yyvsp[0].ival) && (yyvsp[0].ival) != 0 && (yyvsp[-4].sdata).type != 0) {
        printf("Incompatible type error at line %d: the cases type are not compatible with the switch value type\n", lineNumber);
        hasErrors = true;
    }
}
#line 1751 "sintax_analizer.tab.c"
    break;

  case 63: /* switch_stmt: SWITCH_KW LEFT_PARENT exp_op RIGHT_PARENT LEFT_BRACKET n_line switch_block $@3 RIGHT_BRACKET  */
#line 355 "sintax_analizer.y"
                { hasDefaultCase = false; }
#line 1757 "sintax_analizer.tab.c"
    break;

  case 65: /* switch_block: switch_line  */
#line 357 "sintax_analizer.y"
                            { (yyval.ival) = (yyvsp[0].ival) == -1 ? 0 : (yyvsp[0].ival); }
#line 1763 "sintax_analizer.tab.c"
    break;

  case 66: /* switch_block: switch_block switch_line  */
#line 357 "sintax_analizer.y"
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
#line 1779 "sintax_analizer.tab.c"
    break;

  case 67: /* $@4: %empty  */
#line 369 "sintax_analizer.y"
                                     { initBlock(); }
#line 1785 "sintax_analizer.tab.c"
    break;

  case 68: /* switch_line: CASE_KW exp_op COLON $@4 block  */
#line 369 "sintax_analizer.y"
                                                            { endBlock(); (yyval.ival) = (yyvsp[-3].sdata).type; }
#line 1791 "sintax_analizer.tab.c"
    break;

  case 69: /* $@5: %empty  */
#line 370 "sintax_analizer.y"
                                 { initBlock(); }
#line 1797 "sintax_analizer.tab.c"
    break;

  case 70: /* switch_line: DEFAULT_KW COLON $@5 block  */
#line 370 "sintax_analizer.y"
                                                        {
    endBlock();
    if (hasDefaultCase) {
        printf("Definition error at line %d: the switch has more than one default case\n", lineNumber);
        hasErrors = true;
    }
    hasDefaultCase = true;
    (yyval.ival) = -1;
}
#line 1811 "sintax_analizer.tab.c"
    break;

  case 73: /* $@6: %empty  */
#line 382 "sintax_analizer.y"
                                    { isInException = true; initBlock(); }
#line 1817 "sintax_analizer.tab.c"
    break;

  case 74: /* $@7: %empty  */
#line 382 "sintax_analizer.y"
                                                                                               { isInException = false; endBlock(); }
#line 1823 "sintax_analizer.tab.c"
    break;

  case 76: /* func_type: COLON type  */
#line 384 "sintax_analizer.y"
                           { functType = (yyvsp[0].ival); hasReturn = false; (yyval.ival) = (yyvsp[0].ival); }
#line 1829 "sintax_analizer.tab.c"
    break;

  case 77: /* func_type: COLON VOID_KW  */
#line 384 "sintax_analizer.y"
                                                                                           { functType = -1; (yyval.ival) = -1; }
#line 1835 "sintax_analizer.tab.c"
    break;

  case 83: /* param: IDENTIFIER COLON type  */
#line 390 "sintax_analizer.y"
                                      { addFunctionParam((yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 1841 "sintax_analizer.tab.c"
    break;

  case 84: /* param: IDENTIFIER COLON type OP_ASSIGN exp_op  */
#line 390 "sintax_analizer.y"
                                                                                                             {
    addFunctionParam((yyvsp[-4].sval), (yyvsp[-2].ival));
    if ((yyvsp[0].sdata).type != (yyvsp[-2].ival) && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: data value of parameter %s is not compatible with data type\n",lineNumber, (yyvsp[-4].sval));
        hasErrors = true;
    }
}
#line 1853 "sintax_analizer.tab.c"
    break;

  case 86: /* instance: inst_id OP_ASSIGN exp_op  */
#line 398 "sintax_analizer.y"
                                                   {
    if ((yyvsp[-2].ival) == 5 && (yyvsp[0].sdata).type != 5 && (yyvsp[0].sdata).type != 1 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber);
        hasErrors = true;
    } else if ((yyvsp[-2].ival) != (yyvsp[0].sdata).type && (yyvsp[-2].ival) != 5 && (yyvsp[0].sdata).type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber);
        hasErrors = true;
    }
}
#line 1867 "sintax_analizer.tab.c"
    break;

  case 87: /* inst_id: type IDENTIFIER  */
#line 408 "sintax_analizer.y"
                                { addSymb((yyvsp[0].sval), (yyvsp[-1].ival), false); (yyval.ival) = (yyvsp[-1].ival); }
#line 1873 "sintax_analizer.tab.c"
    break;

  case 88: /* type: CHAR_KW  */
#line 410 "sintax_analizer.y"
                            { (yyval.ival) = 1; }
#line 1879 "sintax_analizer.tab.c"
    break;

  case 89: /* type: INT_KW  */
#line 411 "sintax_analizer.y"
                            { (yyval.ival) = 2; }
#line 1885 "sintax_analizer.tab.c"
    break;

  case 90: /* type: FLOAT_KW  */
#line 412 "sintax_analizer.y"
                            { (yyval.ival) = 3; }
#line 1891 "sintax_analizer.tab.c"
    break;

  case 91: /* type: BOOL_KW  */
#line 413 "sintax_analizer.y"
                            { (yyval.ival) = 4; }
#line 1897 "sintax_analizer.tab.c"
    break;

  case 92: /* type: STRING_KW  */
#line 414 "sintax_analizer.y"
                            { (yyval.ival) = 5; }
#line 1903 "sintax_analizer.tab.c"
    break;

  case 93: /* value_data: CHAR  */
#line 416 "sintax_analizer.y"
                            { (yyval.sdata).type = 1; (yyval.sdata).hasVal = 0; }
#line 1909 "sintax_analizer.tab.c"
    break;

  case 94: /* value_data: NUM  */
#line 417 "sintax_analizer.y"
                            { (yyval.sdata).type = 2; (yyval.sdata).hasVal = 1; (yyval.sdata).val = (yyvsp[0].dval); }
#line 1915 "sintax_analizer.tab.c"
    break;

  case 95: /* value_data: NUM_DEC  */
#line 418 "sintax_analizer.y"
                            { (yyval.sdata).type = 3; (yyval.sdata).hasVal = 1; (yyval.sdata).val = (yyvsp[0].dval); }
#line 1921 "sintax_analizer.tab.c"
    break;

  case 96: /* value_data: TRUE_KW  */
#line 419 "sintax_analizer.y"
                            { (yyval.sdata).type = 4; (yyval.sdata).hasVal = 0; }
#line 1927 "sintax_analizer.tab.c"
    break;

  case 97: /* value_data: FALSE_KW  */
#line 420 "sintax_analizer.y"
                            { (yyval.sdata).type = 4; (yyval.sdata).hasVal = 0; }
#line 1933 "sintax_analizer.tab.c"
    break;

  case 98: /* value_data: STRING  */
#line 421 "sintax_analizer.y"
                            { (yyval.sdata).type = 5; (yyval.sdata).hasVal = 0; }
#line 1939 "sintax_analizer.tab.c"
    break;

  case 99: /* value_data: var_value  */
#line 422 "sintax_analizer.y"
                            { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0; }
#line 1945 "sintax_analizer.tab.c"
    break;

  case 100: /* var_value: IDENTIFIER  */
#line 424 "sintax_analizer.y"
                            { (yyval.ival) = getSymbType((yyvsp[0].sval), false); }
#line 1951 "sintax_analizer.tab.c"
    break;

  case 101: /* var_value: D_COLON IDENTIFIER  */
#line 425 "sintax_analizer.y"
                                   { (yyval.ival) = getGlobalSymbType((yyvsp[0].sval)); }
#line 1957 "sintax_analizer.tab.c"
    break;

  case 102: /* exp_op: exp_op OP_ADD exp_op  */
#line 427 "sintax_analizer.y"
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
#line 1983 "sintax_analizer.tab.c"
    break;

  case 103: /* exp_op: exp_op OP_SUB exp_op  */
#line 448 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val - (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 1996 "sintax_analizer.tab.c"
    break;

  case 104: /* exp_op: exp_op OP_MUL exp_op  */
#line 456 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = (yyvsp[-2].sdata).val * (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2009 "sintax_analizer.tab.c"
    break;

  case 105: /* exp_op: exp_op OP_DIV exp_op  */
#line 464 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val != 0) {
            (yyval.sdata).hasVal = 1;
            (yyval.sdata).val = (yyvsp[-2].sdata).val / (yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
    if((yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val == 0 && !isInException) {
        printf("Logical error at line %d: division by zero\n", lineNumber);
        hasErrors = true;
        (yyval.sdata).hasVal = 0;
    }
}
#line 2027 "sintax_analizer.tab.c"
    break;

  case 106: /* exp_op: exp_op OP_MOD exp_op  */
#line 477 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkNumsOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val != 0) {
            (yyval.sdata).hasVal = 1;
            (yyval.sdata).val = fmod((yyvsp[-2].sdata).val,(yyvsp[0].sdata).val);
    } else {
        (yyval.sdata).hasVal = 0;
    }
    if((yyvsp[0].sdata).hasVal && (yyvsp[0].sdata).val == 0 && !isInException) {
        printf("Logical error at line %d: division by zero on module operation\n", lineNumber);
        hasErrors = true;
        (yyval.sdata).hasVal = 0;
    }
}
#line 2045 "sintax_analizer.tab.c"
    break;

  case 107: /* exp_op: OP_SUB exp_op  */
#line 490 "sintax_analizer.y"
                                           { (yyval.sdata).type = checkNumsOperation((yyvsp[0].sdata).type, (yyvsp[0].sdata).type);
    if((yyvsp[0].sdata).hasVal) {
        (yyval.sdata).hasVal = 1;
        (yyval.sdata).val = -(yyvsp[0].sdata).val;
    } else {
        (yyval.sdata).hasVal = 0;
    }
}
#line 2058 "sintax_analizer.tab.c"
    break;

  case 108: /* exp_op: exp_op OP_GT exp_op  */
#line 498 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && !isInException) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f > %.*f is always %s\n", lineNumber, dec1, (yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val > (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2071 "sintax_analizer.tab.c"
    break;

  case 109: /* exp_op: exp_op OP_LT exp_op  */
#line 506 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && !isInException) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f < %.*f is always %s\n", lineNumber, dec1, (yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val < (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2084 "sintax_analizer.tab.c"
    break;

  case 110: /* exp_op: exp_op OP_GTE exp_op  */
#line 514 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && !isInException) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f >= %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val >= (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2097 "sintax_analizer.tab.c"
    break;

  case 111: /* exp_op: exp_op OP_LTE exp_op  */
#line 522 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && !isInException) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f <= %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val <= (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2110 "sintax_analizer.tab.c"
    break;

  case 112: /* exp_op: exp_op OP_EQ exp_op  */
#line 530 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkValuesComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && !isInException) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f == %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val == (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2123 "sintax_analizer.tab.c"
    break;

  case 113: /* exp_op: exp_op OP_NEQ exp_op  */
#line 538 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkValuesComparison((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0;
    if((yyvsp[-2].sdata).hasVal && (yyvsp[0].sdata).hasVal && !isInException) {
        int dec1 = (yyvsp[-2].sdata).type == 2 ? 0 : 7;
        int dec2 = (yyvsp[0].sdata).type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f != %.*f is always %s\n", lineNumber, dec1,(yyvsp[-2].sdata).val, dec2, (yyvsp[0].sdata).val, (yyvsp[-2].sdata).val != (yyvsp[0].sdata).val ? "true" : "false");
        hasErrors = true;
    }
}
#line 2136 "sintax_analizer.tab.c"
    break;

  case 114: /* exp_op: exp_op OP_AND exp_op  */
#line 546 "sintax_analizer.y"
                                     { (yyval.sdata).type = checkLogicOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2142 "sintax_analizer.tab.c"
    break;

  case 115: /* exp_op: exp_op OP_OR exp_op  */
#line 547 "sintax_analizer.y"
                                    { (yyval.sdata).type = checkLogicOperation((yyvsp[-2].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2148 "sintax_analizer.tab.c"
    break;

  case 116: /* exp_op: OP_NOT exp_op  */
#line 548 "sintax_analizer.y"
                              { (yyval.sdata).type = checkLogicOperation((yyvsp[0].sdata).type, (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2154 "sintax_analizer.tab.c"
    break;

  case 117: /* exp_op: var_value OP_ASSIGN exp_op  */
#line 549 "sintax_analizer.y"
                                           { (yyval.sdata).type = singleAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2160 "sintax_analizer.tab.c"
    break;

  case 118: /* exp_op: var_value OP_ADD_ASSIGN exp_op  */
#line 550 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2166 "sintax_analizer.tab.c"
    break;

  case 119: /* exp_op: var_value OP_SUB_ASSIGN exp_op  */
#line 551 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2172 "sintax_analizer.tab.c"
    break;

  case 120: /* exp_op: var_value OP_MUL_ASSIGN exp_op  */
#line 552 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2178 "sintax_analizer.tab.c"
    break;

  case 121: /* exp_op: var_value OP_DIV_ASSIGN exp_op  */
#line 553 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2184 "sintax_analizer.tab.c"
    break;

  case 122: /* exp_op: var_value OP_MOD_ASSIGN exp_op  */
#line 554 "sintax_analizer.y"
                                               { (yyval.sdata).type = checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); (yyval.sdata).hasVal=0; }
#line 2190 "sintax_analizer.tab.c"
    break;

  case 123: /* exp_op: LEFT_PARENT exp_op RIGHT_PARENT  */
#line 555 "sintax_analizer.y"
                                                { (yyval.sdata).type = (yyvsp[-1].sdata).type; (yyval.sdata).hasVal=(yyvsp[-1].sdata).hasVal; if((yyvsp[-1].sdata).hasVal) { (yyval.sdata).val = (yyvsp[-1].sdata).val; } }
#line 2196 "sintax_analizer.tab.c"
    break;

  case 124: /* exp_op: value_data  */
#line 556 "sintax_analizer.y"
                           { (yyval.sdata).type = (yyvsp[0].sdata).type; (yyval.sdata).hasVal = (yyvsp[0].sdata).hasVal; if((yyvsp[0].sdata).hasVal) { (yyval.sdata).val = (yyvsp[0].sdata).val; }; }
#line 2202 "sintax_analizer.tab.c"
    break;

  case 125: /* exp_op: func_call  */
#line 557 "sintax_analizer.y"
                          { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0;
    if ((yyvsp[0].ival) == -1) {
        printf("Incompatible type error at line %d: the function called has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 2213 "sintax_analizer.tab.c"
    break;

  case 126: /* exp_op: inc_dec  */
#line 563 "sintax_analizer.y"
                        { (yyval.sdata).type = (yyvsp[0].ival); (yyval.sdata).hasVal = 0; }
#line 2219 "sintax_analizer.tab.c"
    break;

  case 127: /* inc_dec: var_value ops_inc_dec  */
#line 565 "sintax_analizer.y"
                                      { (yyval.ival) = checkIncrementDecrement((yyvsp[-1].ival)); }
#line 2225 "sintax_analizer.tab.c"
    break;

  case 128: /* inc_dec: ops_inc_dec var_value  */
#line 565 "sintax_analizer.y"
                                                                                                    { (yyval.ival) = checkIncrementDecrement((yyvsp[0].ival)); }
#line 2231 "sintax_analizer.tab.c"
    break;

  case 131: /* func_call: IDENTIFIER LEFT_PARENT RIGHT_PARENT  */
#line 569 "sintax_analizer.y"
                                                    { (yyval.ival) = getSymbType((yyvsp[-2].sval), true); }
#line 2237 "sintax_analizer.tab.c"
    break;

  case 132: /* func_call: IDENTIFIER LEFT_PARENT func_args RIGHT_PARENT  */
#line 570 "sintax_analizer.y"
                                                              { (yyval.ival) = getSymbType((yyvsp[-3].sval), true); }
#line 2243 "sintax_analizer.tab.c"
    break;

  case 138: /* asingn: var_value OP_ASSIGN exp_op  */
#line 576 "sintax_analizer.y"
                                           { singleAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2249 "sintax_analizer.tab.c"
    break;

  case 139: /* asingn: var_value OP_ADD_ASSIGN exp_op  */
#line 577 "sintax_analizer.y"
                                               { checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2255 "sintax_analizer.tab.c"
    break;

  case 140: /* asingn: var_value ops_asingn exp_op  */
#line 578 "sintax_analizer.y"
                                            { checkAsignation((yyvsp[-2].ival), (yyvsp[0].sdata).type); }
#line 2261 "sintax_analizer.tab.c"
    break;


#line 2265 "sintax_analizer.tab.c"

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

#line 581 "sintax_analizer.y"


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
