#include <stdio.h>
int main()
{
    char c;
    int blank = 0, tab = 0, newline = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            blank++;
        else if (c == '\t')
            tab++;
        else if (c == '\n')
            newline++;
    }
    printf("%d %d %d", blank, tab, newline - 1);
    return 0;
}