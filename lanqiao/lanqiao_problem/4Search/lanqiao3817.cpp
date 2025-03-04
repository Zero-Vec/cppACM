#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
char mp[N][N];
int c[N][N];
int n, m;
bool vis[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void dfs(int x,int y,int col){  //起点和染的颜色
    if(x<1||y<1||x>n||y>m)
        return;
    if(vis[x][y])
        return;
    if(mp[x][y]=='.'){
        c[x][y] = col;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++){
            int nx = dx[i] + x, ny = dy[i] + y;
            dfs(nx, ny, col);
        }
    }
    return;
}
bool Find(int x1,int y1,int x2,int y2){
    if(c[x1][y1]==2)
        return true;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(mp[i][j]=='#'){
                bool t1 = false, t2 = false;
                for (int k = 0; k < 4;k++){
                    int nx = dx[k] + i, ny = dy[k] + j;
                    if(nx<1||nx>n||ny<1||ny>m)continue;
                    if(c[nx][ny]==1)
                        t1 = 1;
                    if(c[nx][ny]==2)
                        t2 = 1;
                }
                if(t1&&t2)
                    return true;
            }
        }
    }
    return false;
}
void solve(){
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> mp[i][j];
        }
    }
    dfs(x1, y1, 1);
    memset(vis, 0, sizeof vis);
    dfs(x2, y2, 2);
    cout << (Find(x1, y1, x2, y2) ? "Yes\n" : "No\n");
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