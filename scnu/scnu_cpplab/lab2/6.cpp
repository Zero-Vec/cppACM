#include <iostream>
using namespace std;
int main()
{
    char a, b, c;
    cout << "input character a,b,c\n";
    cin >> a >> b >> c;
    cout << a << b << c;
    a = a - 32;
    b = b - 32;
    c = c - 32;
    cout << a << b << c << endl;
    return 0;
}
