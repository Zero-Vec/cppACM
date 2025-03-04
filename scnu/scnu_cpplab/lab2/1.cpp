#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double a, b, c, s, area;
    cout << "a , b , c = ";
    cin >> a >> b >> c; // 输入三角形的三条边
    s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c)); // 求三角形的面积
    cout << "area = " << area << endl;
    return 0;
}