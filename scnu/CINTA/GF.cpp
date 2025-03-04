#include <iostream>
#include <stdlib.h>
using namespace std;
// 数组输出函数
void print_array(int num[8])
{
    for (int i = 0; i < 8;)
    {
        printf("%d", num[i++]);
    }
}
// 乘法运算
//  输入：两个长度为8的数组
void multiplication(int num1[8], int num2[8])
{
    int num3[8][8];
    int num4[8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            num3[i][j] = (num1[j] * num2[7 - i]) % 2;
        }
    }
    for (int k = 0; k < 8; k++)
    {
        int temp = 0;
        for (int m = 0; m < 8 - k; m++)
        {
            temp = temp + num3[m][m + k];
        }
        num4[k] = temp % 2;
    }
    // 输出结果
    cout << "num1 :";
    print_array(num1);
    cout << endl;
    cout << "num2 :";
    print_array(num2);
    cout << endl;
    cout << "计算结果为：";
    print_array(num4);
    cout << endl;
}
int main()
{
    // 定义两个 GF(2^8) 上的多项式 ， 以数组形式
    int num1[8] = {0, 1, 0, 0, 0, 0, 0, 0};
    int num2[8] = {0, 0, 0, 0, 0, 1, 0, 0};
    // 1. GF 2^8 上的加法、减法和乘法运算
    cout << "1. GF 2^8 上的乘法运算:" << '\n';
    // 乘法运算
    multiplication(num1, num2);
    return 0;
}
