#include <iostream>
using namespace std;
int main()
{
    char c1 ='a', c2 ='b', c3 ='c';
    int i1 = 10, i2 = 20, i3 = 30;
    double d1 = 0.1, d2 = 0.2, d3 = 0.4;
    int a = c1 + i2 * i3 / i2 % i1;
    cout << "a = " << a << endl;
    int b = i1++ + i2 % i3;
    cout << "b = " << b << endl;
    int c = i2-- * ++i3;
    cout << "c = " << c << endl;
    int d = i1 > i2 > i3 < d1 < d2 < d3;
    cout << "d = " << d << endl;
    int e = (c1 = i2 * i3) != (i2 % i1);
    cout << "e = " << e << endl;
    int f = d1 > d2 || i1 == i2;
    cout << "f = " << f << endl;
    int g = c1 > i1 ? i1 : c2;
    cout << "g = " << g << endl;
    int h=0?1:0?2:0?3:4;
    cout << "h = " << h << endl;
    int i = i1 += i2 *= i3;
    cout << "i = " << i << endl;
    int j = i3 = (i1 = 1, i2--);
    cout << "j = " << j << endl;
    int k = i1 = (c1, c2, c3);
    cout << "k = " << k << endl;
    int l = !i1 && i2--;
    cout << "l = " << l << endl;
    return 0;
}
