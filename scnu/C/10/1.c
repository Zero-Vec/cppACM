#include <stdio.h>
#include <ctype.h>

void expand(const char *s1, char *s2) {
    int i = 0, j = 0;
    char start, end;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' && s1[i - 1] < s1[i + 1]) {
            start = s1[i - 1] + 1;
            end = s1[i + 1];
            for (char c = start; c <= end; c++) {
                s2[j++] = c;
            }
            i++;
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}

int main() {
    char s1[100], s2[100];
    fgets(s1, sizeof(s1), stdin);

    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}