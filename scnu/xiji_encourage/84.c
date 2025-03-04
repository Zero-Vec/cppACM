#include <stdio.h>
int main()
{
    FILE *f;
    f = fopen("input.c", "r");
    char c[1000];
    int i, count = 0, num = 0, a[50], x = 0, y = 0; // x为“{”数目，y为“}”数目,数组a中1代表“{”，-1代表“}”
    int flag = 1, k = 0;                            // k用来判断右边括号是否超过左边
    while (!feof(f))
        fscanf(f, "%c", &c[count++]); // 以字符形式输入
    for (i = 0; i < count; i++)
    {
        if (c[i] == '/' && c[i + 1] == '*') // 排除注释中的括号
        {
            i++;
            while (c[i] != '*' || c[i + 1] != '/')
            {
                i++;
            }
            i += 2;
        }
        if (c[i] == '{')
        {
            k++;
            a[num++] = 1;
            x++;
        }
        if (c[i] == '}')
        {
            k--;
            a[num++] = -1;
            y++;
        }
        if (k < 0 && flag == 1) // 右花括号超过左花括号,判断flag==1即防止不匹配后又对flag的值修改(易忽略)
            flag = 0;
    }
    if (x != y)
        flag = 0;
    printf("%d\n", flag);
    for (i = 0; i < num; i++)
    {
        if (a[i] == 1)
            printf("{");
        else
            printf("}");
    }
    fclose(f);
    return 0;
}
