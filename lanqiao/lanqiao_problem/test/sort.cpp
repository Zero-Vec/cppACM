#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll m = 97, k = 33, h = 114514;
    cout << (h - (h - 1) / m * k);
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