#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N];
int main()
{
    //十六进制转十进制
    string s = "2021ABCD";
    long long x = 0;
    for (int i = 0; i < s.length();i++){
        if('0'<=s[i]&&s[i]<='9')
            a[i] = s[i] - '0';
        else
            a[i] = s[i] - 'A' + 10;
        x = x * 16 + a[i];
    }
    cout << x << '\n';
    return 0;
}