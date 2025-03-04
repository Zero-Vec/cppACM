#include<stdio.h>

int main()
{
    int sum = 0;
    int a;
    scanf("%d", &a);
    while(a){
        sum += a % 10;
        a /= 10;
    }
    printf("%d\n", sum);
    return 0;
}