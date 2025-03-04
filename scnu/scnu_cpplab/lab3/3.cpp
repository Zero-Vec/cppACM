#include<iostream>
#include<iomanip>
using namespace std;
const double pi = 3.141592653589793;
int main()
{
    double r;
    cout<<"请输入球的半径：";
    cin >> r;
    double s = 4 * pi * r * r;
    double v = 4.0 * pi * r * r * r / 3.0;
    cout << fixed << setprecision(2);
    cout << "球的表面积为：" << s << '\t';
    cout << "球的体积为：" << v << endl;
    return 0;
}