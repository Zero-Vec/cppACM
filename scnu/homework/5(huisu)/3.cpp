#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=25;
int n, c[N][N];
bool v[N];
int ans=1e9, res;
void dfs(int x){
    if(res>=ans){
        return;
    }
    if(x==n+1){
        ans=min(res,ans);
        return;
    }
    for (int i = 1; i <= n;i++){
        if(v[i])continue;
        v[i] = 1;
        res += c[x][i];
        dfs(x+1);
        v[i] = 0;
        res -= c[x][i];
    }
    return;
}
void solve(){
    cin>>n;
    for (int i = 1;i<=n;i++)
        for (int j = 1; j <= n;j++)
            cin >> c[i][j];
    dfs(1);
    cout << ans << "\n";
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