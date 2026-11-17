#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto","break","case","char","const","continue",
        "default","do","double","else","enum","extern",
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void",
        "volatile","while"
    };

    for(int i = 0; i < 32; i++) {
        if(strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int j = 0;

    fp = fopen("test.c", "r");

    if(fp == NULL) {
        printf("Error opening file");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF) {

        // Identify operators
        if(strchr("+-*/%=<>!&|", ch) != NULL) {
            printf("%c is an operator\n", ch);
        }

        // Identify identifiers and keywords
        if(isalnum((unsigned char)ch) || ch == '_') {
            buffer[j++] = ch;
        }
        else {
            if(j > 0) {
                buffer[j] = '\0';
                j = 0;

                if(isKeyword(buffer))
                    printf("%s is a keyword\n", buffer);

                else if(isdigit((unsigned char)buffer[0]))
                    printf("%s is a constant\n", buffer);

                else
                    printf("%s is an identifier\n", buffer);
            }

            // Identify special symbols
            if(strchr(";,(){}[]", ch) != NULL) {
                printf("%c is a special symbol\n", ch);
            }
        }
    }

    // Process the last token
    if(j > 0) {
        buffer[j] = '\0';

        if(isKeyword(buffer))
            printf("%s is a keyword\n", buffer);
        else if(isdigit((unsigned char)buffer[0]))
            printf("%s is a constant\n", buffer);
        else
            printf("%s is an identifier\n", buffer);
    }

    fclose(fp);
    return 0;
}
