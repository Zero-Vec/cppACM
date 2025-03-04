#include<iostream>
using namespace std;
int power(int y, int n)
{
    int i, p = 1;
    for (i = 1; i <= n; i++)
        p = p * y;
    return p;
}
int main()
{
    int x, n, s;
    cout << "请分别输入 x 和 n 的值：" << endl;
    cin >> x >> n;
    s = power(x, n);
    cout << "s = " << s << endl;
    return 0;
}