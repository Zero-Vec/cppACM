#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
    //九进制转十进制
    string s = "2022";
    long long x = 0;
    for (int i = 0; i < s.length();i++){
        a[i] = s[i] - '0';
        x = x * 9 + a[i];
    }
    cout << x << '\n';
    return 0;
}