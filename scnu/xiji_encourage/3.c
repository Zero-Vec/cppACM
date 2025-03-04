#include <stdio.h>

int main()
{
    int x[100];
    int y[100];
    int n = 0;
    int i = 0;
    double s = 0;
    int sum1 = 0;
    int sum2 = 0;
    scanf("%d", &n);
    // 数据的输入
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    // Xi*Y(i+1)……n-1次
    for (i = 1; i < n; i++)
        sum1 += x[i] * y[i + 1];
    sum1 += x[i] * y[1];
    for (i = 1; i < n; i++)
        sum2 += y[i] * x[i + 1];
    sum2 += y[i] * x[1];
    s = (1 / 2.0) * (sum1 - sum2);
    if (s > 0)
        printf("%.2lf", s);
    else
        printf("%.2lf", -s);
}