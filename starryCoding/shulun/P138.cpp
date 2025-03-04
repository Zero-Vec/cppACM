// 整出分块 向上取整
// 法二 向上取整模板
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll quick_power(ll base,ll power){
    ll res = 1;
    while(power){
        if(power&1)
            res = res * base % p;
        power >>= 1;
        base = base * base % p;
    }
    return res;
}
ll inv(ll x){
    return quick_power(x, p - 2);
}
ll mo(ll x){
    return (x % p + p) % p;
}
ll inv2 = inv(2);
ll findr(ll n,ll l){
    ll k = (n + l - 1) / l;
    if(k==1)
        return n;
    return (n - 1) / (k - 1);
}
void solve(){
    ll n, ans = 0;
    cin >> n;
    for (ll l = 1, r = 1; l <= n;l=r+1){
        r = findr(n, l);
        ans = mo(ans + mo(l + r) * mo(r - l + 1) % p * inv2 % p * mo((n + l - 1) / l) % p);
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
/*
// 法一  :利用公式(n/i)向上取整 = [(n-1)/i]向下取整+1 转换为向下取整问题
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll quick_power(ll base,ll power){
    ll res = 1;
    while(power){
        if(power&1)
            res = res * base % p;
        power >>= 1;
        base = base * base % p;
    }
    return res;
}
ll inv(ll x){
    return quick_power(x, p - 2);
}
ll mo(ll x){
    return (x % p + p) % p;
}
ll inv2 = inv(2);
void solve(){
    ll n;
    cin >> n;
    ll ans = mo(1 + n) * mo(n) % p * inv2 % p;
    n--;
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
    while (t--)
        solve();
    return 0;
}
*/