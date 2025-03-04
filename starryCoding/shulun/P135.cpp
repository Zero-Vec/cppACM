#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll qp(ll b, ll power){
    ll res = 1;
    while(power){
        if(power & 1)
            res = res * b % p;
        b = b * b % p;
        power >>= 1;
    }
    return res;
}
ll inv(ll x){
    return qp(x, p - 2);
}
ll inv2 = inv(2);
ll mo(ll x){
    return (x % p + p) % p;
}
void solve(){
    // 整除分块 向下整除
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll l = 1, r = 1; l <= n;l=r+1){
        r = min(n, n / (n / l));
        ans = mo(ans + mo(l + r) * mo(r - l + 1) % p * inv2 % p * mo(n / l) % p);
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