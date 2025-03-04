#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int mp[N][N], tmp[N][N], n, m, k, t;
void process()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                tmp[i][j] = tmp[i + 1][j] = tmp[i - 1][j] = tmp[i][j + 1] = tmp[i][j - 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[i][j] = tmp[i][j];
}
void solve()
{
    cin >> n >> m >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
        process();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j])
                ans++;
    // cout << mp[i][j] << " \n"[j == m];
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