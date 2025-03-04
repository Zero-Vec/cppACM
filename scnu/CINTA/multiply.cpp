#include <iostream>
using namespace std;
int multiply(int a, int b)
{
    int ans = 0; // 返回的相乘结果
    int x = 1;   // 初始化2的0次方
    while (b)
    {
        if (b & 1)
        {
            ans += x * a;
        }
        b = b >> 1;
        x = x << 1;
    }
    return ans;
}
int main()
{
    int a, b;
    cout << "请分别输入相乘的两个数的值：";
    cin >> a >> b;
    cout << "相乘结果为：" << multiply(a, b);
    return 0;
}