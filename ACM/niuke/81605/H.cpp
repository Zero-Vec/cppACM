#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 998244353;
ll a, b;
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
ll mo(ll x) { return (x % P + P) % P; }
void solve()
{
    cin >> a >> b;
    cout << mo(a * inv(a + b)) << " " << mo(b * inv(a + b));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 998244353;
ll a, b;
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
ll mo(ll x) { return (x % P + P) % P; }
void solve(){
    cin >> a >> b;
    if(a==b){
        cout << 1ll * inv(2) << " " << 1ll * inv(2);
        return;
    }
    // cout << 1ll * inv(4) << " " << 3ll * inv(4) % P;
    bool tag = false;
    if(a>b){
        swap(a, b);
        tag = true;
    }
    ll jushu = 0;
    while(a < b){
        ll t = a;
        a += t, b -= t;
        jushu++;
    }
    ll lose = 0;
    while (a >= b){
        ll t = b;
        b += t, a -= t;
        lose++;
    }
    ll k = 1;
    for (int i = 1; i <= jushu;i++){
        k = k * 2;
    }
    ll k2 = 1;
    for (int i = 1; i <= lose;i++){
        k2 = k2 * 2;
    }
    ll fenzi = k2 - 1, fenmu = k * k2;
    ll bf = fenmu - fenzi;
    // cout << fenzi << " " << bf << " " << fenmu << '\n';
    // cout << a << " " << b << '\n';
    // cout << k << '\n';
    if (!tag)
        cout << mo(fenzi * inv(fenmu)) << " " << mo(bf * inv(fenmu));
    else
        cout << mo(bf * inv(fenmu)) << " " << mo(fenzi * inv(fenmu));
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
*/