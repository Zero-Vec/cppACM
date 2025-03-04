#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7, N = 1e7 + 2;
ll fac[N], n, m, q;
ll qmi(ll base, ll power){
    ll res = 1;
    while(power){
        if(power & 1)
            res = res * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return res;
}
ll inv(ll x){
    return qmi(x, p - 2);
}
ll C(ll n, ll m){
    if(n<0||m<0||n<m)
        return 0;
    return fac[n] * inv(fac[m]) % p * inv(fac[n - m]) % p;
}
void solve(){
    cin >> q;
    while(q--){
        cin >> n >> m;
        cout << C(n, m) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    fac[0] = 1;
    for (int i = 1; i < N;i++)
        fac[i] = fac[i - 1] * i % p;
    while (t--)
        solve();
    return 0;
}