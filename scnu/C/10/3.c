#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N[9][9], M[9][9], n, m;
    int i, j;
    bool begain = false;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &N[i][j]);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &M[i][j]);
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j <= n - m; j++)
        {
            if (N[i][j] == M[0][0])
                if (N[i + m - 1][j] == M[m - 1][0] && N[i][j + m - 1] == M[0][m - 1] && N[i + m - 1][j + m - 1] == M[m - 1][m - 1])
                {
                    int i1, j1;
                    for (i1 = 0; i1 < m; i1++)
                        for (j1 = 0; j1 < m; j1++)
                            if (N[i + i1][j + j1] != M[i1][j1])
                                break;
                    if (i1 == m && j1 == m)
                        begain = true;
                }
            if (begain)
                break;
        }
        if (begain)
            break;
    }
    if (begain)
        printf("%d,%d\n", i + 1, j + 1);
    else
        printf("-1\n");
    return 0;
}