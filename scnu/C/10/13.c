#include <stdio.h>
#include <ctype.h>

int is_identifier(const char *str) {
    if (!isalpha(str[0])) {
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    scanf("%99s", str);

    if (is_identifier(str)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}