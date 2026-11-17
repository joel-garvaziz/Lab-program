#include <stdio.h>

int n, e[20][20], c[20][20], v[20];

void findClosure(int s, int start)
{
    int i;

    v[s] = 1;
    c[start][s] = 1;

    for (i = 0; i < n; i++)
    {
        if (e[s][i] && !v[i])
        {
            findClosure(i, start);
        }
    }
}

int main()
{
    int i, j, m, a, b;

    printf("Number of states: ");
    scanf("%d", &n);

    printf("Number of epsilon transitions: ");
    scanf("%d", &m);

    printf("Enter transitions (from to):\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        e[a][b] = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            v[j] = 0;

        findClosure(i, i);
    }

    printf("\nEpsilon Closure:\n");

    for (i = 0; i < n; i++)
    {
        printf("E-closure(q%d) = { ", i);

        for (j = 0; j < n; j++)
        {
            if (c[i][j])
                printf("q%d ", j);
        }

        printf("}\n");
    }

    return 0;
}
