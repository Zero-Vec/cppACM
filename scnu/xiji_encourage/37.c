#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char line[10000];
int a[10000];

int compar(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    while(scanf("%[^\n]", line) != EOF){
        getchar();
        memset(a, 0, sizeof a);
        int i = 0;
        char *p = line;
        while(p != NULL && sscanf(p, "%d", &a[i]) != EOF){
            i++;
            p = strchr(p + 1, ' ');
        }
        int ia = i;
        scanf("%[^\n]", line);
        getchar();
        p = line;
        while(p != NULL && sscanf(p, "%d", &a[i]) != EOF){
            i++;
            p = strchr(p + 1, ' ');
        }
        int ib = i;
        if(ia == ib)
            break;
        qsort(a, i, sizeof(int), compar);
        while(i){
            int cur = a[i - 1];
            printf("%d ", cur);
            while(i && a[i - 1] == cur)
                i--;
        }
        putchar('\n');
        memset(a, 0, sizeof a);
        memset(line, 0, sizeof line);
    }
    return 0;
}