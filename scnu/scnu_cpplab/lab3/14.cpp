#include<iostream>
using namespace std;
int main()
{
    int cnt = 0, x;
    cout<<"请输入一个正整数：";
    cin >> x;
    while(x){
        cnt++;
        x /= 10;
    }
    cout << "该正整数是" << cnt << "位数" << endl;
    return 0;
}