#include <stdio.h>
#include <string.h>
#include <ctype.h>

void del(char s[]) {
    int len = strlen(s);
    int seen[256] = {0};
    char result[len + 1];
    int index = len - 1;

    for (int i = len - 1; i >= 0; i--) {
        char lower = tolower(s[i]);
        if (!seen[lower]) {
            result[index--] = s[i];
            seen[lower] = 1;
        }
    }

    for (int i = index + 1, j = 0; i < len; i++, j++) {
        s[j] = result[i];
    }
    s[len - index - 1] = '\0';
}

int main() {
    char s[100];
    scanf("%s", s);
    del(s);
    printf("%s\n", s);
    return 0;
}