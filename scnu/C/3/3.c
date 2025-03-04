#include <stdio.h>

int main() {
    char input;
    scanf("%c", &input);

    char prev = input - 1;
    char next = input + 1;

    // 按照从小到大的顺序输出字符
    if (prev < input && input < next) {
        printf("%c %c %c\n", prev, input, next);
        printf("%d %d %d\n", prev, input, next);
    } else if (input < prev && prev < next) {
        printf("%c %c %c\n", input, prev, next);
        printf("%d %d %d\n", input, prev, next);
    } else {
        printf("%c %c %c\n", input, next, prev);
        printf("%d %d %d\n", input, next, prev);
    }

    return 0;
}