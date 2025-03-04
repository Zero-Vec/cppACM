#include <stdio.h>
#include <string.h>

void str_bin(char* str1, char* str2) {
    char result[201]; // Maximum length of combined string
    int i = 0, j = 0, k = 0;

    while (str1[i] != '\0' && str2[j] != '\0') {
        if (str1[i] < str2[j]) {
            if (k == 0 || result[k-1] != str1[i]) {
                result[k++] = str1[i];
            }
            i++;
        } else if (str1[i] > str2[j]) {
            if (k == 0 || result[k-1] != str2[j]) {
                result[k++] = str2[j];
            }
            j++;
        } else {
            if (k == 0 || result[k-1] != str1[i]) {
                result[k++] = str1[i];
            }
            i++;
            j++;
        }
    }

    while (str1[i] != '\0') {
        if (k == 0 || result[k-1] != str1[i]) {
            result[k++] = str1[i];
        }
        i++;
    }

    while (str2[j] != '\0') {
        if (k == 0 || result[k-1] != str2[j]) {
            result[k++] = str2[j];
        }
        j++;
    }

    result[k] = '\0';
    strcpy(str1, result);
}

int main() {
    char str1[101], str2[101];

    scanf("%100s", str1);
    scanf("%100s", str2);

    str_bin(str1, str2);

    printf("%s\n", str1);

    return 0;
}