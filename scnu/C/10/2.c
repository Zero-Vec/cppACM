#include<stdio.h>
#include<string.h>

#define MAX 1024
int main()
{
    char ch;
    scanf("%c", &ch);
    FILE *fp = fopen("filein.txt", "r");
    FILE *out_fp = fopen("fileout.txt", "w");
    char line[MAX];
    while(fgets(line, MAX, fp)){
        char *found = strstr(line, &ch);
        while(found){
            fprintf(out_fp, "%.*s\"%c\"", (int)(found - line), line, ch);
            line[strlen(line) - strlen(found) + 1] = '\0';
            found = strstr(found + 1, &ch);
        }
        fprintf(out_fp, "%s", line);
    }

    fclose(fp);
    fclose(out_fp);

    return 0;
}