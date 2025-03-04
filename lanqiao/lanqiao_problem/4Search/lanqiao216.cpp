#include<bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int N = 60;
int n, m, k;
using ll = long long;
int c[N][N];
ll dp[N][N][15][15];
int dx[] = {0, 1}, dy[] = {1, 0};
//坐标为(x,y)，最大值为mx，宝贝有cnt件的方案数
ll dfs(int x,int y,int mx,int cnt){
    ll ans = 0;
    if(x==n&&y==m)
        return 1ll * (cnt == k);
    if(dp[x][y][mx][cnt]!=-1)
        return dp[x][y][mx][cnt];
    for (int i = 0; i < 2;i++){
        int nx = dx[i] + x, ny = dy[i] + y;
        if(nx<1||ny<1||nx>n||ny>m)continue;
        if(c[nx][ny]>mx){
            // 拿宝贝
            ans = (ans + dfs(nx, ny, c[nx][ny], cnt + 1)) % P;
            //不拿
            ans = (ans + dfs(nx, ny, mx, cnt)) % P;
        }
        else{
            ans = (ans + dfs(nx, ny, mx, cnt)) % P;
        }
    }
    return dp[x][y][mx][cnt] = ans;
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> c[i][j];
            c[i][j]++;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << (dfs(1, 1, 0, 0) + dfs(1, 1, c[1][1], 1)) % P;
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