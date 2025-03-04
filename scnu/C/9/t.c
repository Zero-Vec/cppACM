/*
#include <stdio.h>

void swap(int *p1, int *p2)
{
    int n;
    n = *p1;
    *p1 = *p2;
    *p2 = n;
}

int main()
{
    int a = 10, b = 14, *pp1, *pp2;
    pp1 = &a;
    pp2 = &b;
    swap(pp1, pp2);
    printf("*pp1=%d,*pp2=%d\n", *pp1, *pp2);
    printf("a=%d,b=%d\n", a, b);
    return 0;
}
*/

/*
#include <stdio.h>
int func(int a, int b)
{
    int c;
    c = a + b;
    return c;
}
int main()
{
    int x = 6, y = 7, z = 8, r;
    r = func((x--, y--, x + y), --z);
    printf("%d\n", r);
    return 0;
}
*/

/*
#include <stdio.h>
int x1 = 30, x2 = 40;
void swap(int x, int y);
int main()
{
    int x3 = 10, x4 = 20;
    swap(x3, x4);
    swap(x2, x1);
    printf("%d,%d,%d,%d\n", x3, x4, x1, x2);
    return 0;
}
void swap(int x, int y)
{
    x1 = x;
    x = y;
    y = x1;
}
*/

/*
#include <stdio.h>
int x = 2;
void increment();
int main()
{
    int x = 8;
    increment();
    x++;
    increment();
    x++;
    increment();
    return 0;
}
void increment()
{
    int x = 0;
    x++;
    printf("%d,", x);
}
*/

#include <stdio.h>
int func(int n)
{
    if (n <= 1)
        return 1;
    else
        return (2 + n * func(n - 1));
}

int main()
{
    int x = 4;
    printf("%d", func(x));
    return 0;
}