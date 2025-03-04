#include<stdio.h>

int weishu(int x){
    int c = 0;
    while(x){
        c++, x /= 10;
    }
    return c == 3;
}

int main()
{
    int x;
    scanf("%d", &x);
    if(weishu(x)){
        int a = x / 100;
        int b = x / 10 % 10;
        int c = x % 10;
        // printf("%d%d%d\n", c, b, a);
        if(c == 0 && b == 0){
            printf("%d\n", a);
        }
        else{
            printf("%d%d%d\n", c, b, a);
        }
    }
    else{
        printf("-1\n");
    }
    return 0;
}