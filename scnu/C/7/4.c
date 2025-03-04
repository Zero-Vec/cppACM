#include <stdio.h>

void primeFactorization(int n) {
    int factor = 2;
    int first = 1;

    while (n > 1) {
        while (n % factor == 0) {
            if (first) {
                printf("%d", factor);
                first = 0;
            } else {
                printf(" %d", factor);
            }
            n /= factor;
        }
        factor++;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    if (N < 2 || N > 65535) {
        return 1;
    }

    primeFactorization(N);

    return 0;
}