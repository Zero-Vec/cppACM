#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char mp[510][510];
int n, m;
int pre[510][510];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(mp[i][j]=='.')
                pre[i][j] = 0;
            else{
                if(pre[i][j-1])
                    pre[i][j] = pre[i][j - 1];
                else
                    pre[i][j] = j;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(mp[i][j]=='*'){
                int l = j - 1, r = j + 1, d = i + 1;
                while(l>=1&&r<=m&&mp[d][l]=='*'&&mp[d][r]=='*'&&d<=n){
                    if(pre[d][r]<=l)
                        ans++;
                    l--, r++, d++;
                }
            }
        }
    }
    cout << ans;
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