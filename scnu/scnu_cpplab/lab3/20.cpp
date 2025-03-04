#include<iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 6;i++){
        // 输出若干空格
        for (int j = 1; j < i;j++)
            cout << " ";
        // 输出若干个 M
        for (int j = 1; j <= 13 - 2 * i;j++)
            cout << "M";
        cout << '\n';
    }
    return 0;
}