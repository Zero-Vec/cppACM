#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0];
    int min = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("%d %d\n", max, min);
    return 0;
}