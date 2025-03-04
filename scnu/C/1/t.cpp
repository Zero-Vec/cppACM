#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    // char a = 'a';
    // float b = 2.3;
    // double c = 41;
    // int d = a + b + c;
    // cout << typeid(d).name();
    int x = 10, y = 9;
    int a, b, c;
    a=(--x==y++)?--x:++y;
    b = x++;
    c = y;
    cout << a << '\n'
         << b << '\n'
         << c;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}