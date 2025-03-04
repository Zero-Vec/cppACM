#include<iostream>
#include<cmath>
using namespace std;
bool judge(int x){
    if(x == 1)
        return false;
    if(x == 2)
        return true;
    for (int i = 2; i <= sqrt(x);i++)
        if(x % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cout << "请输入n:";
    cin >> n;
    if(judge(n))
        cout << n << "是素数" << endl;
    else
        cout << n << "不是素数" << endl;
    return 0;
}