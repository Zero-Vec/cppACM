#include <stdio.h>
#include <math.h>

int main()
{
    double x, e;
    scanf("%lf %lf", &x, &e);
    double cos_x = 1.0;
    double term = 1.0;
    int n = 0;
    int sign = -1; 
    do
    {
        n++;
        term *= (x * x) / ((2 * n - 1) * (2 * n));
        cos_x += sign * term; 
        sign = -sign;
    } while (fabs(term) > e);
    printf("%d %.7lf\n", n, cos_x);
    return 0;
}
