#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll mo(ll x) { return (x % p + p) % p; }
ll qmi(ll base,ll power){
    ll res = 1;
    while(power){
        if(power&1)
            res = res * base % p;
        power >>= 1;
        base = base * base % p;
    }
    return res;
}
ll inv6 = qmi(6, p - 2);
ll f(ll n){
    n %= p;
    return n * (n + 1) % p * (2 * n + 1) % p * inv6 % p;
}
void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll l = 1, r = 1; l <= n;l = r + 1){
        r = min(n, n / (n / l));
        ans = mo(ans + mo(n / l) * mo(f(r) - f(l - 1)) % p);
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