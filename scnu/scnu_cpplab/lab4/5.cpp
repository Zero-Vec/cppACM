#include <iostream>
using namespace std;
int main()
{
    int i, a[5], sum = 0;
    for (i = 1; i <= 4; i++){
        cout << "请输入第" << i << "个人的成绩: ";
        cin >> a[i];
        sum = sum + a[i];
    }
    cout << "sum=" << sum;
}
