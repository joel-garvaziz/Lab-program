// identifier.l
%{
#include "y.tab.h"
%}
%%
[a-zA-Z][a-zA-Z0-9]* { return ID; }
. { return yytext[0]; }
%%
int yywrap()
{
return 1; }


// identifier.y
%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(char *s);
int yylex();
%}
%token ID
%%
S : ID
{
printf("Valid Identifier\n"); }
;
%%
int main() {
printf("Enter the identifier: ");
yyparse();
return 0;
}
void yyerror(char *s)
{
printf("Invalid Identifier\n");
}