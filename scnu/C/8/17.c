#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int q = a % 10, bai = b % 10, shi = a / 10, ge = b / 10;
    printf("%d\n", q * 1000 + bai * 100 + shi * 10 + ge);
    return 0;
}