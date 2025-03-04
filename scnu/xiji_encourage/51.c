#include <stdio.h>
int main()
{
    char char1[50], char2[50], a[50], b[50]; // a[]代表公共字符串，b[]代表最长公共字符串
    int i, j, s = 0, k = 0;
    gets(char1);
    gets(char2);
    for (i = 0; i < 50; i++)
    {
        if (char1[i] != 0)
        {
            for (j = 0; j < 50; j++)
            {
                if (char2[j] == 0)
                    break;
                else
                {
                    if (char1[i] == char2[j])
                    {
                        while (char1[i] == char2[j])
                        {
                            a[k] = char1[i], k++; // 输出当前的公共字符串
                            i++, j++;
                        }
                        if (k > s) // 判断是否是最长公共字符串
                        {
                            int t;
                            for (t = 0; t < k; t++)
                            {
                                b[t] = a[t];
                                s = k;
                            }
                        }
                        k = 0;
                    }
                }
            }
        }
    }
    if (s == 0)
        printf("No Answer");
    else
        for (i = 0; i < s; i++)
            printf("%c", b[i]);
    return 0;
}
