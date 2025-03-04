#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int maxn = 5e5 + 9;
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
void solve(){
    ll s0 = 0, s1 = 0, n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        int a;
        cin >> a;
        if(a == 1)
            s1++;
        else
            s0++;
    }
    ll ans = 0;
    for (int i = (k + 1) / 2; i <= k;i++){
        ans = (ans + C(s1, i) * C(s0, k - i)) % P;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % P;
    }
    cin >> t;
    while(t--)
        solve();
    return 0;
}