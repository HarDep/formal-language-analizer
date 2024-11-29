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
    if (a <= 1 || a >= 4|| b <= 1 || b >= 4) {
        printf("Logical error at line %d: invalid operation expression, the values must be int or float\n", lineNumber);
        hasErrors = true;
        return 0;
    }
    return a == 3 || b == 3 ? 3 : 2;
}
int checkComparison(int a, int b) {
    if (a <= 1 || a >= 4|| b <= 1 || b >= 4) {
        printf("Logical error at line %d: invalid comparison expression, the values must be int or float\n", lineNumber);
        hasErrors = true;
    }
    return 4;
}
int checkValuesComparison(int a, int b) {
    if (a == b) {
        return 4;
    }
    if (a == 5 || b == 5) {
        return 4;
    }
    if ((a == 2 && b == 3) || (a == 3 && b == 2)) {
        return 4;
    }
    printf("Logical error at line %d: invalid comparison expression, incompatible type comparation\n", lineNumber);
    hasErrors = true;
    return 4;
}
int checkAsignation(int a, int b) {
    if (a != b && (a != 3 || a != 2)) {
        printf("Incompatible type error at line %d: unsoported assignment expression, both values must be the same type, and the type must be int or float\n",
            lineNumber);
        hasErrors = true;
        return 0;
    }
    return a;
}
int singleAsignation(int a, int b) {
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
    if (a != 4 || b != 4) {
        printf("Logical error at line %d: invalid logic operation expression, the values must be bool\n", lineNumber);
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
    printf("Definition error at line %d: %s %s is not defined\n", lineNumber, isFunc ? "function" : "variable", name);
    hasErrors = true;
    return 0;
}
int getGlobalSymbType(char* name) {
    for (int i = 0; i < symCount; i++) {
        if (strcmp(name, syms[i].name) == 0 && syms[i].scopeLevel == 0 && !syms[i].isFunc) {
            return syms[i].type;
        }
    }
    printf("Definition error at line %d: global variable %s is not defined\n", lineNumber, name);
    hasErrors = true;
    return 0;
}
int checkIncrementDecrement(int type) {
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

#line 260 "sintax_analizer.tab.c"

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
  YYSYMBOL_CHAR_KW = 3,                    /* CHAR_KW  */
  YYSYMBOL_INT_KW = 4,                     /* INT_KW  */
  YYSYMBOL_FLOAT_KW = 5,                   /* FLOAT_KW  */
  YYSYMBOL_BOOL_KW = 6,                    /* BOOL_KW  */
  YYSYMBOL_STRING_KW = 7,                  /* STRING_KW  */
  YYSYMBOL_VOID_KW = 8,                    /* VOID_KW  */
  YYSYMBOL_IF_KW = 9,                      /* IF_KW  */
  YYSYMBOL_ELSE_KW = 10,                   /* ELSE_KW  */
  YYSYMBOL_SWITCH_KW = 11,                 /* SWITCH_KW  */
  YYSYMBOL_CASE_KW = 12,                   /* CASE_KW  */
  YYSYMBOL_DEFAULT_KW = 13,                /* DEFAULT_KW  */
  YYSYMBOL_FOR_KW = 14,                    /* FOR_KW  */
  YYSYMBOL_WHILE_KW = 15,                  /* WHILE_KW  */
  YYSYMBOL_DO_KW = 16,                     /* DO_KW  */
  YYSYMBOL_BREAK_KW = 17,                  /* BREAK_KW  */
  YYSYMBOL_RETURN_KW = 18,                 /* RETURN_KW  */
  YYSYMBOL_TRUE_KW = 19,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 20,                  /* FALSE_KW  */
  YYSYMBOL_FUNCTION_KW = 21,               /* FUNCTION_KW  */
  YYSYMBOL_TRY_KW = 22,                    /* TRY_KW  */
  YYSYMBOL_CATCH_KW = 23,                  /* CATCH_KW  */
  YYSYMBOL_FINALLY_KW = 24,                /* FINALLY_KW  */
  YYSYMBOL_THROW_KW = 25,                  /* THROW_KW  */
  YYSYMBOL_NULL_KW = 26,                   /* NULL_KW  */
  YYSYMBOL_OP_INC = 27,                    /* OP_INC  */
  YYSYMBOL_OP_DEC = 28,                    /* OP_DEC  */
  YYSYMBOL_OP_ADD = 29,                    /* OP_ADD  */
  YYSYMBOL_OP_SUB = 30,                    /* OP_SUB  */
  YYSYMBOL_OP_MUL = 31,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 32,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 33,                    /* OP_MOD  */
  YYSYMBOL_OP_AND = 34,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 35,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 36,                    /* OP_NOT  */
  YYSYMBOL_OP_EQ = 37,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 38,                    /* OP_NEQ  */
  YYSYMBOL_OP_GT = 39,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 40,                     /* OP_LT  */
  YYSYMBOL_OP_GTE = 41,                    /* OP_GTE  */
  YYSYMBOL_OP_LTE = 42,                    /* OP_LTE  */
  YYSYMBOL_OP_ASSIGN = 43,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_ADD_ASSIGN = 44,             /* OP_ADD_ASSIGN  */
  YYSYMBOL_OP_SUB_ASSIGN = 45,             /* OP_SUB_ASSIGN  */
  YYSYMBOL_OP_MUL_ASSIGN = 46,             /* OP_MUL_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 47,             /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 48,             /* OP_MOD_ASSIGN  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_LEFT_PARENT = 50,               /* LEFT_PARENT  */
  YYSYMBOL_RIGHT_PARENT = 51,              /* RIGHT_PARENT  */
  YYSYMBOL_LEFT_BRACKET = 52,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 53,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_SQUARE = 54,               /* LEFT_SQUARE  */
  YYSYMBOL_RIGHT_SQUARE = 55,              /* RIGHT_SQUARE  */
  YYSYMBOL_COMMA = 56,                     /* COMMA  */
  YYSYMBOL_DOT = 57,                       /* DOT  */
  YYSYMBOL_D_COLON = 58,                   /* D_COLON  */
  YYSYMBOL_COLON = 59,                     /* COLON  */
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
  YYSYMBOL_func = 70,                      /* func  */
  YYSYMBOL_std_block_d = 71,               /* std_block_d  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_func_dec = 73,                  /* func_dec  */
  YYSYMBOL_block = 74,                     /* block  */
  YYSYMBOL_block_line = 75,                /* block_line  */
  YYSYMBOL_block_exp = 76,                 /* block_exp  */
  YYSYMBOL_rtrn = 77,                      /* rtrn  */
  YYSYMBOL_throw_dec = 78,                 /* throw_dec  */
  YYSYMBOL_loop = 79,                      /* loop  */
  YYSYMBOL_for_decl = 80,                  /* for_decl  */
  YYSYMBOL_for_vrs_dec = 81,               /* for_vrs_dec  */
  YYSYMBOL_for_var = 82,                   /* for_var  */
  YYSYMBOL_for_cond = 83,                  /* for_cond  */
  YYSYMBOL_for_sec = 84,                   /* for_sec  */
  YYSYMBOL_for_iter = 85,                  /* for_iter  */
  YYSYMBOL_while_exp = 86,                 /* while_exp  */
  YYSYMBOL_conditional = 87,               /* conditional  */
  YYSYMBOL_if_els_stmt = 88,               /* if_els_stmt  */
  YYSYMBOL_if_stmt = 89,                   /* if_stmt  */
  YYSYMBOL_90_2 = 90,                      /* $@2  */
  YYSYMBOL_else_stmt = 91,                 /* else_stmt  */
  YYSYMBOL_els_if_stmt = 92,               /* els_if_stmt  */
  YYSYMBOL_switch_stmt = 93,               /* switch_stmt  */
  YYSYMBOL_94_3 = 94,                      /* $@3  */
  YYSYMBOL_switch_block = 95,              /* switch_block  */
  YYSYMBOL_switch_line = 96,               /* switch_line  */
  YYSYMBOL_97_4 = 97,                      /* $@4  */
  YYSYMBOL_98_5 = 98,                      /* $@5  */
  YYSYMBOL_exception = 99,                 /* exception  */
  YYSYMBOL_try_catch = 100,                /* try_catch  */
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
#define YYLAST   544

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

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
       0,   208,   208,   208,   210,   210,   212,   212,   212,   212,
     212,   214,   221,   221,   223,   225,   225,   227,   227,   229,
     229,   229,   229,   229,   229,   229,   229,   230,   245,   247,
     247,   249,   249,   251,   252,   253,   255,   257,   257,   259,
     268,   276,   276,   278,   278,   280,   287,   287,   289,   289,
     289,   291,   291,   298,   300,   300,   300,   302,   302,   307,
     309,   309,   321,   321,   322,   322,   332,   332,   334,   336,
     336,   338,   338,   340,   340,   340,   342,   342,   350,   350,
     360,   362,   363,   364,   365,   366,   368,   369,   370,   371,
     372,   373,   374,   376,   377,   379,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   418,
     420,   420,   422,   422,   424,   425,   427,   427,   427,   429,
     429,   431,   432,   433,   435,   435,   435,   435
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
  "\"end of file\"", "error", "\"invalid token\"", "CHAR_KW", "INT_KW",
  "FLOAT_KW", "BOOL_KW", "STRING_KW", "VOID_KW", "IF_KW", "ELSE_KW",
  "SWITCH_KW", "CASE_KW", "DEFAULT_KW", "FOR_KW", "WHILE_KW", "DO_KW",
  "BREAK_KW", "RETURN_KW", "TRUE_KW", "FALSE_KW", "FUNCTION_KW", "TRY_KW",
  "CATCH_KW", "FINALLY_KW", "THROW_KW", "NULL_KW", "OP_INC", "OP_DEC",
  "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_AND", "OP_OR",
  "OP_NOT", "OP_EQ", "OP_NEQ", "OP_GT", "OP_LT", "OP_GTE", "OP_LTE",
  "OP_ASSIGN", "OP_ADD_ASSIGN", "OP_SUB_ASSIGN", "OP_MUL_ASSIGN",
  "OP_DIV_ASSIGN", "OP_MOD_ASSIGN", "UMINUS", "LEFT_PARENT",
  "RIGHT_PARENT", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_SQUARE",
  "RIGHT_SQUARE", "COMMA", "DOT", "D_COLON", "COLON", "CHAR", "STRING",
  "NUM", "NUM_DEC", "IDENTIFIER", "EOL", "$accept", "in", "line", "exp",
  "func", "std_block_d", "$@1", "func_dec", "block", "block_line",
  "block_exp", "rtrn", "throw_dec", "loop", "for_decl", "for_vrs_dec",
  "for_var", "for_cond", "for_sec", "for_iter", "while_exp", "conditional",
  "if_els_stmt", "if_stmt", "$@2", "else_stmt", "els_if_stmt",
  "switch_stmt", "$@3", "switch_block", "switch_line", "$@4", "$@5",
  "exception", "try_catch", "func_type", "func_params", "params_sec",
  "param", "instance", "inst_id", "type", "value_data", "var_value",
  "exp_op", "inc_dec", "ops_inc_dec", "func_call", "func_args", "func_arg",
  "asingn", "ops_asingn", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -162,    76,  -162,  -162,  -162,  -162,  -162,  -162,   -33,  -162,
    -162,   -31,    -3,  -162,  -162,    29,  -162,    44,  -162,     6,
      36,   131,  -162,   -38,  -162,  -162,    48,  -162,   337,  -162,
    -162,  -162,   384,  -162,   384,   384,  -162,  -162,  -162,  -162,
    -162,   384,  -162,  -162,   -36,    47,  -162,  -162,   384,   384,
     384,  -162,  -162,  -162,  -162,  -162,   -29,  -162,   179,   502,
    -162,  -162,    56,    52,  -162,   502,   502,   502,   502,  -162,
      50,    60,    57,    83,  -162,  -162,   172,   449,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,  -162,    65,
     139,    34,  -162,   -21,  -162,  -162,  -162,   502,  -162,  -162,
    -162,  -162,  -162,  -162,   277,   277,   277,   277,   277,   172,
     172,  -162,  -162,  -162,  -162,  -162,  -162,   399,  -162,    62,
      64,    66,    67,    44,  -162,   384,    69,    54,  -162,  -162,
    -162,    59,  -162,  -162,  -162,    44,  -162,  -162,   109,  -162,
    -162,    98,  -162,  -162,  -162,  -162,    88,    73,  -162,  -162,
     384,   384,    75,   384,   118,   502,  -162,    97,  -162,  -162,
      -7,  -162,   141,   100,   384,  -162,   502,   472,   117,   111,
     104,   112,   487,  -162,   245,   -34,  -162,  -162,    -7,  -162,
    -162,   502,   114,   120,   384,    44,   384,    75,  -162,   147,
    -162,   122,  -162,   272,    44,   115,   502,  -162,   125,   502,
    -162,   135,  -162,  -162,  -162,    22,   -16,   123,   384,   129,
    -162,    39,  -162,  -162,   134,  -162,  -162,   130,   435,  -162,
     142,  -162,   -16,   144,  -162,  -162,  -162,  -162,  -162,  -162,
     344,   317,   344,  -162
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    81,    82,    83,    84,    85,     0,   122,
     123,     0,    93,     4,     3,     0,     7,     0,     6,    78,
       0,     0,     8,     0,     9,    10,     0,    94,     0,     5,
      12,    11,     0,    80,     0,     0,   134,   135,   136,   137,
     120,     0,    93,   121,     0,     0,    89,    90,     0,     0,
       0,   124,    86,    91,    87,    88,    93,   117,    92,   130,
     119,   118,     0,   126,    15,    79,   131,   132,   133,    72,
       0,     0,    73,     0,    14,   100,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,    71,     0,    70,    69,   116,   129,   110,   111,
     112,   113,   114,   115,    95,    96,    97,    98,    99,   107,
     108,   105,   106,   101,   102,   103,   104,     0,   127,     0,
       0,     0,     0,     0,    20,    30,     0,     0,    13,    17,
      16,     0,    27,    28,    24,     0,    25,    46,    48,    47,
      26,    66,    19,    21,    22,    23,    76,     0,    74,   128,
       0,     0,     0,     0,     0,    29,    15,     0,    18,    34,
       0,    49,    50,     0,     0,    75,    51,     0,     0,     0,
       0,    37,     0,    35,     0,     0,    53,    54,     0,    56,
      15,    77,     0,     0,     0,     0,     0,     0,    45,     0,
      32,     0,    55,     0,     0,     0,    39,    33,     0,    40,
      38,     0,    31,    67,    52,     0,     0,     0,     0,     0,
      59,    57,    60,    36,    41,    43,    44,     0,     0,    64,
       0,    61,     0,     0,    62,    15,    58,    42,    15,    15,
      65,     0,    63,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,  -162,   -13,  -162,  -162,  -161,  -162,
    -162,  -162,  -162,  -162,  -162,     1,  -162,  -162,   -32,  -162,
      30,  -162,  -162,  -156,  -162,    27,  -162,  -162,  -162,  -162,
     -20,  -162,  -162,  -162,  -162,  -162,  -162,   -84,  -162,   216,
    -162,   -65,  -162,    -1,   -25,     2,    -8,     5,   -81,  -162,
       0,  -162
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    14,    15,    16,   186,    64,    17,   100,   140,
     141,   142,   143,   144,   179,   180,   181,   208,   223,   224,
     145,   146,   147,   148,   192,   171,   172,   149,   230,   221,
     222,   239,   235,   150,   151,    74,    45,    71,    72,   152,
      19,    20,    57,    58,    59,    60,    23,    61,    62,    63,
     155,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    25,   129,    22,    31,   184,    24,    65,   105,    66,
      67,     9,    10,    40,   187,    69,    68,   200,   128,   158,
      11,    28,    43,    75,    76,    77,    42,   201,    70,   203,
      78,    26,   202,    27,   218,   219,   156,     3,     4,     5,
       6,     7,    11,    70,   157,    30,   159,    28,    42,    32,
      40,   218,   219,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   175,   240,   220,     2,   241,   242,     3,
       4,     5,     6,     7,    46,    47,     3,     4,     5,     6,
       7,   104,     9,    10,    29,    48,    30,     8,    44,    21,
      33,    49,   153,     9,    10,   154,    73,    98,    99,   101,
     165,   102,   160,   103,   161,    50,   162,   163,   167,   170,
     164,   166,   173,    11,   168,    52,    53,    54,    55,    56,
     127,   174,   169,   132,    11,   176,   177,    70,   182,   178,
      12,    13,     3,     4,     5,     6,     7,   185,   129,   191,
     130,   188,   190,   131,   132,   133,   134,   135,     9,    10,
     194,   136,   195,   196,   137,   204,     9,    10,   197,   206,
     211,   209,   205,   212,    34,    35,    36,    37,    38,    39,
     215,   233,   207,    21,   216,   217,   153,   227,   229,   154,
     232,   214,   138,   228,   183,   236,   238,    11,   210,   189,
     237,   231,    21,    12,   139,   153,     9,    10,   154,    92,
      93,    94,    95,    96,    97,    21,   226,    18,   225,     0,
       0,     0,    79,    80,    81,    82,    83,    84,     0,     0,
       0,    21,   226,     0,   225,     0,     0,     0,     0,    21,
      21,    21,   153,   153,   153,   154,   154,   154,     3,     4,
       5,     6,     7,     0,   129,     0,   130,     0,     0,   131,
     132,   133,   134,   135,     0,     0,     0,   136,     0,     0,
     137,     0,     9,    10,     0,     3,     4,     5,     6,     7,
       0,   129,     0,   130,     0,     0,   131,   132,   133,   134,
     135,     0,     0,     0,   136,     0,     0,   137,   199,     9,
      10,     0,     0,    11,     0,     0,     0,     0,     0,    12,
     139,    90,    91,     0,    92,    93,    94,    95,    96,    97,
       3,     4,     5,     6,     7,   213,   129,     0,   130,     0,
      11,   131,   132,   133,   134,   135,    12,   139,     0,   136,
       0,     0,   137,     0,     9,    10,     0,     3,     4,     5,
       6,     7,     0,   129,     0,   130,    46,    47,   131,   132,
     133,   134,   135,     0,     9,    10,   136,    48,     0,   137,
     243,     9,    10,    49,     0,    11,     0,     0,     0,     0,
       0,    12,   139,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,     0,    11,     0,    52,    53,    54,
      55,    56,    11,    46,    47,     0,     0,     0,    12,   139,
       0,     9,    10,     0,    48,     0,     0,     0,    46,    47,
      49,     0,     0,     0,     0,     0,     9,    10,     0,    48,
       0,     0,     0,     0,    50,    49,     0,     0,     0,     0,
       0,     0,    11,     0,    52,    53,    54,    55,    12,    50,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    52,
      53,    54,    55,    56,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    93,    94,    95,    96,    97,    85,    86,
      87,    88,    89,    90,    91,     0,    92,    93,    94,    95,
      96,    97,     0,     0,   234,     0,     0,     0,     0,     0,
     106,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      93,    94,    95,    96,    97,     0,    85,    86,    87,    88,
      89,    90,    91,   193,    92,    93,    94,    95,    96,    97,
       0,    85,    86,    87,    88,    89,    90,    91,   198,    92,
      93,    94,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
       1,     1,     9,     1,    17,   166,     1,    32,    73,    34,
      35,    27,    28,    21,   170,    51,    41,    51,    99,   103,
      58,    50,    23,    48,    49,    50,    64,    61,    64,   190,
      59,    64,   188,    64,    12,    13,   101,     3,     4,     5,
       6,     7,    58,    64,    65,    52,   127,    50,    64,    43,
      58,    12,    13,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   157,   235,    53,     0,   238,   239,     3,
       4,     5,     6,     7,    19,    20,     3,     4,     5,     6,
       7,     8,    27,    28,    65,    30,    52,    21,    50,   100,
      64,    36,   100,    27,    28,   100,    59,    51,    56,    59,
     135,    51,    50,    56,    50,    50,    50,    50,    64,    10,
     133,    52,    24,    58,    65,    60,    61,    62,    63,    64,
      65,    43,   145,    15,    58,   160,   161,    64,   163,    64,
      64,    65,     3,     4,     5,     6,     7,    50,     9,   174,
      11,    10,    52,    14,    15,    16,    17,    18,    27,    28,
      43,    22,    51,    59,    25,    51,    27,    28,    56,   194,
      23,   196,    52,    51,    43,    44,    45,    46,    47,    48,
      65,    51,   195,   184,    59,    50,   184,    64,    59,   184,
      56,   204,    53,   218,   164,    53,    52,    58,   197,   172,
     232,   221,   203,    64,    65,   203,    27,    28,   203,    37,
      38,    39,    40,    41,    42,   216,   216,     1,   216,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,   232,   232,    -1,   232,    -1,    -1,    -1,    -1,   240,
     241,   242,   240,   241,   242,   240,   241,   242,     3,     4,
       5,     6,     7,    -1,     9,    -1,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    27,    28,    -1,     3,     4,     5,     6,     7,
      -1,     9,    -1,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    53,    27,
      28,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,
      65,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     7,    53,     9,    -1,    11,    -1,
      58,    14,    15,    16,    17,    18,    64,    65,    -1,    22,
      -1,    -1,    25,    -1,    27,    28,    -1,     3,     4,     5,
       6,     7,    -1,     9,    -1,    11,    19,    20,    14,    15,
      16,    17,    18,    -1,    27,    28,    22,    30,    -1,    25,
      53,    27,    28,    36,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,    62,
      63,    64,    58,    19,    20,    -1,    -1,    -1,    64,    65,
      -1,    27,    28,    -1,    30,    -1,    -1,    -1,    19,    20,
      36,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    50,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60,    61,    62,    63,    64,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    62,    63,    64,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      51,    29,    30,    31,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    29,    30,    31,    32,
      33,    34,    35,    51,    37,    38,    39,    40,    41,    42,
      -1,    29,    30,    31,    32,    33,    34,    35,    51,    37,
      38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,     0,     3,     4,     5,     6,     7,    21,    27,
      28,    58,    64,    65,    68,    69,    70,    73,   105,   106,
     107,   109,   111,   112,   113,   116,    64,    64,    50,    65,
      52,    71,    43,    64,    43,    44,    45,    46,    47,    48,
     112,   117,    64,   109,    50,   102,    19,    20,    30,    36,
      50,    51,    60,    61,    62,    63,    64,   108,   109,   110,
     111,   113,   114,   115,    72,   110,   110,   110,   110,    51,
      64,   103,   104,    59,   101,   110,   110,   110,    59,    43,
      44,    45,    46,    47,    48,    29,    30,    31,    32,    33,
      34,    35,    37,    38,    39,    40,    41,    42,    51,    56,
      74,    59,    51,    56,     8,   107,    51,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,    65,   114,     9,
      11,    14,    15,    16,    17,    18,    22,    25,    53,    65,
      75,    76,    77,    78,    79,    86,    87,    88,    89,    93,
      99,   100,   105,   111,   113,   116,   107,    65,   103,   114,
      50,    50,    50,    50,    71,   110,    52,    64,    65,    71,
      10,    91,    92,    24,    43,   103,   110,   110,    64,    80,
      81,    82,   110,    86,    74,    50,    71,    89,    10,    91,
      52,   110,    90,    51,    43,    51,    59,    56,    51,    53,
      51,    61,    89,    74,    51,    52,   110,    71,    83,   110,
      81,    23,    51,    53,    71,    65,    59,    50,    12,    13,
      53,    95,    96,    84,    85,   111,   116,    64,   110,    59,
      94,    96,    56,    51,    59,    98,    53,    84,    52,    97,
      74,    74,    74,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    70,    72,    71,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    80,    81,    81,    82,
      83,    84,    84,    85,    85,    86,    87,    87,    88,    88,
      88,    90,    89,    91,    92,    92,    92,    94,    93,    93,
      95,    95,    97,    96,    98,    96,    99,    99,   100,   101,
     101,   102,   102,   103,   103,   103,   104,   104,   105,   105,
     106,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   115,
     115,   116,   116,   116,   117,   117,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     4,     4,     0,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     4,     5,     2,     3,     5,     1,     3,     3,
       1,     1,     3,     1,     1,     4,     1,     1,     1,     2,
       2,     0,     6,     2,     2,     3,     2,     0,     9,     7,
       1,     2,     0,     5,     0,     4,     1,     5,    11,     2,
       2,     3,     2,     1,     3,     4,     3,     5,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       2,     2,     1,     1,     3,     4,     1,     3,     4,     3,
       1,     3,     3,     3,     1,     1,     1,     1
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
  case 11: /* func: func_dec std_block_d  */
#line 214 "sintax_analizer.y"
                                     {
    if (functType != 0 && !hasReturn) {
        printf("Logical error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1610 "sintax_analizer.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 221 "sintax_analizer.y"
                             { initBlock(); }
#line 1616 "sintax_analizer.tab.c"
    break;

  case 13: /* std_block_d: LEFT_BRACKET $@1 block RIGHT_BRACKET  */
#line 221 "sintax_analizer.y"
                                                                  { endBlock(); }
#line 1622 "sintax_analizer.tab.c"
    break;

  case 14: /* func_dec: FUNCTION_KW IDENTIFIER func_params func_type  */
#line 223 "sintax_analizer.y"
                                                             { addSymb((yyvsp[-2].sval), (yyvsp[0].ival), true); }
#line 1628 "sintax_analizer.tab.c"
    break;

  case 27: /* block_exp: rtrn  */
#line 230 "sintax_analizer.y"
                   {
    if (scopeLevel == 1) {
        hasReturn = true;
    }
    if (functType != 0 && (yyvsp[0].ival) == 0) {
        printf("Logical error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    } else if (functType == 0 && (yyvsp[0].ival) != 0) {
        printf("Logical error at line %d: the function is void and has a return value\n", lineNumber);
        hasErrors = true;
    } else if (functType != 0 && functType != (yyvsp[0].ival)) {
        printf("Incompatible type error at line %d: return data value of function is not compatible with function return type\n",
            lineNumber);
        hasErrors = true;
    }
}
#line 1649 "sintax_analizer.tab.c"
    break;

  case 29: /* rtrn: RETURN_KW exp_op  */
#line 247 "sintax_analizer.y"
                                 { (yyval.ival) = (yyvsp[0].ival); }
#line 1655 "sintax_analizer.tab.c"
    break;

  case 30: /* rtrn: RETURN_KW  */
#line 247 "sintax_analizer.y"
                                                          { (yyval.ival) = 0; }
#line 1661 "sintax_analizer.tab.c"
    break;

  case 39: /* for_var: IDENTIFIER OP_ASSIGN exp_op  */
#line 259 "sintax_analizer.y"
                                            {
    if ((yyvsp[0].ival) != 2) {
        printf("Incompatible type error at line %d: the variable used in for iteration is not a int value\n", 
            lineNumber);
    } else {
        addForNumber((yyvsp[-2].sval));
    }
}
#line 1674 "sintax_analizer.tab.c"
    break;

  case 40: /* for_cond: exp_op  */
#line 268 "sintax_analizer.y"
                       {
    if((yyvsp[0].ival) != 4 ) {
        printf("Logical error at line %d: the condition used in for iteration is not a bool value\n", 
            lineNumber);
        hasErrors = true;
    }
}
#line 1686 "sintax_analizer.tab.c"
    break;

  case 45: /* while_exp: WHILE_KW LEFT_PARENT exp_op RIGHT_PARENT  */
#line 280 "sintax_analizer.y"
                                                         {
    if ((yyvsp[-1].ival) != 4) {
        printf("Logical error at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1697 "sintax_analizer.tab.c"
    break;

  case 51: /* $@2: %empty  */
#line 291 "sintax_analizer.y"
                                         {
    if ((yyvsp[0].ival) != 4) {
        printf("Logical error at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
}
#line 1708 "sintax_analizer.tab.c"
    break;

  case 57: /* $@3: %empty  */
#line 302 "sintax_analizer.y"
                                                                                        {
    if ((yyvsp[-4].ival) != (yyvsp[0].ival) && (yyvsp[0].ival) != 0) {
        printf("Incompatible type error at line %d: the switch cases are not compatible with the switch value type\n", lineNumber);
        hasErrors = true;
    }
}
#line 1719 "sintax_analizer.tab.c"
    break;

  case 58: /* switch_stmt: SWITCH_KW LEFT_PARENT exp_op RIGHT_PARENT LEFT_BRACKET EOL switch_block $@3 RIGHT_BRACKET  */
#line 307 "sintax_analizer.y"
                { hasDefaultCase = false; }
#line 1725 "sintax_analizer.tab.c"
    break;

  case 60: /* switch_block: switch_line  */
#line 309 "sintax_analizer.y"
                            { (yyval.ival) = (yyvsp[0].ival); }
#line 1731 "sintax_analizer.tab.c"
    break;

  case 61: /* switch_block: switch_block switch_line  */
#line 309 "sintax_analizer.y"
                                                                    {
    (yyvsp[-1].ival) = (yyvsp[-1].ival) == 0 ? (yyvsp[0].ival) : (yyvsp[-1].ival);
    (yyvsp[0].ival) = (yyvsp[0].ival) == 0 ? (yyvsp[-1].ival) : (yyvsp[0].ival);
    if ((yyvsp[-1].ival) != (yyvsp[0].ival)) {
        printf("Incompatible type error at line %d: the switch cases data types are not compatible\n", lineNumber);
        hasErrors = true;
        (yyval.ival) = 0;
    } else {
        (yyval.ival) = (yyvsp[0].ival);
    }
}
#line 1747 "sintax_analizer.tab.c"
    break;

  case 62: /* $@4: %empty  */
#line 321 "sintax_analizer.y"
                                     { initBlock(); }
#line 1753 "sintax_analizer.tab.c"
    break;

  case 63: /* switch_line: CASE_KW exp_op COLON $@4 block  */
#line 321 "sintax_analizer.y"
                                                            { endBlock(); (yyval.ival) = (yyvsp[-3].ival); }
#line 1759 "sintax_analizer.tab.c"
    break;

  case 64: /* $@5: %empty  */
#line 322 "sintax_analizer.y"
                                 { initBlock(); }
#line 1765 "sintax_analizer.tab.c"
    break;

  case 65: /* switch_line: DEFAULT_KW COLON $@5 block  */
#line 322 "sintax_analizer.y"
                                                        {
    endBlock();
    if (hasDefaultCase) {
        printf("Logical error at line %d: the switch has more than one default case\n", lineNumber);
        hasErrors = true;
    }
    hasDefaultCase = true;
    (yyval.ival) = 0;
}
#line 1779 "sintax_analizer.tab.c"
    break;

  case 69: /* func_type: COLON type  */
#line 336 "sintax_analizer.y"
                           { functType = (yyvsp[0].ival); hasReturn = false; (yyval.ival) = (yyvsp[0].ival); }
#line 1785 "sintax_analizer.tab.c"
    break;

  case 70: /* func_type: COLON VOID_KW  */
#line 336 "sintax_analizer.y"
                                                                                           { functType = 0; (yyval.ival) = 0; }
#line 1791 "sintax_analizer.tab.c"
    break;

  case 76: /* param: IDENTIFIER COLON type  */
#line 342 "sintax_analizer.y"
                                      { addFunctionParam((yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 1797 "sintax_analizer.tab.c"
    break;

  case 77: /* param: IDENTIFIER COLON type OP_ASSIGN exp_op  */
#line 342 "sintax_analizer.y"
                                                                                                             {
    addFunctionParam((yyvsp[-4].sval), (yyvsp[-2].ival));
    if ((yyvsp[0].ival) != (yyvsp[-2].ival)) {
        printf("Incompatible type error at line %d: data value of parameter %s is not compatible with data type\n",lineNumber, (yyvsp[-4].sval));
        hasErrors = true;
    }
}
#line 1809 "sintax_analizer.tab.c"
    break;

  case 79: /* instance: inst_id OP_ASSIGN exp_op  */
#line 350 "sintax_analizer.y"
                                                   {
    if ((yyvsp[-2].ival) == 5 && (yyvsp[0].ival) != 5 && (yyvsp[0].ival) != 1) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber - 1);
        hasErrors = true;
    } else if ((yyvsp[-2].ival) != (yyvsp[0].ival) && (yyvsp[-2].ival) != 5) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber - 1);
        hasErrors = true;
    }
}
#line 1823 "sintax_analizer.tab.c"
    break;

  case 80: /* inst_id: type IDENTIFIER  */
#line 360 "sintax_analizer.y"
                                { addSymb((yyvsp[0].sval), (yyvsp[-1].ival), false); (yyval.ival) = (yyvsp[-1].ival); }
#line 1829 "sintax_analizer.tab.c"
    break;

  case 81: /* type: CHAR_KW  */
#line 362 "sintax_analizer.y"
                            { (yyval.ival) = 1; }
#line 1835 "sintax_analizer.tab.c"
    break;

  case 82: /* type: INT_KW  */
#line 363 "sintax_analizer.y"
                            { (yyval.ival) = 2; }
#line 1841 "sintax_analizer.tab.c"
    break;

  case 83: /* type: FLOAT_KW  */
#line 364 "sintax_analizer.y"
                            { (yyval.ival) = 3; }
#line 1847 "sintax_analizer.tab.c"
    break;

  case 84: /* type: BOOL_KW  */
#line 365 "sintax_analizer.y"
                            { (yyval.ival) = 4; }
#line 1853 "sintax_analizer.tab.c"
    break;

  case 85: /* type: STRING_KW  */
#line 366 "sintax_analizer.y"
                            { (yyval.ival) = 5; }
#line 1859 "sintax_analizer.tab.c"
    break;

  case 86: /* value_data: CHAR  */
#line 368 "sintax_analizer.y"
                            { (yyval.ival) = 1; }
#line 1865 "sintax_analizer.tab.c"
    break;

  case 87: /* value_data: NUM  */
#line 369 "sintax_analizer.y"
                            { (yyval.ival) = 2; }
#line 1871 "sintax_analizer.tab.c"
    break;

  case 88: /* value_data: NUM_DEC  */
#line 370 "sintax_analizer.y"
                            { (yyval.ival) = 3; }
#line 1877 "sintax_analizer.tab.c"
    break;

  case 89: /* value_data: TRUE_KW  */
#line 371 "sintax_analizer.y"
                            { (yyval.ival) = 4; }
#line 1883 "sintax_analizer.tab.c"
    break;

  case 90: /* value_data: FALSE_KW  */
#line 372 "sintax_analizer.y"
                            { (yyval.ival) = 4; }
#line 1889 "sintax_analizer.tab.c"
    break;

  case 91: /* value_data: STRING  */
#line 373 "sintax_analizer.y"
                            { (yyval.ival) = 5; }
#line 1895 "sintax_analizer.tab.c"
    break;

  case 92: /* value_data: var_value  */
#line 374 "sintax_analizer.y"
                            { (yyval.ival) = (yyvsp[0].ival); }
#line 1901 "sintax_analizer.tab.c"
    break;

  case 93: /* var_value: IDENTIFIER  */
#line 376 "sintax_analizer.y"
                            { (yyval.ival) = getSymbType((yyvsp[0].sval), false); }
#line 1907 "sintax_analizer.tab.c"
    break;

  case 94: /* var_value: D_COLON IDENTIFIER  */
#line 377 "sintax_analizer.y"
                                   { (yyval.ival) = getGlobalSymbType((yyvsp[0].sval)); }
#line 1913 "sintax_analizer.tab.c"
    break;

  case 95: /* exp_op: exp_op OP_ADD exp_op  */
#line 379 "sintax_analizer.y"
                                     {
    if ((yyvsp[-2].ival) == 4 && (yyvsp[0].ival) == 4) {
        printf("Logical error at line %d: invalid operation expression, cannot add bool values\n", lineNumber);
        hasErrors = true;
        (yyval.ival) = 0;
    } else {
        (yyvsp[-2].ival) = (yyvsp[-2].ival) == 1 || (yyvsp[-2].ival) == 4 ? 5 : (yyvsp[-2].ival);
        (yyvsp[0].ival) = (yyvsp[0].ival) == 1 || (yyvsp[0].ival) == 4 ? 5 : (yyvsp[0].ival);
        (yyval.ival) = (yyvsp[-2].ival) == 5 || (yyvsp[0].ival) == 5 ? 5 : (yyvsp[-2].ival) == 3 || (yyvsp[0].ival) == 3 ? 3 : 2;
    }
}
#line 1929 "sintax_analizer.tab.c"
    break;

  case 96: /* exp_op: exp_op OP_SUB exp_op  */
#line 390 "sintax_analizer.y"
                                     { (yyval.ival) = checkNumsOperation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1935 "sintax_analizer.tab.c"
    break;

  case 97: /* exp_op: exp_op OP_MUL exp_op  */
#line 391 "sintax_analizer.y"
                                     { (yyval.ival) = checkNumsOperation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1941 "sintax_analizer.tab.c"
    break;

  case 98: /* exp_op: exp_op OP_DIV exp_op  */
#line 392 "sintax_analizer.y"
                                     { (yyval.ival) = checkNumsOperation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1947 "sintax_analizer.tab.c"
    break;

  case 99: /* exp_op: exp_op OP_MOD exp_op  */
#line 393 "sintax_analizer.y"
                                     { (yyval.ival) = checkNumsOperation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1953 "sintax_analizer.tab.c"
    break;

  case 100: /* exp_op: OP_SUB exp_op  */
#line 394 "sintax_analizer.y"
                                           { (yyval.ival) = checkNumsOperation((yyvsp[0].ival), (yyvsp[0].ival)); }
#line 1959 "sintax_analizer.tab.c"
    break;

  case 101: /* exp_op: exp_op OP_GT exp_op  */
#line 395 "sintax_analizer.y"
                                    { (yyval.ival) = checkComparison((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1965 "sintax_analizer.tab.c"
    break;

  case 102: /* exp_op: exp_op OP_LT exp_op  */
#line 396 "sintax_analizer.y"
                                    { (yyval.ival) = checkComparison((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1971 "sintax_analizer.tab.c"
    break;

  case 103: /* exp_op: exp_op OP_GTE exp_op  */
#line 397 "sintax_analizer.y"
                                     { (yyval.ival) = checkComparison((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1977 "sintax_analizer.tab.c"
    break;

  case 104: /* exp_op: exp_op OP_LTE exp_op  */
#line 398 "sintax_analizer.y"
                                     { (yyval.ival) = checkComparison((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1983 "sintax_analizer.tab.c"
    break;

  case 105: /* exp_op: exp_op OP_EQ exp_op  */
#line 399 "sintax_analizer.y"
                                    { (yyval.ival) = checkValuesComparison((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1989 "sintax_analizer.tab.c"
    break;

  case 106: /* exp_op: exp_op OP_NEQ exp_op  */
#line 400 "sintax_analizer.y"
                                     { (yyval.ival) = checkValuesComparison((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1995 "sintax_analizer.tab.c"
    break;

  case 107: /* exp_op: exp_op OP_AND exp_op  */
#line 401 "sintax_analizer.y"
                                     { (yyval.ival) = checkLogicOperation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2001 "sintax_analizer.tab.c"
    break;

  case 108: /* exp_op: exp_op OP_OR exp_op  */
#line 402 "sintax_analizer.y"
                                    { (yyval.ival) = checkLogicOperation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2007 "sintax_analizer.tab.c"
    break;

  case 109: /* exp_op: OP_NOT exp_op  */
#line 403 "sintax_analizer.y"
                              { (yyval.ival) = checkLogicOperation((yyvsp[0].ival), (yyvsp[0].ival)); }
#line 2013 "sintax_analizer.tab.c"
    break;

  case 110: /* exp_op: var_value OP_ASSIGN exp_op  */
#line 404 "sintax_analizer.y"
                                           { (yyval.ival) = singleAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2019 "sintax_analizer.tab.c"
    break;

  case 111: /* exp_op: var_value OP_ADD_ASSIGN exp_op  */
#line 405 "sintax_analizer.y"
                                               { (yyval.ival) = checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2025 "sintax_analizer.tab.c"
    break;

  case 112: /* exp_op: var_value OP_SUB_ASSIGN exp_op  */
#line 406 "sintax_analizer.y"
                                               { (yyval.ival) = checkAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2031 "sintax_analizer.tab.c"
    break;

  case 113: /* exp_op: var_value OP_MUL_ASSIGN exp_op  */
#line 407 "sintax_analizer.y"
                                               { (yyval.ival) = checkAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2037 "sintax_analizer.tab.c"
    break;

  case 114: /* exp_op: var_value OP_DIV_ASSIGN exp_op  */
#line 408 "sintax_analizer.y"
                                               { (yyval.ival) = checkAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2043 "sintax_analizer.tab.c"
    break;

  case 115: /* exp_op: var_value OP_MOD_ASSIGN exp_op  */
#line 409 "sintax_analizer.y"
                                               { (yyval.ival) = checkAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2049 "sintax_analizer.tab.c"
    break;

  case 116: /* exp_op: LEFT_PARENT exp_op RIGHT_PARENT  */
#line 410 "sintax_analizer.y"
                                                { (yyval.ival) = (yyvsp[-1].ival); }
#line 2055 "sintax_analizer.tab.c"
    break;

  case 117: /* exp_op: value_data  */
#line 411 "sintax_analizer.y"
                           { (yyval.ival) = (yyvsp[0].ival); }
#line 2061 "sintax_analizer.tab.c"
    break;

  case 118: /* exp_op: func_call  */
#line 412 "sintax_analizer.y"
                          { (yyval.ival) = (yyvsp[0].ival);
    if ((yyvsp[0].ival) == 0) {
        printf("Logical error at line %d: the function called has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
#line 2072 "sintax_analizer.tab.c"
    break;

  case 119: /* exp_op: inc_dec  */
#line 418 "sintax_analizer.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2078 "sintax_analizer.tab.c"
    break;

  case 120: /* inc_dec: var_value ops_inc_dec  */
#line 420 "sintax_analizer.y"
                                      { (yyval.ival) = checkIncrementDecrement((yyvsp[-1].ival)); }
#line 2084 "sintax_analizer.tab.c"
    break;

  case 121: /* inc_dec: ops_inc_dec var_value  */
#line 420 "sintax_analizer.y"
                                                                                                    { (yyval.ival) = checkIncrementDecrement((yyvsp[0].ival)); }
#line 2090 "sintax_analizer.tab.c"
    break;

  case 124: /* func_call: IDENTIFIER LEFT_PARENT RIGHT_PARENT  */
#line 424 "sintax_analizer.y"
                                                    { (yyval.ival) = getSymbType((yyvsp[-2].sval), true); }
#line 2096 "sintax_analizer.tab.c"
    break;

  case 125: /* func_call: IDENTIFIER LEFT_PARENT func_args RIGHT_PARENT  */
#line 425 "sintax_analizer.y"
                                                              { (yyval.ival) = getSymbType((yyvsp[-3].sval), true); }
#line 2102 "sintax_analizer.tab.c"
    break;

  case 131: /* asingn: var_value OP_ASSIGN exp_op  */
#line 431 "sintax_analizer.y"
                                           { singleAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2108 "sintax_analizer.tab.c"
    break;

  case 132: /* asingn: var_value OP_ADD_ASSIGN exp_op  */
#line 432 "sintax_analizer.y"
                                               { checkSumAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2114 "sintax_analizer.tab.c"
    break;

  case 133: /* asingn: var_value ops_asingn exp_op  */
#line 433 "sintax_analizer.y"
                                            { checkAsignation((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2120 "sintax_analizer.tab.c"
    break;


#line 2124 "sintax_analizer.tab.c"

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

#line 436 "sintax_analizer.y"


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
