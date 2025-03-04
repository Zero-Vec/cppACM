#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 410;
const ll inf = 2e18;
ll d[N][N];
int n, m, q;
void solve()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = inf;
    while(m--){
        ll u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for (int i = 1; i <= n;i++)
        d[i][i] = 0;
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while(q--){
        int st, ed;
        cin >> st >> ed;
        cout << (d[st][ed] == inf ? -1 : d[st][ed]) << '\n';
    }
}
int main()
{
    // Floyd
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}