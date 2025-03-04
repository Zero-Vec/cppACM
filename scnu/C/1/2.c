#include<stdio.h>

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%d\n", x + y + z);
    printf("%.2f\n", (float)(x + y + z) / 3);
    return 0;
}