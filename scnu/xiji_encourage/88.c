#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define N 20

void solve(const char *inputFile, const char *outputFile, const char *target)
{
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, input) != NULL)
    {
        int len = strlen(line);
        char lines[MAX_LENGTH];
        int idx = 0;

        for (int i = 0; i < len; ++i)
        {
            int m_len = 0;
            while (i + m_len < len && line[i + m_len] == target[m_len])
            {
                m_len++;
            }

            if (m_len == strlen(target))
            {
                // 找到匹配字符串，添加引号包裹的匹配字符串到标记后的行
                strncpy(lines + idx, "\"", 1);
                idx++;
                strncpy(lines + idx, line + i, m_len);
                idx += m_len;
                strncpy(lines + idx, "\"", 1);
                idx++;
                i += m_len - 1;
            }
            else
            {
                // 未找到匹配，添加当前字符到标记后的行
                lines[idx] = line[i];
                idx++;
            }
        }

        lines[idx] = '\0';
        fputs(lines, output);
    }

    fclose(input);
    fclose(output);
}

int main()
{
    char s[N];
    scanf("%s", s);
    solve("filein.txt", "fileout.txt", s);
    return 0;
}
