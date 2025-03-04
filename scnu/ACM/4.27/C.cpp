#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll a[N];
ll n, m, k, x;
void solve(){
    cin >> k;
    for (int i = 1; i <= k;i++)
        cin >> a[i];
    cin >> n >> m >> x;
    ll t = x % m;
    ll s = 0;
    for (int i = 1; i <= k;i++)
        s += a[i] % m;
    t += (n / k) * s;
    ll ans = n % k;
    for (int i = 1; i <= ans;i++)
        t += a[i];
    cout << n - t / m << '\n';
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