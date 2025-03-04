#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "请输入n:";
    cin >> n;
    for (int i = 1; i <= n;i++)
        if(i % 3 == 0 && i % 10 == 3)
            cout << i << endl;
    return 0;
}