%{
struct alpha_token_t {
  unsigned int     numline;
  unsigned int     numToken;
  char          *content;
  char          *type;
  char          *message;
  struct alpha_token_t *next;
};
struct alpha_token_t* Head=NULL;
int num_lines=1;

#include "parser.h"

%}
%option noyywrap
%option yylineno
digit [0-9]
id [a-zA-Z][a-zA-Z_0-9]*
string \"(?:\\.|[^\"])*\"
comment "//".* 

%x COMMENT NESTED

%%

"/*"    BEGIN(COMMENT);

<COMMENT>[^*/]+   
<COMMENT>"*"+[^*/]*   
<COMMENT>"*/"   BEGIN(INITIAL);  

<COMMENT>"/*" BEGIN(NESTED);

<NESTED>[^*/]+    
<NESTED>"*"+[^*/]*   
<NESTED>"*/"   BEGIN(COMMENT);  


\/\*([^*]|\*[^/]|[\r\n])*\Z 

[ \t] 

{digit}+    {yylval.intVal=atoi(yytext);return NUMBER;}
{digit}+"."{digit}*   {yylval.intVal=atoi(yytext);return NUMBER;}

"if"    {return IF;}
"else"  {return ELSE;}
"while" {return WHILE;}
"for"   {return FOR;}
"function"  {return FUNCTION;}
"return"    {return RETURN;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"and"  {return AND;}
"not" {return NOT;}
"or" {return OR;}
"local" {return LOC;}
"true" {return TRUE;}
"false" {return FALSE;}
"nil"  {return NIL;}

"==" {return EQUAL_TO;}
"++" {return PLUS_PLUS;}
"--" {return MINUS_MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"=" {return ASSIGNMENT;}
"!=" {return NOT_EQUAL_TO;}
"+" {return PLUS;}
"-" {return MINUS;}
">=" {return GREATER_THAN_OR_EQUAL;}
"<=" {return LESS_THAN_OR_EQUAL;}
">" {return GREATER_THAN;}
"<" {return LESS_THAN;}

"(" {return LEFT_PARENTHESIS;}
")" {return RIGHT_PARENTHESIS;}
"{" {return LEFT_BRACE;}
"}" {return RIGHT_BRACE;}
"[" {return LEFT_BRACKET;}
"]" {return RIGHT_BRACKET;}
";" {return SEMICOLON;}
"," {return COMMA;}
":" {return COLON;}
"::" {return DOUBLE_COLON;}
"." {return DOT;}
".." {return DOUBLE_DOT;}

{id} {yylval.stringVal=strdup(yytext);return ID;}
{string} {yylval.stringVal=strdup(yytext);return STRING;}
{comment} {}
\n      num_lines++;

%%
