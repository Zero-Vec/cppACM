#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n,m;
    cin >> n >> m;
    if(n == m)
        cout << n * 2 << '\n';
    else
        cout << min(n, m) * 2 + 1 << '\n';
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