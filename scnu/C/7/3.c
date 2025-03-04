#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[10][10];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d %d\n", n, m);
    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i >= 0; i--) {
            printf("%d", matrix[i][j]);
            if (i > 0) {
                printf(" ");
            }
        }
        if (j < n - 1) {
            printf("\n");
        }
    }
    return 0;
}