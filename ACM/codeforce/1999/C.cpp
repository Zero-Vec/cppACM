#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll n, s, m, l[N], r[N];
void solve()
{
    cin >> n >> s >> m;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        if (i == 1)
            ans = max(ans, l[i] - 0);
        // else if (i == n)
        //     ans = max(ans, m - r[i]);
        else
            ans = max(ans, l[i] - r[i - 1]);
    }
    ans = max(ans, m - r[n]);
    cout << (ans >= s ? "Yes\n" : "No\n");
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