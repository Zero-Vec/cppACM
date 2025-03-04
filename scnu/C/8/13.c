#include<stdio.h>

#define ll long long
ll fac[35];
int main()
{
    fac[0] = 1;
    for (int i = 1; i < 35;i++)
        fac[i] = fac[i - 1] * i;
    int n;
    scanf("%d", &n);
    double ans = 0.0;
    for (int i = 1; i <= n;i++)
        ans += 1.0 / fac[i];
    printf("%.10lf\n", ans + 1);
    return 0;
}