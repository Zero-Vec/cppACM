#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N][N];
bool vis[N][N];
ll ans, cnt;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void dfs(int i,int j){
    if(vis[i][j]||!a[i][j])
        return;
    cnt += a[i][j];
    vis[i][j] = 1;
    for (int k = 0; k < 4;k++){
        int nx = dx[k] + i, ny = dy[k] + j;
        dfs(nx, ny);
    }
    return;
}
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(!a[i][j]||vis[i][j])continue;
            cnt = 0;
            dfs(i, j);
            ans = max(ans, cnt);
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