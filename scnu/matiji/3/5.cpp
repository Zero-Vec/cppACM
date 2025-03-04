#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int n, k, g[N][N], cnt;
void solve(){
    cin >> n >> k;
    for (int i = 1, x, y; i <= n;i++){
        cin >> x >> y;
        x = (x - 1) % k + 1, y = (y - 1) % k + 1;
        g[x][y] ^= 1;
    }
    for (int i = 1; i <= k;i++)
        if(g[i][1])
            for (int j = 1; j <= k;j++)
                g[i][j] ^= 1;
    for (int i = 1; i <= k;i++)
        if(g[1][i])
            for (int j = 1; j <= k;j++)
                g[j][i] ^= 1;
    for (int i = 1; i <= k;i++)
        for (int j = 1; j <= k;j++)
            if(g[i][j])
                cnt++;
    if(cnt==k*k||!cnt)
        cout << "YES\n";
    else
        cout << "NO\n";
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