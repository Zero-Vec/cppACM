#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k;
const int N = 110;
char mp[N][N];
int ans;
int dp[110][110][10][2];
int dfs(int x,int y,int cnt,int v){
    int res = 0;
    if(dp[x][y][cnt][v]!=-1){
        return dp[x][y][cnt][v];
    }
    if(x==n&&y==m){
        return dp[x][y][cnt][v] = 1;
    }
    if(cnt>k||x<1||x>n||y<1||y>m||mp[x][y]=='#')
        return dp[x][y][cnt][v] = 0;
    if(cnt==k){
        if(v==0){
            res+=dfs(x + 1, y, cnt, 0);
        }
        else{
            res+=dfs(x, y + 1, cnt, 1);
        }
    }
    else{
        if(v==0){
            //考虑改不改变方向
            res+=dfs(x + 1, y, cnt, 0);
            res+=dfs(x, y + 1, cnt + 1, 1);
        }
        else{
            //考虑改不改变方向
            res+=dfs(x, y + 1, cnt, 1);
            res+=dfs(x + 1, y, cnt + 1, 0);
        }
    }
    return dp[x][y][cnt][v] = res;
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> mp[i][j];
    memset(dp, -1, sizeof dp);
    ans+=dfs(1, 2, 0, 1);
    memset(dp, -1, sizeof dp);
    ans+=dfs(2, 1, 0, 0);//0表示当前向下走，1表示当前向右走
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