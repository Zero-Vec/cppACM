#include <stdio.h>
char ch[51], str[100000], ab[] = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    FILE *fp, *pp;
    fp = fopen("encrypt.txt", "r");
    pp = fopen("output.txt", "w"); // 打开需要的文件
    int i = 0, j = 0, k = 0, lench = 0, flag = 0, n = 0, lenstr = 0;
    char hold, p;
    scanf("%s", ch); // 读取密匙
    p = fgetc(fp);
    lench = strlen(ch);         // 获得密匙长度
    for (i = 0; i < lench; i++) // 从前向后遍历密匙
    {
        for (j = i + 1; j < lench; j++) // 寻找该字符后面是否有重复的
        {
            if (ch[i] == ch[j]) // 如果有
            {
                for (k = j; k < lench; k++)
                    ch[k] = ch[k + 1]; // 将重复字符后面的字符都向前移一位
                lench--;               // 密匙删掉一个字符，长度减一
                j--;                   // 此时ch【j】已经是新的字符，因为for循环里j++，这里的j要减一
            }
        }
    } // 将密匙中的重复字符删去
    lench = strlen(ch); // 更新处理后的密匙长度
    for (i = 0, j = 25; i < j; i++, j--)
    {
        hold = ab[j];
        ab[j] = ab[i];
        ab[i] = hold;
    } // 将ab中的字符倒过来，其实这一步没必要，在下一个for循环中从后向前就行
    for (i = 0, n = 0; i < 26; i++)
    {
        flag = 0;
        for (j = 0; j < lench; j++)
        {
            if (ab[i] == ch[j])
            {
                flag = 1;
                break;
            }
        } // 寻找ab中对应的字母是否已经在密匙中
        if (flag == 0)
        {
            ch[lench + n] = ab[i];
            n++;
        } // 如果没有，则将其加入密匙中
    }
    lench = strlen(ch); // 更新密匙长度，这里的长度应该等于26
    for (i = 0, j = 25; i < j; i++, j--)
    {
        hold = ab[j];
        ab[j] = ab[i];
        ab[i] = hold;
    } // 再将ab倒过来，所以上文中说没有必要
    while (p != EOF)
    {
        for (j = 0; j < 26; j++)
        {
            if (p == ab[j])
            {
                p = ch[j];
                break;
            }
        } // 将读取到的字符进行替换
        fputc(p, pp);  // 然后输出
        p = fgetc(fp); // 再次读入下一个字符
    }
    fclose(fp);
    fclose(pp); // 关闭文件
}