#include <stdio.h>
#define N 12
int a[N][N], b[N][N], c[N][N];
int n;
int _0(int a[][N], int n, int b[][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = a[i][j];
            if (b[i][j] != c[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int _90(int a[][N], int n, int b[][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = a[n - j + 1][i];
            if (b[i][j] != c[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int _180(int a[][N], int n, int b[][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = a[n - i + 1][n - j + 1];
            if (b[i][j] != c[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int _270(int a[][N], int n, int b[][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = a[j][n - i + 1];
            if (b[i][j] != c[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    if (_0(a, n, b))
    {
        printf("0\n");
        return 0;
    }
    else if (_90(a, n, b))
    {
        printf("90\n");
        return 0;
    }
    else if (_180(a, n, b))
    {
        printf("180\n");
        return 0;
    }
    else if (_270(a, n, b))
    {
        printf("270\n");
        return 0;
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}