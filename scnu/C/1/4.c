#include <stdio.h>
#include <math.h>

int main()
{
    int s;
    scanf("%d", &s);

    int c10 = s / 10;
    s %= 10;
    int c5 = s / 5;
    s %= 5;
    int c2 = s / 2;
    s %= 2;
    int c1 = s / 1;
    printf("%d %d %d %d", c10, c5, c2, c1);
    return 0;
}