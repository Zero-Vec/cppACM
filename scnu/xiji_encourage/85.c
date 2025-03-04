#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file1 = fopen("in.c", "r");
    FILE *file2 = fopen("out.txt", "w");
    fseek(file1, 0, SEEK_END);
    long length = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    char *str = (char *)malloc(length + 1);
    fread(str, 1, length, file1);
    str[length] = '\0';

    int i = 0;
    while (i < length)
    {
        if (strncmp(&str[i], "if", 2) == 0)
        {
            fprintf(file2, "if");
        }
        else if (strncmp(&str[i], "else", 4) == 0)
        {
            fprintf(file2, "else");
        }
        else if (strncmp(&str[i], "for", 3) == 0)
        {
            fprintf(file2, "for");
        }
        else if (strncmp(&str[i], "while", 5) == 0)
        {
            fprintf(file2, "while");
        }
        else if (strncmp(&str[i], "switch", 6) == 0)
        {
            fprintf(file2, "switch");
        }
        else if (strncmp(&str[i], "case", 4) == 0)
        {
            fprintf(file2, "case");
        }
        i++;
    }

    free(str);
    fclose(file1);
    fclose(file2);

    return 0;
}
