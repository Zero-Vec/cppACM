#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a = 1, b = 1, c = 1;
    for (int i = 4; i <= 20190324;i++){
        int t = c;
        c = (a + b + t) % 10000;
        int tmp = b;
        b = t;
        a = tmp;
    }
    cout << c << '\n';
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