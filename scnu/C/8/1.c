#include<stdio.h>

int main()
{
    int d1, d2;
    char op;
    scanf("%d %d %c", &d1, &d2, &op);
    if(op == '+'){
        printf("%d", d1 + d2);
    }
    else if(op == '-'){
        printf("%d", d1 - d2);
    }
    else if(op == '*'){
        printf("%d", d1 * d2);
    }
    else if(op == '/'){
        if(d1 % d2 == 0){
            printf("%d", d1 / d2);
        }
        else{
            printf("%.2f", (float)d1 / d2);
        }
    }
    return 0;
}