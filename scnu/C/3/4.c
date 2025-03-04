#include <stdio.h>

#include <string.h>

int main()
{
    int i, j, n, m, flag = 0;
    char str[100], cut[50];
    gets(str);
    gets(cut);
    n = strlen(str);
    m = strlen(cut);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (str[i] == cut[j])
            {
                if (flag == 0)
                    flag = 1;
                break;
            }
        }
        if (j == m)
            if (flag == 1)
            {
                printf("\n%c", str[i]);
                flag = 0;
            }
            else
                printf("%c", str[i]);
    }
    return 0;
}
