#include<stdio.h>

int loop(int x){
    int t = x;
    int y = 0;
    while(t){
        y = y * 10 + t % 10;
        t /= 10;
    }
    return x == y;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b;i++){
        if(loop(i) && i % 2 == 0){
            printf("%d\n", i);
        }
    }
    // printf("%d", loop(121));
    return 0;
        
}