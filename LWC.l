%{
#include <stdio.h>

int lc=0,sc=0,wc=0,cc=0
%}

%%

[\n] {lc++; cc+=yyleng;}
[ \t] {sc++; cc+=yyleng;}
[^\t\n ]+ {wc++; cc+=yyleng;}
%%

int main()
{
    printf("Enter text:\n");
    yylex();

    printf("\nLines : %d\n", lc);
    printf("Words : %d\n", wc);
    printf("Characters : %d\n", cc);

    return 0;
}

int yywrap()
{
    return 1;
}