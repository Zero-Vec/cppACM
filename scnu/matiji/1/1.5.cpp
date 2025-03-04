#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 107;
int k, n, m, ma[N][N], ans;
void solve(){
    cin >> k >> n >> m;
    int u, v;
    for (int i = 1; i <= m;i++){
        cin >> u >> v;
        ma[u][v] = ma[v][u] = 1;
    }
    if(n<=k)
        cout << m;
    else{
        for (int i = 1; i <= n;i++){
            for (int j = i + 1; j <= n;j++){
                int cnt = 0;
                for (int l = 1; l <= n;l++){
                    if(ma[i][l]&&ma[j][l])
                        cnt++;
                }
                ans = max(ans, m - cnt);
            }
        }
        cout << ans;
    }
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