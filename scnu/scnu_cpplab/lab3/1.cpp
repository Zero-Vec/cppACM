// 下面程序的功能是计算球体的表面积和球体的体积，程序中有多处错误，并且指定必须按下面的形式输入、输出数据。请对程序做相应的修改。
#include <iostream>
using namespace std;
int main()
{
    double r, s, v;
    double pi = 3.14;
    cout << "input r:" << endl; /*输入球的半径*/
    cin >> r;
    s = 4 * pi * r * r;             /*计算球体的表面积*/
    v = 4.0 * pi * r * r * r / 3.0; /*计算球体的体积*/
    cout << "r=" << r << endl;
    cout << "s=" << s << ",v=" << v << endl;
}