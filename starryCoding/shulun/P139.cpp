#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll mo(ll x){
    return (x % p + p) % p;
}
ll quick_power(ll base,ll power){
    ll res = 1;
    while(power){
        if(power & 1)
            res = res * base % p;
        power >>= 1;
        base = base * base % p;
    }
    return res;
}
ll inv(ll x){
    return quick_power(x, p - 2);
}
ll inv2 = inv(2);
void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = mo(n) * k % p;
    for (ll l = 1, r = 1; l <= min(n, k);l = r + 1){
        r = min(n, k / (k / l));
        ans = mo(ans - mo(l + r) * mo(r - l + 1) % p * inv2 % p * mo(k / l) % p);
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