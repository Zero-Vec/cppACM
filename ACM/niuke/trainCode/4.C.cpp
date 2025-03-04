#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char mp[110][110];
int op[110], z[110];
void solve(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> mp[i][j];
    int p, q;
    cin >> p >> q;
    for (int i = 1; i <= q;i++){
        cin >> op[i] >> z[i];
    }
    for (int i = 1; i <= p;i++){
        for (int j = 1; j <= q;j++){
            if (op[j] == 1)
            {
                char t = mp[z[j]][m];
                for (int i = m; i > 1; i--)
                {
                    mp[z[j]][i] = mp[z[j]][i - 1];
                }
                mp[z[j]][1] = t;
            }
            else
            {
                char t = mp[n][z[j]];
                for (int i = n; i > 1; i--)
                {
                    mp[i][z[j]] = mp[i - 1][z[j]];
                }
                mp[1][z[j]] = t;
            }
        }
    }
    cout << mp[x][y];
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