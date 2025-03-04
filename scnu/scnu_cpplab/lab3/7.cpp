#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "input a,b,c:";
    cin >> a >> b >> c;
    int mn = a;
    if(b < mn)
        mn = b;
    if(c < mn)
        mn = c;
    cout << "min = " << mn << endl;
    return 0;
}
/*
#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout<<"input a,b,c:";
    cin >> a >> b >> c;
    if((a > b) && (a > c))
        if(b < c)
            cout << "min = " << b << endl;
        else
            cout << "min = " << c << endl;
    if((a < b) && (a < c))
        cout << "min = " << a << endl;
    if((a > b) && (a < c))
        cout << "min = " << b << endl;
    if((a > c) && a < b)
        cout << "min = " << c << endl;
    return 0;
}
*/