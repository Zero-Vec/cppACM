#include<stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 100; i <= N;i++){
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100;
        if(a*a*a + b*b*b + c*c*c == i)
            printf("%d\n", i);
    }
    return 0;
}