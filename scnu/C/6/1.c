#include <stdio.h>

void sort(float *a, float *b, float *c) {
    float temp;
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main() {
    float num1, num2, num3;

    scanf("%f %f %f", &num1, &num2, &num3);

    sort(&num1, &num2, &num3);

    printf("%g %g %g\n", num1, num2, num3);

    return 0;
}