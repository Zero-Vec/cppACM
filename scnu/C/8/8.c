#include <stdio.h>

int check(int num) {
    int square = num * num;
    int temp = num;
    while (temp > 0) {
        if (temp % 10 != square % 10) {
            return 0;
        }
        temp /= 10;
        square /= 10;
    }
    return 1;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i <= b; i++) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}