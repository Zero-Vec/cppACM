#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, x, y;
const int N = 110;
int mp[N][N];
bool v[N][N];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx1[] = {0, 0, 1, -1}, dy1[] = {1, -1, 0, 0};
int ans = 0;
bool isvalid(int x,int y){
    if(x<1||y<1||x>n||y>n)
        return false;
    return true;
}
void dfs(int x,int y){
    if(mp[x][y]==0){
        v[x][y] = 1;
        for (int i = 0; i < 4; i++){
            int nx = dx1[i] + x, ny = dy1[i] + y;
            if (!isvalid(nx,ny)||v[nx][ny])
                continue;
            dfs(nx, ny);
        }
    }
    return;
}
void solve(){
    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        mp[x][y] = -1e5;
        for (int i = 0; i < 8;i++){
            int nx = dx[i] + x, ny = dy[i] + y;
            if(!isvalid(nx,ny))continue;
            mp[nx][ny]++;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(mp[i][j]>0){
                ans++;
                continue;
            }
            if(v[i][j])continue;
            if(mp[i][j]==0){
                dfs(i, j);
                ans++;
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