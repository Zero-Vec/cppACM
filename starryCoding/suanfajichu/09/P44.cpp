#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 998244353;
ll quick_power(ll base,ll power){
    ll result = 1;
    while(power){
        if(power & 1)
            result = result * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return result;
}
ll inv(ll x){
    return quick_power(x, p - 2);
}
void solve(){
    ll a, b, c, q;
    cin >> a >> b >> c >> q;
    while(q--){
        ll x;
        cin >> x;
        ll ans = (a * x % p + b) % p;
        ll k = inv(c * x % p);
        cout << ans * k % p << '\n';
    }
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