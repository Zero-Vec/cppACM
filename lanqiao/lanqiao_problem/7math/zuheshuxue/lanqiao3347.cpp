#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
int n, a, b;
ll quick_power(ll base, ll power){
    ll result = 1;
    while (power){
        if (power % 2 == 1){
            result = base * result % P;
            power--;
        }
        base = base * base % P;
        power /= 2;
    }
    return result % P;
}
ll inv(ll x)
{
    return quick_power(x, P - 2);
}
void solve()
{
    cin >> n >> a >> b;
    ll cnta = 1, cntb = 1;
    for (int i = n; i >= n - a + 1; i--){
        cnta = cnta * i % P;
    }
    for (int i = 1; i <= a;i++){
        cnta = cnta * inv(i) % P;
    }
    for (int i = n; i >= n - b + 1; i--){
        cntb = cntb * i % P;
    }
    for (int i = 1; i <= b; i++){
        cntb = cntb * inv(i) % P;
    }
    ll ans = ((quick_power(2, n) - cnta - cntb - 1) % P + P) % P;
    //cout << quick_power(2,n) << "\n";
    //cout << cnta << "\n";
    //cout << cntb << "\n";
    cout << ans << "\n";
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