#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double sum, given;
    double a_m = 2.50, b_m = 1.80, c_m = 2.00, d_m = 1.60;//分别表示苹果、鸭梨、香蕉、桔子的单价
    double a, b, c, d;//分别表示苹果、鸭梨、香蕉、桔子的重量
    cout<<"请输入购买的苹果的重量：";
    cin >> a;
    cout<<"请输入购买的鸭梨的重量：";
    cin >> b;
    cout<<"请输入购买的香蕉的重量：";
    cin >> c;
    cout<<"请输入购买的桔子的重量：";
    cin >> d;
    sum = a * a_m + b * b_m + c * c_m + d * d_m;
    cout << "应付钱数为：" << sum << endl;
    cout<<"请输入顾客实际付款数：";
    cin >> given;
    cout << "应找钱数为：" << given - sum << endl;
    return 0;
}