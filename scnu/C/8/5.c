#include<stdio.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if(a > b)
        swap(&a, &b);
    if(a > c)
        swap(&a, &c);
    if(b > c)
        swap(&b, &c);
    printf("%g %g %g\n", a, b, c);
    return 0;
}