#include <iostream>
using namespace std;
double max(double x, double y);
int main()
{
    double a, b, c;
    cout <<"input two numbers：";
    cin >> a >> b; // 输入两个实数
    c = max(a, b); // 求两个实数最大值
    cout << "maximum = " << c << endl;
    return 0;
}
double max(double x, double y)
{
    if (x > y)
        return x;
    else
        return y;
}
