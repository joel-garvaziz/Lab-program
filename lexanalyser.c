#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, j, k, id = 0, digit = 0, operator = 0;
    int keyword = 0, special = 0, flag;

    char e[50], buffer[50];

    char keywords[32][10] = {
        "auto","break","case","char","const","continue",
        "default","do","double","else","enum","extern",
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void",
        "volatile","while"
    };

    FILE *fp;

    fp = fopen("input.txt", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    while(fgets(e, sizeof(e), fp) != NULL)
    {
        for(i = 0; e[i] != '\0'; i++)
        {
            char ch = e[i];

            if(isalpha((unsigned char)ch) || ch == '_')
            {
                j = 0;

                while(isalnum((unsigned char)e[i]) || e[i] == '_')
                {
                    buffer[j++] = e[i++];
                }

                buffer[j] = '\0';
                i--;

                flag = 0;

                for(k = 0; k < 32; k++)
                {
                    if(strcmp(buffer, keywords[k]) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 1)
                {
                    printf("%s is a keyword\n", buffer);
                    keyword++;
                }
                else
                {
                    printf("%s is an identifier\n", buffer);
                    id++;
                }
            }

            else if(isdigit((unsigned char)ch))
            {
                printf("%c is a digit\n", ch);
                digit++;
            }

            else if(ch == '+' || ch == '-' || ch == '*' ||
                    ch == '/' || ch == '^')
            {
                printf("%c is an operator\n", ch);
                operator++;
            }

            else if(ch == ';' || ch == ',' || ch == '(' ||
                    ch == ')' || ch == '{' || ch == '}' ||
                    ch == '[' || ch == ']')
            {
                printf("%c is a special symbol\n", ch);
                special++;
            }

            else if(!isspace((unsigned char)ch))
            {
                printf("Invalid character: %c\n", ch);
            }
        }
    }

    fclose(fp);

    printf("\nTotal identifiers: %d\n", id);
    printf("Total digits: %d\n", digit);
    printf("Total operators: %d\n", operator);
    printf("Total keywords: %d\n", keyword);
    printf("Total special symbols: %d\n", special);

    printf("Total tokens: %d\n",
           id + digit + operator + keyword + special);

    return 0;
}