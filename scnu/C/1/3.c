#include <stdio.h>
#include<math.h>

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    float s = 1.0 * (x + y + z) / 2;

    printf("%.3f", sqrt(s * (s - x) * (s - y) * (s - z)));
    return 0;
}