#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_INPUT_LENGTH 20

void solve(const char *inputFile, const char *outputFile, const char *targetString)
{
    FILE *input = fopen(inputFile, "r");
    if (input == NULL)
    {
        printf("无法打开输入文件 %s\n", inputFile);
        return;
    }

    FILE *output = fopen(outputFile, "w");
    if (output == NULL)
    {
        printf("无法打开输出文件 %s\n", outputFile);
        fclose(input);
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, input) != NULL)
    {
        int lineLength = strlen(line);
        char markedLine[MAX_LENGTH];
        int markedIndex = 0;

        for (int i = 0; i < lineLength; ++i)
        {
            int matchLength = 0;
            while (i + matchLength < lineLength &&
                   tolower(line[i + matchLength]) == tolower(targetString[matchLength]))
            {
                matchLength++;
            }

            if (matchLength == strlen(targetString))
            {
                // 找到匹配字符串，添加引号包裹的匹配字符串到标记后的行
                strncpy(markedLine + markedIndex, "\"", 1);
                markedIndex++;
                strncpy(markedLine + markedIndex, line + i, matchLength);
                markedIndex += matchLength;
                strncpy(markedLine + markedIndex, "\"", 1);
                markedIndex++;
                i += matchLength - 1;
            }
            else
            {
                // 未找到匹配，添加当前字符到标记后的行
                markedLine[markedIndex] = line[i];
                markedIndex++;
            }
        }

        markedLine[markedIndex] = '\0';
        fputs(markedLine, output);
    }

    fclose(input);
    fclose(output);
}

int main()
{
    char targetString[N];
    scanf("%s", targetString);

    solve("filein.txt", "fileout.txt", targetString);

    return 0;
}