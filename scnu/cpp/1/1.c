#include<stdio.h>

int x, y, z;

int main()
{
    scanf("%d %d %d", &x, &y, &z);
    printf("%d\n", x + y + z);
    printf("%.2f", (x + y + z) / 3.0);
    return 0;
}