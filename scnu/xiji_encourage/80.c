#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //toupper(c)  tolower('A') 转换字符大小写
// 获得中括号中的字符串
void getPiece(char str[], char piece[], int pos)
{
    int i = 0;
    while (str[pos] != ']')
    {
        piece[i++] = str[pos++];
    }
}
// 判断字符c是否在字符串str中出现
int isin(char str[], char c)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (toupper(c) == toupper(str[i]))
            return 1;
    }
    return 0;
}
// 匹配字符串
int match(char str_in[], char str_scan[], char str_out[], int pos_in_start)
{
    int pos_in = pos_in_start, pos_scan = 0, pos_out = 0; // 三个字符串中的当前字符位置
    int pos_in_end = strlen(str_in);                      // pos_in < pos_in_end
    while (pos_in < pos_in_end)
    { // 最多将读入串遍历完
        if (str_scan[pos_scan] == '*')
        {                                         // 匹配到了‘*’
            if (pos_scan == strlen(str_scan) - 1) // 输入串中‘*’为最后一个字符
                while (pos_in < pos_in_end)       // 将读入串中剩余字符全部存入写入串
                    str_out[pos_out++] = str_in[pos_in++];
            else
            {                                                                                             // 输入串中‘*’不是最后一个字符
                while (pos_in < pos_in_end && toupper(str_in[pos_in]) != toupper(str_scan[pos_scan + 1])) // 循环到读入串与‘*’后一个字符匹配
                    str_out[pos_out++] = str_in[pos_in++];
                if (pos_in == pos_in_end)
                    return 0; // 如果是因为读入串被遍历完，匹配失败
                pos_scan++;   // 跳过‘*’
            }
        }
        else if (str_scan[pos_scan] == '[')
        {                                           // 匹配到‘[’
            char piece[50] = {'\0'};                // 储存‘[’内的字符串
            getPiece(str_scan, piece, ++pos_scan);  // 获得‘[’内的字符串
            int flag = isin(piece, str_in[pos_in]); // 判断读入串当前字符是否在中括号内出现过
            if ((piece[0] == '^' && flag) || (piece[0] != '^' && !flag))
                return 0;
            str_out[pos_out++] = str_in[pos_in++];
            pos_scan += strlen(piece) + 1; // 跳过中括号
        }
        else
        {                                                               // 匹配到字母
            if (toupper(str_in[pos_in]) != toupper(str_scan[pos_scan])) // 不匹配
                return 0;
            str_out[pos_out++] = str_in[pos_in++];
            pos_scan++;
        }
        if (pos_scan == strlen(str_scan))
            return 1; // 输入串被遍历完，匹配成功
    }
    return 1;
}

int main()
{
    char str_scan[100], str_in[1000];
    int line = 0, i;
    FILE *fin = fopen("string.in", "r"), *fout = fopen("string.out", "w");
    if (!fin || !fout)
        exit(1);
    scanf("%s", str_scan); // 获得输入串
    while (fgets(str_in, 100, fin))
    {           // 获得读入串
        line++; // 读入串的行数
        int flag = 1;
        strcpy(str_in, str_in);
        for (i = 0; str_in[i] != '\0'; i++)
        {
            char str_out[100] = {'\0'}; // 输出串
            if (match(str_in, str_scan, str_out, i))
            { // 匹配成功则输入到文件
                if (flag)
                    fprintf(fout, "%d:", line);
                else
                    fprintf(fout, ",");
                fprintf(fout, "%s", str_out);
                flag = 0;
            }
        }
        if (!flag)
            fprintf(fout, "\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
