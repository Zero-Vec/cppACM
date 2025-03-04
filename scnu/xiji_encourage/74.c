#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 1000

void solve(const char *file_path)
{
    const char *keywords[] = {"while", "for", "if"};
    int cnt = 3;
    char line[N];
    FILE *file = fopen(file_path, "r");
    bool tag = false;
    int line_num = 0;

    while (fgets(line, N, file) != NULL)
    {
        line_num++;
        int i = 0;

        while (line[i] != '\0')
        {
            if (line[i] == '"')
            { // 检测字符串的起止
                tag = !tag;
                i++;
            }
            else if (!tag)
            {
                for (int k = 0; k < cnt; k++)
                {
                    const char *keyword = keywords[k];
                    int keyword_len = strlen(keyword);

                    // 检查是否匹配关键字
                    if (strncmp(&line[i], keyword, keyword_len) == 0 &&
                        (i == 0 || !(line[i - 1] >= 'a' && line[i - 1] <= 'z') && !(line[i - 1] >= 'A' && line[i - 1] <= 'Z') && !(line[i - 1] >= '0' && line[i - 1] <= '9')) &&
                        (!(line[i + keyword_len] >= 'a' && line[i + keyword_len] <= 'z') && !(line[i + keyword_len] >= 'A' && line[i + keyword_len] <= 'Z') && !(line[i + keyword_len] >= '0' && line[i + keyword_len] <= '9')))
                    {
                        printf("%s:%d,%d\n", keyword, line_num, i + 1);
                    }
                }
                i++;
            }
            else
            {
                i++;
            }
        }
    }

    fclose(file);
}

int main()
{
    const char *file_path = "in.c";
    solve(file_path);
    return 0;
}
