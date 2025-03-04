#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0'){
        len++;
    }
    if (!isalpha(str[0])){
        printf("0\n");
        return 0;
    }
    for (int i = 1; i < len; i++){
        if (!isalnum(str[i])){
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}