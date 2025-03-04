#include <stdio.h>

int main() {
    int spaces = 0, newlines = 0;
    char ch;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            spaces++;
        } else if (ch == '\n') {
            newlines++;
        }
    }

    printf("%d %d\n", spaces, newlines);
    return 0;
}