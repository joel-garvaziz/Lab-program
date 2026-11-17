%{
#include <stdio.h>

int vowels = 0, consonants = 0;
%}

%%

[aAeEiIoOuU]                  { vowels++; }

[^aAeEiIoOuU] { consonants++; }

[ \t\n0-9]+                   ;

.                              ;

%%

int main()
{
    printf("Enter a string:\n");
    yylex();

    printf("\nNumber of Vowels     : %d\n", vowels);
    printf("Number of Consonants : %d\n", consonants);

    return 0;
}

int yywrap()
{
    return 1;
}