#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double w, m, x, e;
    cout << "请输入苹果重量（斤）：";
    cin >> w;
    if(w > 10)
        e = 0.8;
    else if(w > 8)
        e = 1.0;
    else if(w > 6)
        e = 1.2;
    else if(w > 4)
        e = 1.5;
    else
        e = 1.8;
    m = w * e;
    cout << "应付货款：" << fixed << setprecision(2) << m << endl;
    cout<<"请输入顾客实际付款：";
    cin >> x;
    cout << "应找回钱数：" << fixed << setprecision(2) << x - m << endl;
    return 0;
}