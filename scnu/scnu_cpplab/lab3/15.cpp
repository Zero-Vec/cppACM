#include<iostream>
using namespace std;
const double pi = 3.1415;
int main()
{
    double R;
    char choice;
    cout << "piz enter R:";
    cin >> R;
    cout<<"piz enter choice:";
    cin >> choice;
    double s = pi * R * R;
    double c = 2 * pi * R;
    switch(choice){
        case 'C':
            cout << "圆的周长为" << c << endl;
            break;
        case 'A':
            cout << "圆的面积为" << s << endl;
            break;
        case 'B':
            cout << "圆的周长为" << c << endl;
            cout << "圆的面积为" << s << endl;
            break;
    }
    return 0;
}