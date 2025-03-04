#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d, e; // 分别表示个位、十位、百位、千位、万位
    int x;
    cout << "请输入一个五位正整数：";
    cin >> x;
    a = x % 10;
    b = x / 10 % 10;
    c = x / 100 % 10;
    d = x / 1000 % 10;
    e = x / 10000;
    cout << "该五位整数个位为：" << a << endl;
    cout << "该五位整数十位为：" << b << endl;
    cout << "该五位整数百位为：" << c << endl;
    cout << "该五位整数千位为：" << d << endl;
    cout << "该五位整数万位为：" << e << endl;
    return 0;
}