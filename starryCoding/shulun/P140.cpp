#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll mo(ll x) { return (x % p + p) % p; }
void solve(){
    // 二维整除分块
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll l = 1, r = 1; l <= min(n, m);l=r+1){
        r = min({n, m, n / (n / l), m / (m / l)});
        ans = mo(ans + mo(r - l + 1) * mo(n / l) % p * mo(m / l) % p);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}