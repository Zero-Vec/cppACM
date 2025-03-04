#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 辅助函数：判断字符是否是标点或数字
int is_special_character(char c)
{
    return ispunct(c) || isdigit(c);
}

// 辅助函数：将字符串转换为小写
void to_lower(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]);
    }
}

// 辅助函数：判断是否是排除词
int judge(const char *word)
{
    char lower_word[21]; // 限制最大长度为20个字符
    strcpy(lower_word, word);
    to_lower(lower_word);
    return strcmp(lower_word, "a") == 0 || strcmp(lower_word, "an") == 0 || strcmp(lower_word, "the") == 0 || strcmp(lower_word, "and") == 0;
}

struct WordRecord
{
    char word[21];         // 单词
    int line[200]; // 存储出现该单词的行号
    int count;             // 单词出现的次数
};

// 将单词记录插入到字典中
void insert_word(struct WordRecord *dict, int *dict_size, const char *word, int l_num)
{
    for (int i = 0; i < *dict_size; i++)
    {
        if (strcmp(dict[i].word, word) == 0)
        {
            // 如果单词已存在，检查行号是否已经记录
            for (int j = 0; j < dict[i].count; j++)
            {
                if (dict[i].line[j] == l_num)
                    return; // 如果行号已存在，则不再记录
            }
            dict[i].line[dict[i].count++] = l_num; // 新的行号加入
            return;
        }
    }
    // 如果单词不存在，则添加到字典中
    strcpy(dict[*dict_size].word, word);
    dict[*dict_size].line[0] = l_num;
    dict[*dict_size].count = 1;
    (*dict_size)++;
}

// 比较函数：按字典序比较单词
int cmp(const void *a, const void *b)
{
    return strcmp(((struct WordRecord *)a)->word, ((struct WordRecord *)b)->word);
}

int main()
{
    FILE *infile = fopen("crossin.txt", "r");
    if (!infile)
    {
        printf("无法打开文件 crossin.txt\n");
        return 1;
    }

    struct WordRecord dict[200]; // 存储单词记录
    int dict_size = 0;
    char line[1024];
    int line_number = 0;

    while (fgets(line, sizeof(line), infile))
    {
        line_number++;
        char cleaned_line[1024];
        int cleaned_index = 0;

        // 处理每一行，去掉标点符号和数字
        for (int i = 0; i < strlen(line); i++)
        {
            if (is_special_character(line[i]))
            {
                cleaned_line[cleaned_index++] = ' ';
            }
            else
            {
                cleaned_line[cleaned_index++] = line[i];
            }
        }
        cleaned_line[cleaned_index] = '\0'; // 确保字符串结束

        // 分割行中的单词
        char *word = strtok(cleaned_line, " \n");
        while (word != NULL)
        {
            // 判断是否是排除词
            if (!judge(word))
            {
                insert_word(dict, &dict_size, word, line_number);
            }
            word = strtok(NULL, " \n");
        }
    }
    fclose(infile);

    // 按字典序排序
    qsort(dict, dict_size, sizeof(struct WordRecord), cmp);

    // 输出到文件 "crossout.txt"
    FILE *outfile = fopen("crossout.txt", "w");
    if (!outfile)
    {
        printf("无法打开文件 crossout.txt\n");
        return 1;
    }

    // 输出结果
    for (int i = 0; i < dict_size; i++)
    {
        fprintf(outfile, "%s:", dict[i].word);
        for (int j = 0; j < dict[i].count; j++)
        {
            if (j > 0)
            {
                fprintf(outfile, ",");
            }
            fprintf(outfile, "%d", dict[i].line[j]);
        }
        fprintf(outfile, "\n");
    }
    fclose(outfile);

    return 0;
}
