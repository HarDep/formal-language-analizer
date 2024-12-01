%{
#include "sintax_analizer.tab.h"
#include <string.h>
#include <stdbool.h>
bool hasErrors = false;
bool isComment = false;
int lineNum = 1;
char* currVar = NULL;
%}
alpha               [a-zA-Z]
digit               [0-9]
alnum               {alpha}|{digit}|\_
text                [ -~]
IDENTIFIER          {alpha}+{alnum}*
CHAR                \'{text}\'
STRING              \"{text}*\"|\'{text}*\'
COMMENT_LINE        \/\/.*
COMMENT_INIT        \/\*.*
COMMENT_FINAL       .*\*\/
%%
{COMMENT_LINE}                          {/*do nothing*/}
{COMMENT_INIT}                          {isComment = true;}
{COMMENT_FINAL}                         {isComment = false;}
char                                    {if (!isComment) {return CHAR_KW;}}
int                                     {if (!isComment) {return INT_KW;}}
float                                   {if (!isComment) {return FLOAT_KW;}}
bool                                    {if (!isComment) {return BOOL_KW;}}
string                                  {if (!isComment) {return STRING_KW;}}
void                                    {if (!isComment) {return VOID_KW;}}
if                                      {if (!isComment) {return IF_KW;}}
else                                    {if (!isComment) {return ELSE_KW;}}
switch                                  {if (!isComment) {return SWITCH_KW;}}
case                                    {if (!isComment) {return CASE_KW;}}
default                                 {if (!isComment) {return DEFAULT_KW;}}
for                                     {if (!isComment) {return FOR_KW;}}
while                                   {if (!isComment) {return WHILE_KW;}}
do                                      {if (!isComment) {return DO_KW;}}
return                                  {if (!isComment) {return RETURN_KW;}}
break                                   {if (!isComment) {return BREAK_KW;}}
true                                    {if (!isComment) {return TRUE_KW;}}
false                                   {if (!isComment) {return FALSE_KW;}}
function                                {if (!isComment) {return FUNCTION_KW;}}
try                                     {if (!isComment) {return TRY_KW;}}
catch                                   {if (!isComment) {return CATCH_KW;}}
finally                                 {if (!isComment) {return FINALLY_KW;}}
throw                                   {if (!isComment) {return THROW_KW;}}
\+\+                                    {if (!isComment) {return OP_INC;}}
\+\=                                    {if (!isComment) {return OP_ADD_ASSIGN;}}
\+                                      {if (!isComment) {return OP_ADD;}}
\-\-                                    {if (!isComment) {return OP_DEC;}}
\-\=                                    {if (!isComment) {return OP_SUB_ASSIGN;}}
\-                                      {if (!isComment) {return OP_SUB;}}
\*\=                                    {if (!isComment) {return OP_MUL_ASSIGN;}}
\*                                      {if (!isComment) {return OP_MUL;}}
\/\=                                    {if (!isComment) {return OP_DIV_ASSIGN;}}
\/                                      {if (!isComment) {return OP_DIV;}}
\%\=                                    {if (!isComment) {return OP_MOD_ASSIGN;}}
\%                                      {if (!isComment) {return OP_MOD;}}
\&\&                                    {if (!isComment) {return OP_AND;}}
\|\|                                    {if (!isComment) {return OP_OR;}}
\=\=                                    {if (!isComment) {return OP_EQ;}}
\=                                      {if (!isComment) {return OP_ASSIGN;}}
\!\=                                    {if (!isComment) {return OP_NEQ;}}
\!                                      {if (!isComment) {return OP_NOT;}}
\>\=                                    {if (!isComment) {return OP_GTE;}}
\>                                      {if (!isComment) {return OP_GT;}}
\<\=                                    {if (!isComment) {return OP_LTE;}}
\<                                      {if (!isComment) {return OP_LT;}}
\(                                      {if (!isComment) {return LEFT_PARENT;}}
\)                                      {if (!isComment) {return RIGHT_PARENT;}}
\{                                      {if (!isComment) {return LEFT_BRACKET;}}
\}                                      {if (!isComment) {return RIGHT_BRACKET;}}
\,                                      {if (!isComment) {return COMMA;}}
\:\:                                    {if (!isComment) {return D_COLON;}}
\:                                      {if (!isComment) {return COLON;}}
{IDENTIFIER}                            {if (!isComment) {yylval.sval = strdup(yytext);return IDENTIFIER;}}
{CHAR}                                  {if (!isComment) {return CHAR;}}
{STRING}                                {if (!isComment) {return STRING;}}
{digit}+\.{digit}+                      {if (!isComment) {yylval.dval = atof(yytext);return NUM_DEC;}}
{digit}+                                {if (!isComment) {yylval.dval = atof(yytext);return NUM;}}
\n                                      {lineNum++;if (!isComment) {return EOL;}}
[ \t\r\f]                               {/* Ignore spaces */}
.                                       {printf("Lexical error at line %d, cannot recognize the token: %s\n", lineNum, yytext);hasErrors = true;}
%%

int yywrap() { return 1; }
