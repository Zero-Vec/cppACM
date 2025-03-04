#include <stdio.h>

int main()
{
    double x, xn; // x 为输入的正整数，xn 用于存储每次迭代后的值
    int n;        // 迭代次数

    // 读取输入
    scanf("%lf %d", &x, &n);

    // 初始时，x1 = x
    xn = x;

    // 根据迭代公式进行 n 次迭代
    for (int i = 0; i < n; i++)
    {
        xn = (xn + x / xn) / 2.0;
    }

    // 输出结果，保留小数点后 5 位
    printf("%.5f\n", xn);

    return 0;
}