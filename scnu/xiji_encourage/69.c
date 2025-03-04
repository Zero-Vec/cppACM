#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 10000

// 动态数组结构
typedef struct
{
    char **data;
    int size;
    int capacity;
} DynArray;

// 初始化动态数组
DynArray *initArray()
{
    DynArray *arr = (DynArray *)malloc(sizeof(DynArray));
    arr->size = 0;
    arr->capacity = 10;
    arr->data = (char **)malloc(arr->capacity * sizeof(char *));
    return arr;
}

// 动态数组添加元素
void addWord(DynArray *arr, const char *word)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = (char **)realloc(arr->data, arr->capacity * sizeof(char *));
    }
    arr->data[arr->size] = strdup(word);
    arr->size++;
}

// 释放动态数组内存
void freeArray(DynArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        free(arr->data[i]);
    }
    free(arr->data);
    free(arr);
}

// 从文件中读取单词
DynArray *readWords(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    DynArray *words = initArray();
    char line[MAX_WORD_LEN * 10];
    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, " \t\n\r.,!?;:()[]{}\"'"); // 分割符号过滤
        while (token)
        {
            char word[MAX_WORD_LEN];
            int index = 0;
            for (int i = 0; token[i]; i++)
            {
                if (isalpha(token[i]))
                {
                    word[index++] = tolower(token[i]); // 转小写
                }
            }
            word[index] = '\0';
            if (strlen(word) > 0)
            {
                addWord(words, word);
            }
            token = strtok(NULL, " \t\n\r.,!?;:()[]{}\"'");
        }
    }
    fclose(file);
    return words;
}

// 检查单词是否在索引列表中
int contains(DynArray *arr, const char *word)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (strcmp(arr->data[i], word) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// 查找错误单词并排序
DynArray *findErrors(DynArray *input, DynArray *index)
{
    DynArray *errors = initArray();
    for (int i = 0; i < input->size; i++)
    {
        if (!contains(index, input->data[i]))
        {
            addWord(errors, input->data[i]);
        }
    }
    // 排序错误单词
    for (int i = 0; i < errors->size - 1; i++)
    {
        for (int j = i + 1; j < errors->size; j++)
        {
            if (strcmp(errors->data[i], errors->data[j]) > 0)
            {
                char *temp = errors->data[i];
                errors->data[i] = errors->data[j];
                errors->data[j] = temp;
            }
        }
    }
    return errors;
}

// 将错误单词写入文件
void writeErrors(DynArray *errors, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < errors->size; i++)
    {
        fprintf(file, "%s\n", errors->data[i]);
    }
    fclose(file);
}

// 主函数
int main()
{
    const char *inputFile = "in.txt";
    const char *indexFile = "index.txt";
    const char *errorFile = "error.txt";

    DynArray *input = readWords(inputFile);
    DynArray *index = readWords(indexFile);

    DynArray *errors = findErrors(input, index);

    writeErrors(errors, errorFile);

    // 释放动态数组内存
    freeArray(input);
    freeArray(index);
    freeArray(errors);

    return 0;
}
