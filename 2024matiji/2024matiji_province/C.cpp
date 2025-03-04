#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 998244353;
const int maxn = 3e5 + 9;
ll fac[maxn];
ll quick_power(ll base, ll power)
{
    ll result = 1;
    while (power)
    {
        if (power & 1)
        {
            result = result * base % P;
        }
        power /= 2;
        base = base * base % P;
    }
    return result % P;
}
ll inv(ll x)
{
    return quick_power(x, P - 2);
}
ll C(ll m, ll n)
{
    if (m < 0 || n < 0 || m < n)
        return 0;
    return fac[m] * inv(fac[m - n]) % P * inv(fac[n]) % P;
}
ll mo(ll x){
    return (x % P + P) % P;
}
void solve(){
    ll x1, y1, x2, y2, n, p, q;
    
    cin >> x1 >> y1 >> x2 >> y2 >> n >> p >> q;

    ll gx = x2 - x1, gy = y2 - y1;
    ll g = gx + gy;
    if(gx<0||gy<0||((n-g)&1)||n<g){
        cout << 0 << "\n";
        return;
    }
    ll ans = 1;
    ans = mo(ans * C(n, g));
    ans = mo(ans * C(g, gx));
    ll px = mo(p * inv(100));
    ans = mo(ans * quick_power(px, gx));
    ll qy = mo(q * inv(100));
    ans = mo(ans * quick_power(qy, gy));
    ans = mo(ans * quick_power(2, (n - g)));
    cout << ans << '\n';
    

    //cout << mo(216ll * inv(625)) << '\n';
    //cout << 4ll * inv(4);
    //cout << mo(3ll * inv(8));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % P;
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}