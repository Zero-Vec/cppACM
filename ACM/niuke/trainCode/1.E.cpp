#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[13];
int u[13], v[13]; // m场比赛的两名参赛选手
int ans;
int n, m;
void dfs(int dep)
{
    if (dep == m + 1)
    {
        int cnt = 1;
        for (int i = 2; i <= n; i++)
        {
            if (a[1] < a[i])
                cnt++;
        }
        ans = min(cnt, ans);
        return;
    }
    a[u[dep]] += 3;
    dfs(dep + 1);
    a[u[dep]] -= 3;
    a[v[dep]] += 3;
    dfs(dep + 1);
    a[v[dep]] -= 3;
    a[u[dep]] += 1, a[v[dep]] += 1;
    dfs(dep + 1);
    a[u[dep]] -= 1, a[v[dep]] -= 1;
}
void solve()
{
    ans = 13;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
    }
    dfs(1);
    cout << ans << "\n";
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