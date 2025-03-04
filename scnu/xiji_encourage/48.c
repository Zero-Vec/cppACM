#include <stdio.h>

// 加密
int encrypt(char *text, char *result, char *k)
{
    int l, i, j = 0, z = 0;
    for (l = 0; text[l] != '\0'; l++)
        ;
    for (i = 0; i < l; i++)
    {
        result[z] = (text[i] - 'a' + k[j] - 'a') % 26 + 'a';
        j++;
        z++;
    }
    return 0;
}

int main()
{
    char text[50] = "";
    char result[50] = "";
    char k[50] = "";
    int type;

    scanf("%s", k);
    scanf("%s", text);

    /**加密**/
    encrypt(text, result, k);
    printf("%s\n", text, result);

    return 0;
}
