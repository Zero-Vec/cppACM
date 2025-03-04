#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e3 + 9, p = 1e9 + 7;
ll fac[N << 1], n, a[N];
ll qmi(ll base,ll power){
    ll res = 1;
    while(power){
        if(power & 1)res=res*base%p;
        power>>=1;
        base = base * base % p;
    }
    return res;
}
void init(){
    fac[0] = 1;
    for (int i = 1; i < N * 2;i++)
        fac[i] = fac[i - 1] * i % p;
}
ll inv(ll x) { return qmi(x, p - 2); }
ll C(int m,int n){
    if(m < 0 || n < 0 || m < n)
        return 0;
    return fac[m] * inv(fac[m - n]) % p * inv(fac[n]) % p;
}
void solve(){
    init();
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll ans = 0;
    for (int j = 1;j <= n;j++)
        for (int i = 1; i <= j;i++)
            if(a[i]!=a[j]){
                // cout << j << " " << i << " " << C(j + (n - 1 - i), j) << '\n';
                ans = (ans + (C(j + (n - 1 - i),j) * qmi(2, i - j + 1)) % p) % p;
            }
    cout << ans << '\n';
    // cout << C(1, 1);
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