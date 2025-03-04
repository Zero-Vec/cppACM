#include <stdio.h>
#include <malloc.h>

void pspace(int num)
{
    int i;
    for (i = 0; i < num; i++)
        printf(" ");
}

void pnum(int num)
{
    if (num < 10)
        pspace(3);
    else if (num < 100)
        pspace(2);
    else if (num < 1000)
        pspace(1);
    printf("%d", num);
}

void getline(int *a, int i)
{
    int *b = (int *)malloc(i * sizeof(int));
    int k;
    b[0] = 1;
    b[i - 1] = 1;
    for (k = 1; k < i - 1; k++)
        b[k] = a[k] + a[k - 1];
    for (k = 0; k < i; k++)
        a[k] = b[k];
    free(b);
}

int main()
{
    int n, i, k;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    a[0] = 1;
    a[1] = 1;
    for (i = 1; i <= n + 1; i++)
    {
        pspace(2 * (n + 1 - i));
        if (i == 1)
            pnum(1);
        else
        {
            getline(a, i);
            for (k = 0; k < i; k++)
                pnum(a[k]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}