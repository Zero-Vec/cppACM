#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
const ll inf = 4e18;
ll d[N][N], n, k, u, v;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            d[i][j] = inf;
    for (int i = 1; i <= n;i++)
        d[i][i] = 0;
    for (int i = 1; i <= n;i++){
        cin >> u >> k;
        while(k--){
            cin >> v;
            d[u][v] = min(d[u][v], 1ll);
        }
    }
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n;i++)
        cout << i << " " << (d[1][i] == inf ? -1 : d[1][i]) << '\n';
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