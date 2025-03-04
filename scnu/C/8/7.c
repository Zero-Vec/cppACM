#include<stdio.h>
#include<math.h>

int isprime(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    for (int i = 2; i <= sqrt(n);i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", isprime(n));
    return 0;
}