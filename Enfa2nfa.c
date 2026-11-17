#include <stdio.h>

#define MAX 20

int n;
int e[MAX][MAX];
int t[MAX][MAX][2];
int c[MAX][MAX];

void closure(int s, int x)
{
    int i;

    c[s][x] = 1;

    for (i = 0; i < n; i++)
    {
        if (e[x][i] && !c[s][i])
        {
            closure(s, i);
        }
    }
}

int main()
{
    int i, j, k, x;
    int ne, nt;
    int a, b, s;

    printf("States: ");
    scanf("%d", &n);

    printf("Epsilon transitions: ");
    scanf("%d", &ne);

    for (i = 0; i < ne; i++)
    {
        scanf("%d%d", &a, &b);
        e[a][b] = 1;
    }

    printf("Normal transitions: ");
    scanf("%d", &nt);

    for (i = 0; i < nt; i++)
    {
        scanf("%d%d%d", &a, &b, &s);
        t[a][b][s] = 1;
    }

    for (i = 0; i < n; i++)
    {
        closure(i, i);
    }

    printf("\nNFA without epsilon:\n");

    for (i = 0; i < n; i++)
    {
        for (s = 0; s < 2; s++)
        {
            printf("q%d --%d--> { ", i, s);

            for (j = 0; j < n; j++)
            {
                if (c[i][j])
                {
                    for (k = 0; k < n; k++)
                    {
                        if (t[j][k][s])
                        {
                            for (x = 0; x < n; x++)
                            {
                                if (c[k][x])
                                {
                                    printf("q%d ", x);
                                }
                            }
                        }
                    }
                }
            }

            printf("}\n");
        }
    }

    return 0;
}

/*
3
2
0 1
1 2
2
1 1 1
2 2 0   
*/