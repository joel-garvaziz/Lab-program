#include <stdio.h>

int main()
{
    char lhs, a, b, c, op1, op2, temp;
    int count = 1;

    printf("Enter expression: ");

    scanf("%c=%c%c%c%c%c", &lhs, &a, &op1, &b, &op2, &c);

    if (op2 == '*' || op2 == '/')
    {
        printf("t%d = %c %c %c\n", count, b, op2, c);

        temp = '0' + count;
        count++;

        printf("t%d = %c %c %c\n", count, a, op1, temp);
    }
    else
    {
        printf("t%d = %c %c %c\n", count, a, op1, b);

        temp = '0' + count;
        count++;

        printf("t%d = %c %c %c\n", count, temp, op2, c);
    }

    printf("%c = t%d\n", lhs, count);

    return 0;
}