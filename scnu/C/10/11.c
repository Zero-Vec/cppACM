#include <stdio.h>
#include <string.h>

void mergeStrings(char *str1, char *str2, char *result) {
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
}

int main() {
    char str1[51], str2[51], result[102];
    scanf("%50s", str1);
    scanf("%50s", str2);

    mergeStrings(str1, str2, result);
    printf("%s\n", result);

    return 0;
}