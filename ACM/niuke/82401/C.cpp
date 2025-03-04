#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod=998244353;
ll quick_power(ll base, ll power){
    ll result = 1;
    while(power){
        if(power&1)
            result = result * base % mod;
        power /= 2;
        base = base * base % mod;
    }
    return result;
}
ll inv(ll n){
    return quick_power(n, mod - 2);
}
void solve(){
    ll m,a,b,c;
    cin >> m >> a >> b >> c;
    ll ans = (a * (m - 1) * (m - 2) + 3 * b * (m - 1) + c) % mod;
    ll di = m * m % mod;
    if(ans%di==0){
        cout << ans / di % mod << '\n';
    }
    else{
        cout << ans * inv(di) % mod << '\n';
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