#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N], pre[N], n;
void init(int x)
{
    for (int i = 1; i <= x; i++)
        pre[i] = i;
}
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int i, int j)
{
    int x = root(i), y = root(j);
    pre[x] = y;
}
void solve()
{
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        merge(a[i], a[a[i]]);
    }
    for (int i = 1; i <= n; i++)
        root(i);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[pre[i]]++;
    }
    ll ans = 0;
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 1 || mp[i] == 0)
            continue;
        if (mp[i] == 2)
            ct++;
        else if (mp[i] == 4)
            ans++;
        else if (mp[i] != 1)
            ans += (mp[i]) / 3, ct += (mp[i] % 3) == 2;
    }
    cout << ans + 1ll * (ct + 1) / 2 << '\n';
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