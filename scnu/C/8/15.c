#include<stdio.h>

int fac(int n){
    if(n <= 1)
        return 1;
    return n * fac(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fac(n));
    return 0;
}