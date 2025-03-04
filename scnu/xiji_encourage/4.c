#include <stdio.h>

int check(int n) {
    int square = n * n;
    int t = n;
    while (t > 0) {
        if (t % 10 != square % 10) {
            return 0;
        }
        t /= 10;
        square /= 10;
    }
    return 1;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }
    for (int i = a; i <= b; i++) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
