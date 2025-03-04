#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10

int n;
int mark[MAX + 1]; // 标记数组，用于标记数字是否已使用
int stack[MAX];    // 模拟栈，存放当前排列的元素
int top = -1;

// 输出全排列数据
void print()
{
    for (int i = 0; i < n; i++)
        cout << stack[i] << " ";
    cout << endl;
}

// 全排列
void pailie()
{
    if (top == n - 1)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!mark[i])
        {
            mark[i] = 1;
            stack[++top] = i;
            pailie();
            mark[i] = 0;
            top--;
        }
    }
}

int main()
{
    cin >> n;
    pailie();
    return 0;
}