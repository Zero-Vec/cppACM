#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
ll a[N], n, k;
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    ll len = n - k;
    for (int i = 1; i + len - 1 <= n; i++)
    {
        ll t = 0;
        for (int j = i; j <= i + len - 1; j++)
            t += a[j];
        ans = max(t, ans);
    }
    cout << ans << '\n';
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