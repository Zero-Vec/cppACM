#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i, sum = 0, t = n;
    for (i = 1; i <= n;i++){
        sum += i * t;
        t--;
    }
    printf("%d\n", sum);
    return 0;
}