#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double sale, cash;
    cout << "请输入顾客的购物金额：" << endl;
    cin >> cash;
    if(cash < 100)
        sale = 1;
    else if(cash < 300)
        sale = 0.9;
    else if(cash < 500)
        sale = 0.85;
    else
        sale = 0.8;
    cout << "该顾客的打折率为：" << sale << "购物实际应付款为：" << fixed << setprecision(2) << cash * sale << endl;
    return 0;
}