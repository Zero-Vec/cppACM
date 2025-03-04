#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node
{
    int w, p;
    bool operator<(const node &u) const
    {
        return p < u.p;
    }
} t[N];
ll pre[N], nex[N];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i].w >> t[i].p;
    sort(t + 1, t + 1 + n);
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + s * (t[i].p - t[i - 1].p);
        s += t[i].w;
    }
    s = 0;
    for (int i = n; i >= 1; i--)
    {
        nex[i] = nex[i + 1] + s * (t[i + 1].p - t[i].p);
        s += t[i].w;
    }
    ll ans = 2e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, pre[i] + nex[i]);
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