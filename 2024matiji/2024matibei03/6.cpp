#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
const ll inf = 2e18;
ll d[N][N];
int n, u, k, v;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = inf;
    int t = n;
    while (t--)
    {
        cin >> u >> k;
        while (k--)
        {
            cin >> v;
            d[u][v] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
    for (int i = 1; i <= n; i++)
        cout << i << " " << (d[1][i] == inf ? -1 : d[1][i]) << '\n';
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