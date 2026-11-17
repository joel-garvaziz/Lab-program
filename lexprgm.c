
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], buffer[20];
    char keywords[32][10] = {
        "auto","break","case","char","const","continue",
        "default","do","double","else","enum","extern",
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void",
        "volatile","while"
    };

    int i, j, k, flag;

    printf("Enter an expression: ");
    scanf(" %[^\n]", str);

    for(i = 0; str[i] != '\0'; i++) {

        if(isalpha((unsigned char)str[i]) || str[i] == '_') {

            j = 0;

            while(isalnum((unsigned char)str[i]) || str[i] == '_') {
                buffer[j++] = str[i++];
            }

            buffer[j] = '\0';
            i--;

            flag = 0;

            for(k = 0; k < 32; k++) {
                if(strcmp(buffer, keywords[k]) == 0) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 1)
                printf("%s is a keyword\n", buffer);
            else
                printf("%s is an identifier\n", buffer);
        }

        else if(isdigit((unsigned char)str[i])) {
            printf("%c is a constant\n", str[i]);
        }

        else if(strchr("+-*/%=<>!", str[i]) != NULL) {
            printf("%c is an operator\n", str[i]);
        }

        else if(strchr(";,(){}[]", str[i]) != NULL) {
            printf("%c is a special symbol\n", str[i]);
        }
    }

    return 0;
}
