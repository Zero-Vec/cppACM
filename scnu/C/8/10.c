#include <stdio.h>
#include <string.h>

void formatNumber(char *num) {
    int len = strlen(num);
    int commas = (len - 1) / 3;
    int newLen = len + commas;
    char formatted[newLen + 1];
    formatted[newLen] = '\0';

    int j = newLen - 1;
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (count == 3) {
            formatted[j--] = ',';
            count = 0;
        }
        formatted[j--] = num[i];
        count++;
    }

    printf("%s\n", formatted);
}

int main() {
    char num[100];
    scanf("%s", num);
    formatNumber(num);
    return 0;
}