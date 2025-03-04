#include<stdio.h>

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", gcd(a, b), a * b / gcd(a, b));
    return 0;
}