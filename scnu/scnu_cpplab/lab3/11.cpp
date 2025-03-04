#include<iostream>
using namespace std;
int main()
{
    double x, y;
    cout << "x=";
    cin >> x;
    if(x < 0){
        y = x + 1;
        cout << "x=" << x << ',' << "f(x)=" << y << endl;
    }
    else if(x >= 0 && x < 1){
        y = 1.0;
        cout << "x=" << x << ',' << "f(x)=" << y << endl;
    }
    else{
        y = 1 - x;
        cout << "x=" << x << ',' << "f(x)=" << y << endl;
    }
    return 0;
}