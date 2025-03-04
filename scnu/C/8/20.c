#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int same_set(int a[], int b[], int len) {
    qsort(a, len, sizeof(int), cmp);
    qsort(b, len, sizeof(int), cmp);

    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int len;
    scanf("%d", &len);

    int a[len], b[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < len; i++) {
        scanf("%d", &b[i]);
    }

    int result = same_set(a, b, len);
    printf("%d\n", result);

    return 0;
}