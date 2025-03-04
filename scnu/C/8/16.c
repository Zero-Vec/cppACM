#include<stdio.h>
#include<string.h>

char *insert(char *string, char c){
    int i = 0;
    int len = strlen(string);
    while(string[i] < c && string[i] != '\0'){
        i++;
    }
    for (int j = len; j >= i;j--){
        string[j + 1] = string[j];
    }
    string[i] = c;
    string[len + 1] = '\0';
    return string;
}

int main()
{
    // char a = 'a', b = 'b';
    // int c = b < a;
    // printf("%d\n", c);
    char string[100];
    char c;
    scanf("%s", &string);
    scanf(" %c", &c);
    printf("%s\n", insert(string, c));
    return 0;
}