#include <stdio.h>
#include <ctype.h>

char p[20][20];
int n, f[26][128], g[26][128];

int main()
{
    int i, j, k, c;
    char a, b;

    printf("No of productions: ");
    scanf("%d", &n);

    printf("Enter productions: ");
    for(i = 0; i < n; i++)
        scanf("%s", p[i]);

    // FIRST
    do
    {
        c = 0;

        for(i = 0; i < n; i++)
        {
            a = p[i][0];
            b = p[i][2];

            if(!isupper(b))
            {
                if(!f[a-'A'][b])
                {
                    f[a-'A'][b] = 1;
                    c = 1;
                }
            }
            else
            {
                for(k = 0; k < 128; k++)
                {
                    if(f[b-'A'][k] && !f[a-'A'][k])
                    {
                        f[a-'A'][k] = 1;
                        c = 1;
                    }
                }
            }
        }
    } while(c);

    printf("\nFIRST\n");

    for(i = 0; i < n; i++)
    {
        a = p[i][0];

        printf("FIRST(%c) = { ", a);

        for(k = 0; k < 128; k++)
            if(f[a-'A'][k])
                printf("%c ", k);

        printf("}\n");
    }

    // FOLLOW
    g[p[0][0]-'A']['$'] = 1;

    do
    {
        c = 0;

        for(i = 0; i < n; i++)
        {
            for(j = 2; p[i][j]; j++)
            {
                if(isupper(p[i][j]))
                {
                    a = p[i][j];

                    if(p[i][j+1])
                    {
                        b = p[i][j+1];

                        if(!isupper(b))
                        {
                            if(!g[a-'A'][b])
                            {
                                g[a-'A'][b] = 1;
                                c = 1;
                            }
                        }
                        else
                        {
                            for(k = 0; k < 128; k++)
                            {
                                if(f[b-'A'][k] &&
                                   k != '#' &&
                                   !g[a-'A'][k])
                                {
                                    g[a-'A'][k] = 1;
                                    c = 1;
                                }
                            }

                            if(f[b-'A']['#'])
                            {
                                for(k = 0; k < 128; k++)
                                {
                                    if(g[p[i][0]-'A'][k] &&
                                       !g[a-'A'][k])
                                    {
                                        g[a-'A'][k] = 1;
                                        c = 1;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        for(k = 0; k < 128; k++)
                        {
                            if(g[p[i][0]-'A'][k] &&
                               !g[a-'A'][k])
                            {
                                g[a-'A'][k] = 1;
                                c = 1;
                            }
                        }
                    }
                }
            }
        }
    } while(c);

    printf("\nFOLLOW\n");

    for(i = 0; i < n; i++)
    {
        a = p[i][0];

        printf("FOLLOW(%c) = { ", a);

        for(k = 0; k < 128; k++)
            if(g[a-'A'][k])
                printf("%c ", k);

        printf("}\n");
    }

    return 0;
}

/*
E = TR
R = +TR
R = #
T = FY
Y = *FY
Y = #
F = (E)
F = i
*/