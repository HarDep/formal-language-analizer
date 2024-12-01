%{
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
%}
%union{
    int ival;
    char *sval;
    double dval;
    struct {
        int type;
        int hasVal;
        double val;
    } sdata;
}
%right OP_ASSIGN OP_ADD_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN
%left OP_AND OP_OR
%left OP_EQ OP_NEQ
%left OP_GT OP_LT OP_GTE OP_LTE
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD
%right OP_NOT UMINUS
%token THROW_KW OP_INC OP_DEC
%token LEFT_PARENT RIGHT_PARENT LEFT_BRACKET RIGHT_BRACKET COMMA D_COLON COLON
%token FOR_KW WHILE_KW DO_KW BREAK_KW RETURN_KW TRUE_KW FALSE_KW FUNCTION_KW TRY_KW CATCH_KW FINALLY_KW
%token CHAR_KW INT_KW FLOAT_KW BOOL_KW STRING_KW VOID_KW IF_KW ELSE_KW SWITCH_KW CASE_KW DEFAULT_KW
%token <ival> CHAR STRING 
%token <dval> NUM NUM_DEC
%token <sval> IDENTIFIER
%token EOL
%type <ival> rtrn type func_call inc_dec var_value func_type switch_line switch_block inst_id
%type <sdata> value_data exp_op
%%
in          :   /* empty */ | in line;

line        :   n_line | exp n_line | exp_wth_bl;

n_line      :   EOL { lineNumber++; };

exp         :   instance | inc_dec | func_call | asingn;

exp_wth_bl  :   loop | conditional | exception | func;

func        :   func_dec std_block_d {
    if (functType != -1 && !hasReturn) {
        printf("Missing return error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    }
};

std_block_d :   LEFT_BRACKET { initBlock(); } block RIGHT_BRACKET { endBlock(); };

func_dec    :   FUNCTION_KW IDENTIFIER func_params func_type { addSymb($2, $4, true); };

block       :   /* empty */ | block block_line;

block_line  :   n_line | block_exp n_line;

block_exp   :   instance | BREAK_KW | inc_dec | func_call | asingn | loop | conditional | exception
            | rtrn {
    if (scopeLevel == 1) {
        hasReturn = true;
    }
    if (functType != -1 && $1 == -1 && $1 != 0) {
        printf("Incompatible type error at line %d: the function has no a return value\n", lineNumber);
        hasErrors = true;
    } else if (functType == -1 && $1 != -1) {
        printf("Incompatible type error at line %d: the function is void and has a return value\n", lineNumber);
        hasErrors = true;
    } else if (functType != -1 && functType != $1 && $1 != 0) {
        printf("Incompatible type error at line %d: return data value of function is not compatible with function return type\n",
            lineNumber);
        hasErrors = true;
    }
} | throw_dec;

rtrn        :   RETURN_KW exp_op { $$ = $2.type; } | RETURN_KW { $$ = -1; };

throw_dec   :   THROW_KW IDENTIFIER LEFT_PARENT STRING RIGHT_PARENT | THROW_KW IDENTIFIER LEFT_PARENT RIGHT_PARENT;

loop        :   FOR_KW LEFT_PARENT for_decl RIGHT_PARENT std_block_d
            |   while_exp std_block_d
            |   DO_KW std_block_d while_exp;

for_decl    :   for_vrs_dec COLON for_cond COLON for_sec;

for_vrs_dec :   for_var | for_var COMMA for_vrs_dec;

for_var     :   IDENTIFIER OP_ASSIGN exp_op {
    if ($3.type != 2 && $3.type != 0) {
        printf("Incompatible type error at line %d: the variable used in for iteration is not a int value\n", 
            lineNumber);
    }
    addForNumber($1);
};

for_cond    :   exp_op {
    if($1.type != 4 && $1.type != 0) {
        printf("Incompatible type expression at line %d: the condition used in for iteration is not a bool value\n", 
            lineNumber);
        hasErrors = true;
    }
};

for_sec     :   for_iter | for_iter COMMA for_sec;

for_iter    :   inc_dec | asingn;

while_exp   :   WHILE_KW LEFT_PARENT exp_op RIGHT_PARENT {
    if ($3.type != 4 && $3.type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
};

conditional :   if_els_stmt | switch_stmt;

if_els_stmt :   if_stmt | if_stmt else_stmt | if_stmt els_if_stmt;

if_stmt     :   IF_KW LEFT_PARENT exp_op {
    if ($3.type != 4 && $3.type != 0) {
        printf("Incompatible type expression at line %d: the condition is not a bool value\n", lineNumber);
        hasErrors = true;
    }
} RIGHT_PARENT std_block_d;

else_stmt   :   ELSE_KW std_block_d;

els_if_stmt :   ELSE_KW if_stmt | els_if_stmt ELSE_KW if_stmt | els_if_stmt else_stmt;

switch_stmt :   SWITCH_KW LEFT_PARENT exp_op RIGHT_PARENT LEFT_BRACKET n_line switch_block {
    if ($3.type != $7 && $7 != 0 && $3.type != 0) {
        printf("Incompatible type error at line %d: the cases type are not compatible with the switch value type\n", lineNumber);
        hasErrors = true;
    }
} RIGHT_BRACKET { hasDefaultCase = false; } | SWITCH_KW LEFT_PARENT exp_op RIGHT_PARENT LEFT_BRACKET n_line RIGHT_BRACKET;

switch_block:   switch_line { $$ = $1 == -1 ? 0 : $1; } | switch_block switch_line {
    $1 = $1 == -1 ? $2 : $1;
    $2 = $2 == -1 ? $1 : $2;
    if ($1 != $2) {
        printf("Incompatible type error at line %d: the switch cases data types are not compatible\n", lineNumber);
        hasErrors = true;
        $$ = 0;
    } else {
        $$ = $2;
    }
};

switch_line :   CASE_KW exp_op COLON { initBlock(); } block { endBlock(); $$ = $2.type; }
            |   DEFAULT_KW COLON { initBlock(); } block {
    endBlock();
    if (hasDefaultCase) {
        printf("Definition error at line %d: the switch has more than one default case\n", lineNumber);
        hasErrors = true;
    }
    hasDefaultCase = true;
    $$ = -1;
};

exception   :   try_catch | try_catch FINALLY_KW std_block_d;

try_catch   :   TRY_KW LEFT_BRACKET { isInException = true; initBlock(); } block RIGHT_BRACKET { isInException = false; endBlock(); } CATCH_KW LEFT_PARENT IDENTIFIER RIGHT_PARENT std_block_d;

func_type   :   COLON type { functType = $2; hasReturn = false; $$ = $2; } | COLON VOID_KW { functType = -1; $$ = -1; };

func_params :   LEFT_PARENT params_sec RIGHT_PARENT | LEFT_PARENT RIGHT_PARENT;

params_sec  :   param | param COMMA params_sec | param COMMA n_line params_sec;

param       :   IDENTIFIER COLON type { addFunctionParam($1, $3); } | IDENTIFIER COLON type OP_ASSIGN exp_op {
    addFunctionParam($1, $3);
    if ($5.type != $3 && $5.type != 0) {
        printf("Incompatible type error at line %d: data value of parameter %s is not compatible with data type\n",lineNumber, $1);
        hasErrors = true;
    }
};

instance    :   inst_id | inst_id OP_ASSIGN exp_op {
    if ($1 == 5 && $3.type != 5 && $3.type != 1 && $3.type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber);
        hasErrors = true;
    } else if ($1 != $3.type && $1 != 5 && $3.type != 0) {
        printf("Incompatible type error at line %d: variable inicialization value is not compatible with data type\n",lineNumber);
        hasErrors = true;
    }
};

inst_id     :   type IDENTIFIER { addSymb($2, $1, false); $$ = $1; };

type        :   CHAR_KW     { $$ = 1; }
            |   INT_KW      { $$ = 2; }
            |   FLOAT_KW    { $$ = 3; }
            |   BOOL_KW     { $$ = 4; }
            |   STRING_KW   { $$ = 5; };

value_data  :   CHAR        { $$.type = 1; $$.hasVal = 0; }
            |   NUM         { $$.type = 2; $$.hasVal = 1; $$.val = $1; }
            |   NUM_DEC     { $$.type = 3; $$.hasVal = 1; $$.val = $1; }
            |   TRUE_KW     { $$.type = 4; $$.hasVal = 0; }
            |   FALSE_KW    { $$.type = 4; $$.hasVal = 0; }
            |   STRING      { $$.type = 5; $$.hasVal = 0; }
            |   var_value   { $$.type = $1; $$.hasVal = 0; };

var_value   :   IDENTIFIER  { $$ = getSymbType($1, false); }
            |   D_COLON IDENTIFIER { $$ = getGlobalSymbType($2); };

exp_op      :   exp_op OP_ADD exp_op {
    if ($1.type == 4 && $3.type == 4) {
        printf("Incompatible type expression at line %d: invalid operation expression, cannot add bool values\n", lineNumber);
        hasErrors = true;
        $$.type = 0;
    } else {
        if ($1.type != 0 && $3.type != 0) {
            $1.type = $1.type == 1 || $1.type == 4 ? 5 : $1.type;
            $3.type = $3.type == 1 || $3.type == 4 ? 5 : $3.type;
            $$.type = $1.type == 5 || $3.type == 5 ? 5 : $1.type == 3 || $3.type == 3 ? 3 : 2;
        }else{
            $$.type = 0;
        }
    }
    if($1.hasVal && $3.hasVal) {
        $$.hasVal = 1;
        $$.val = $1.val + $3.val;
    } else {
        $$.hasVal = 0;
    }
}
            |   exp_op OP_SUB exp_op { $$.type = checkNumsOperation($1.type, $3.type);
    if($1.hasVal && $3.hasVal) {
        $$.hasVal = 1;
        $$.val = $1.val - $3.val;
    } else {
        $$.hasVal = 0;
    }
}
            |   exp_op OP_MUL exp_op { $$.type = checkNumsOperation($1.type, $3.type);
    if($1.hasVal && $3.hasVal) {
        $$.hasVal = 1;
        $$.val = $1.val * $3.val;
    } else {
        $$.hasVal = 0;
    }
}
            |   exp_op OP_DIV exp_op { $$.type = checkNumsOperation($1.type, $3.type);
    if($1.hasVal && $3.hasVal && $3.val != 0) {
            $$.hasVal = 1;
            $$.val = $1.val / $3.val;
    } else {
        $$.hasVal = 0;
    }
    if($3.hasVal && $3.val == 0 && !isInException) {
        printf("Logical error at line %d: division by zero\n", lineNumber);
        hasErrors = true;
        $$.hasVal = 0;
    }
}
            |   exp_op OP_MOD exp_op { $$.type = checkNumsOperation($1.type, $3.type);
    if($1.hasVal && $3.hasVal && $3.val != 0) {
            $$.hasVal = 1;
            $$.val = fmod($1.val,$3.val);
    } else {
        $$.hasVal = 0;
    }
    if($3.hasVal && $3.val == 0 && !isInException) {
        printf("Logical error at line %d: division by zero on module operation\n", lineNumber);
        hasErrors = true;
        $$.hasVal = 0;
    }
}
            |   OP_SUB exp_op %prec UMINUS { $$.type = checkNumsOperation($2.type, $2.type);
    if($2.hasVal) {
        $$.hasVal = 1;
        $$.val = -$2.val;
    } else {
        $$.hasVal = 0;
    }
}
            |   exp_op OP_GT exp_op { $$.type = checkComparison($1.type, $3.type); $$.hasVal=0;
    if($1.hasVal && $3.hasVal && !isInException) {
        int dec1 = $1.type == 2 ? 0 : 7;
        int dec2 = $3.type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f > %.*f is always %s\n", lineNumber, dec1, $1.val, dec2, $3.val, $1.val > $3.val ? "true" : "false");
        hasErrors = true;
    }
}
            |   exp_op OP_LT exp_op { $$.type = checkComparison($1.type, $3.type); $$.hasVal=0;
    if($1.hasVal && $3.hasVal && !isInException) {
        int dec1 = $1.type == 2 ? 0 : 7;
        int dec2 = $3.type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f < %.*f is always %s\n", lineNumber, dec1, $1.val, dec2, $3.val, $1.val < $3.val ? "true" : "false");
        hasErrors = true;
    }
}
            |   exp_op OP_GTE exp_op { $$.type = checkComparison($1.type, $3.type); $$.hasVal=0;
    if($1.hasVal && $3.hasVal && !isInException) {
        int dec1 = $1.type == 2 ? 0 : 7;
        int dec2 = $3.type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f >= %.*f is always %s\n", lineNumber, dec1,$1.val, dec2, $3.val, $1.val >= $3.val ? "true" : "false");
        hasErrors = true;
    }
}
            |   exp_op OP_LTE exp_op { $$.type = checkComparison($1.type, $3.type); $$.hasVal=0;
    if($1.hasVal && $3.hasVal && !isInException) {
        int dec1 = $1.type == 2 ? 0 : 7;
        int dec2 = $3.type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f <= %.*f is always %s\n", lineNumber, dec1,$1.val, dec2, $3.val, $1.val <= $3.val ? "true" : "false");
        hasErrors = true;
    }
}
            |   exp_op OP_EQ exp_op { $$.type = checkValuesComparison($1.type, $3.type); $$.hasVal=0;
    if($1.hasVal && $3.hasVal && !isInException) {
        int dec1 = $1.type == 2 ? 0 : 7;
        int dec2 = $3.type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f == %.*f is always %s\n", lineNumber, dec1,$1.val, dec2, $3.val, $1.val == $3.val ? "true" : "false");
        hasErrors = true;
    }
}
            |   exp_op OP_NEQ exp_op { $$.type = checkValuesComparison($1.type, $3.type); $$.hasVal=0;
    if($1.hasVal && $3.hasVal && !isInException) {
        int dec1 = $1.type == 2 ? 0 : 7;
        int dec2 = $3.type == 2 ? 0 : 7;
        printf("Logical error at line %d: value of comparison %.*f != %.*f is always %s\n", lineNumber, dec1,$1.val, dec2, $3.val, $1.val != $3.val ? "true" : "false");
        hasErrors = true;
    }
}
            |   exp_op OP_AND exp_op { $$.type = checkLogicOperation($1.type, $3.type); $$.hasVal=0; }
            |   exp_op OP_OR exp_op { $$.type = checkLogicOperation($1.type, $3.type); $$.hasVal=0; }
            |   OP_NOT exp_op { $$.type = checkLogicOperation($2.type, $2.type); $$.hasVal=0; }
            |   var_value OP_ASSIGN exp_op { $$.type = singleAsignation($1, $3.type); $$.hasVal=0; }
            |   var_value OP_ADD_ASSIGN exp_op { $$.type = checkSumAsignation($1, $3.type); $$.hasVal=0; }
            |   var_value OP_SUB_ASSIGN exp_op { $$.type = checkAsignation($1, $3.type); $$.hasVal=0; }
            |   var_value OP_MUL_ASSIGN exp_op { $$.type = checkAsignation($1, $3.type); $$.hasVal=0; }
            |   var_value OP_DIV_ASSIGN exp_op { $$.type = checkAsignation($1, $3.type); $$.hasVal=0; }
            |   var_value OP_MOD_ASSIGN exp_op { $$.type = checkAsignation($1, $3.type); $$.hasVal=0; }
            |   LEFT_PARENT exp_op RIGHT_PARENT { $$.type = $2.type; $$.hasVal=$2.hasVal; if($2.hasVal) { $$.val = $2.val; } }
            |   value_data { $$.type = $1.type; $$.hasVal = $1.hasVal; if($1.hasVal) { $$.val = $1.val; }; }
            |   func_call { $$.type = $1; $$.hasVal = 0;
    if ($1 == -1) {
        printf("Incompatible type error at line %d: the function called has no a return value\n", lineNumber);
        hasErrors = true;
    }
}
            |   inc_dec { $$.type = $1; $$.hasVal = 0; };

inc_dec     :   var_value ops_inc_dec { $$ = checkIncrementDecrement($1); } | ops_inc_dec var_value { $$ = checkIncrementDecrement($2); };

ops_inc_dec :   OP_INC | OP_DEC;

func_call   :   IDENTIFIER LEFT_PARENT RIGHT_PARENT { $$ = getSymbType($1, true); }
            |   IDENTIFIER LEFT_PARENT func_args RIGHT_PARENT { $$ = getSymbType($1, true); };

func_args   :   func_arg | func_arg COMMA func_args | func_arg COMMA n_line func_args;

func_arg    :   IDENTIFIER COLON exp_op | exp_op;

asingn      :   var_value OP_ASSIGN exp_op { singleAsignation($1, $3.type); }
            |   var_value OP_ADD_ASSIGN exp_op { checkSumAsignation($1, $3.type); }
            |   var_value ops_asingn exp_op { checkAsignation($1, $3.type); };

ops_asingn  :   OP_SUB_ASSIGN | OP_MUL_ASSIGN | OP_DIV_ASSIGN | OP_MOD_ASSIGN;
%%

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
