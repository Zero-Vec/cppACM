#include<stdio.h>

int cnt(int x){
    int c = 0;
    while(x){
        c++;
        x /= 10;
    }
    return c;
}

int main() {

    int a;
    scanf("%d", &a);
    printf("%d\n", cnt(a));
    printf("%d\n", a);
    while(a){
        printf("%d", a % 10);
        a /= 10;
    }
    return 0;
}