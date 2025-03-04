#include<stdio.h>

int getsum(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        printf("%d ", getsum(x));
    }
    return 0;
}