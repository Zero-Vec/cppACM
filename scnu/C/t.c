/*
#include<stdio.h>
// #define A 3.5
// #define S(b) A *b *b
// #define INTEGER(x, y) x / y
// #define ADD(X, Y) X *Y
// #define MIN(x, y) (x) < (y) ? (x) : (y)
int main()
{
    // int x = 1, y = 2;
    // printf("%4.1f\n", S(x + y));

    // int z, a = 15, b = 100;
    // z = INTEGER(b, a);
    // printf("%d\n", z++);
    // int a = 3, b = 6;
    // printf("%d\n", ADD(a++, b++));

    // int i = 10, j = 15, k;
    // k = 10 * MIN(i, j);
    // printf("%d\n", k);

    int x = 3;
    do{
        printf("%d", x -= 2);
    } while (!(--x));
    return 0;
}*/
// #include <stdio.h>
// int main()
// {
//     // int k = 2;
//     // switch (k)
//     // {
//     // case 1:
//     //     printf("%d", k++);
//     //     break;
//     // case 2:
//     //     printf("%d", k++);
//     // case 3:
//     //     printf("%d", k++);
//     //     break;
//     // case 4:
//     //     printf("%d", k++);
//     // default:
//     //     printf("Full!");
//     // }
//     // int a = 5, b = 0, c = 1;
//     // printf("%d", a = b + c);
//     // if (a = b + c)
//     //     printf("***");
//     // else
//     //     printf("$$$");

//     // int a, b;
//     // for (a = 1, b = 1; a <= 100; a++)
//     // {
//     //     if (b >= 20)
//     //         break;
//     //     if (b % 3 == 1)
//     //     {
//     //         b += 3;
//     //         continue;
//     //     }
//     //     b -= 5;
//     // }
//     // printf("%d,%d\n", a, b);

//     // int a, b, c;
//     // scanf("a=%d,b=%d,c=%d", &a, &b, &c);
//     // printf("a=%d,b=%d,c=%d", a, b, c);
//     double a = 3.5;
//     printf("%d\n", (int)a);
//     printf("%d\n", a);
//     printf("%f\n", a);
//     printf("%lf\n", a);
//     return 0;
// }

#include <stdio.h>
int main()
{
    static int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int m, *ptr;
    ptr = &a[0][0];
    m = (*ptr) * (*(ptr + 2)) * (*(ptr + 4));
    printf("%d\n", m);
    return 0;
}
