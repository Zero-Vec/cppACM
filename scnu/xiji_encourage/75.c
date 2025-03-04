#include <stdio.h>
int main()
{
    int n, a[10][10], i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int row1, row2, col1, col2;
    for (i = 0; i < n; i++) // 行
    {
        for (j = 0; j < n; j++) // 第一个1
            if (a[i][j] == 1)
            {
                col1 = j;
                break;
            }
        for (j = n; j >= 0; j--) // 最后一个1
            if (a[i][j] == 1)
            {
                col2 = j;
                break;
            }
        for (j = col1 + 1; j < col2; j++) // 两个1之间
            if (a[i][j] != 1)
                a[i][j] += 2;
    }
    for (j = 0; j < n; j++) // 列
    {
        for (i = 0; i < n; i++) // 第一个1
            if (a[i][j] == 1)
            {
                row1 = i;
                break;
            }
        for (i = n; i >= 0; i--) // 最后一个1
            if (a[i][j] == 1)
            {
                row2 = i;
                break;
            }
        for (i = row1 + 1; i < row2; i++)
            if (a[i][j] != 1)
                a[i][j] += 2;
    }
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (a[i][j] == 0 || a[i][j] == 2) // 4代表小岛，0和2代表水面
                count++;
    }
    printf("%d\n", count);
    return 0;
}
