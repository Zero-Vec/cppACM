#include <stdio.h>
int main()
{
    int a[30], i, j, k, n;
    int b[30], max, len = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) // 排序从大到小
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }

    for (i = 0; i < n; i++) // 利用b数组记录连续升序子串的长度
    {
        b[i] = len;
        if (a[i + 1] - a[i] == 1)
        {
            len++;
        }
        else
        {
            len = 1;
        }
    }

    for (i = 0; i < n; i++) // 找出b数组中的最大值
    {
        if (b[i] > max)
            max = b[i];
    }
    printf("%d\n", max); // 输出连续升序子串的最大长度
    for (i = 0; i < n; i++)
    {
        if (b[i] == max)
        {
            int t;
            for (t = i - max + 1; t <= i; t++)
            {
                printf("%d ", a[t]);
            }
            printf("\n");
        }
    }
}