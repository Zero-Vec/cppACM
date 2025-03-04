#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itob(int n, char s[], int b) {
    const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int i = 0, sign = n;

    if (b < 2 || b > 36) {
        fprintf(stderr, "Base %d is not supported.\n", b);
        exit(1);
    }

    if (sign < 0) {
        n = -n;
    }

    do {
        s[i++] = digits[n % b];
        n /= b;
    } while (n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    // Reverse the string
    for (int j = 0, k = strlen(s) - 1; j < k; j++, k--) {
        char temp = s[j];
        s[j] = s[k];
        s[k] = temp;
    }
}

int main() {
    int n, b;
    char s[100];

    if (scanf("%d %d", &n, &b) != 2) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    itob(n, s, b);
    printf("%s\n", s);

    return 0;
}