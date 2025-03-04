#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FUNC_NAME_LEN 20
#define MAX_CUSTOM_FUNCS 10

// 判断是否包含不需要的子串
int contains_unwanted_substring(const char *word) {
    return strstr(word, "getMax") || strstr(word, "getMin") || strstr(word, "get");
}

// 删除空白符和特定子串
void remove_whitespace_and_unwanted_strings(FILE *input, FILE *output) {
    int ch;
    char word[MAX_FUNC_NAME_LEN];
    int word_index = 0;
    int in_identifier = 0;

    while ((ch = fgetc(input)) != EOF) {
        // 跳过空白字符
        if (isspace(ch)) {
            continue;
        }

        // 检测标识符字符
        if (isalnum(ch) || ch == '_') {
            word[word_index++] = ch;
            in_identifier = 1;
        } else {
            // 处理完整的标识符
            if (in_identifier) {
                word[word_index] = '\0';
                // 检查是否包含不需要的子串
                if (!contains_unwanted_substring(word)) {
                    fputs(word, output);  // 输出不包含不需要子串的标识符
                }
                word_index = 0;  // 重置 word 缓冲区
                in_identifier = 0;
            }

            // 输出非标识符的字符
            fputc(ch, output);
        }
    }
    // 处理文件结尾的标识符
    if (in_identifier) {
        word[word_index] = '\0';
        if (!contains_unwanted_substring(word)) {
            fputs(word, output);
        }
    }
}

int main() {
    FILE *input = fopen("input.c", "r");
    FILE *output = fopen("output.c", "w");

    if (!input || !output) {
        printf("无法打开文件。\n");
        return 1;
    }

    // 删除空白符并删除包含不需要子串的标识符
    remove_whitespace_and_unwanted_strings(input, output);

    fclose(input);
    fclose(output);

    printf("处理完成，结果已写入 output.c\n");
    return 0;
}
 