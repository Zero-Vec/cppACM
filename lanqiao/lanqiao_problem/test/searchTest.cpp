#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
ll h[N][N];
int n, m, k;
int x2, y2;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int dp[N][N][2];
bool dfs(int x,int y,int cnt){
    if(x==x2&&y==y2)
        return true;
    if(dp[x][y][cnt]!=-1)
        return dp[x][y][cnt];
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(!h[nx][ny])continue;
        if(h[x][y]>h[nx][ny]){
            if(dfs(nx,ny,cnt))
                return dp[nx][ny][cnt] = true;
        }
        else{
            if(!cnt&&h[x][y]+k>h[nx][ny]){
                if(dfs(nx,ny,cnt+1))
                    return dp[nx][ny][cnt+1] = true;
            }
        }
    }
    return dp[x][y][cnt] = false;
}
void solve(){
    cin >> n >> m >> k;
    int x1, y1;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> h[i][j];
    memset(dp, -1, sizeof dp);
    cout << (dfs(x1, y1, 0) ? "Yes" : "No");
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