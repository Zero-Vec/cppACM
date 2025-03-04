#include <stdio.h>

int check(char *s, char *t, int n)
{
    int i;
    for (i = 0; t[i] != '#'; n++, i++)
    {
        if (s[n] != t[i] || s[n] == '#')
            return 0;
    }
    return i;
}

void invert(char *s, int begin, int end)
{
    int i, j;
    char temp;
    for (i = begin, j = end; j - i > 0; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void put(char *s, FILE *out)
{
    int i;
    for (i = 0; s[i] != '#' && s[i] != '\0'; i++)
    {
        fputc(s[i], out); 
    }
    fputc('\n', out);
}

int main()
{
    char s[51], t[51], rs[51];
    int i, j, len = 0;
    FILE *inputFile = fopen("invertsub.in", "r");
    FILE *outputFile = fopen("invertsub.out", "w");
    fgets(s, sizeof(s), inputFile);
    fgets(t, sizeof(t), inputFile);
    for (i = 0; s[i] != '#'; i++){
        len = check(s, t, i);
        if (len != 0)
            break;
    }
    if (len > 0){
        invert(s, i, i + len - 1);
    }
    put(s, outputFile);
    fclose(inputFile); 
    fclose(outputFile);
    return 0;
}