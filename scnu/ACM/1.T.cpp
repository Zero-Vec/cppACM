#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e3 + 9;
int n;
char s[N];
vector<int> g[N];
int w[N], b[N];
void dfs(int x)
{
    // 算出每个子树的白和黑的个数
    w[x] = (s[x] == 'W');
    b[x] = (s[x] == 'B');
    for (auto i : g[x])
    {
        dfs(i);
        w[x] += w[i];
        b[x] += b[i];
    }
    return;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].resize(0);
    memset(w, 0, sizeof w);
    memset(b, 0, sizeof b);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (w[i] == b[i])
            ans++;
    }
    cout << ans << '\n';
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