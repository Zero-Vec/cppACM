/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int mp[N][N];
int col[N][N], n, m;
bool v[N][N];
char mp1[N][N];
int ans, cnt;
set<int> s;
set<int> c;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, -1, -1, 1, 1};
bool check(int x,int y){
    if(x >= 1 && y >= 1 && x <= n && y <= m)
        return true;
    return false;
}
void dfs1(int x,int y){
    v[x][y] = 1;
    col[x][y] = ans;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(check(nx,ny)&&!v[nx][ny]&&mp[nx][ny])
            dfs1(nx, ny);
    }
    return;
}
bool dfs2(int x,int y){
    v[x][y] = 1;
    if(x==0||x==n+1||y==0||y==m+1)
        return true;
    for (int i = 0; i < 8;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(v[nx][ny]||mp[nx][ny])continue;
        if(dfs2(nx,ny))
            return true;
    }
    return false;
}
void solve(){
    cin >> n >> m;
    memset(v, 0, sizeof v);
    memset(col, 0, sizeof col);
    s.clear();
    c.clear();
    ans = 0;
    cnt = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cin >> mp1[i][j];
            mp[i][j] = mp1[i][j] - '0';
        }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(!v[i][j]&&mp[i][j]){
                ans++;
                dfs1(i, j);
            }
        }
    }
    
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout << col[i][j];
        cout << "\n";
    }
    
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(!mp[i][j]||c.count(col[i][j]))continue;
            if(s.count(col[i][j]))continue;
            memset(v, 0, sizeof v);
            c.insert(col[i][j]);
            if(!dfs2(i,j))
                s.insert(col[i][j]);
        }
    }
    cout << ans - s.size() << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int mp[N][N], m, n, ans;
char mp1[N][N];
bool v1[N][N], v2[N][N];
int dx[] = {0, 0, 1, -1, -1, 1, 1, -1}, dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
bool check(int x,int y){
    return x >= 1 && y >= 1 && x <= m && y <= n;
}
void dfs(int x,int y){
    v2[x][y] = 1;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(check(nx,ny)&&mp[nx][ny]==1&&!v2[nx][ny])
            dfs(nx, ny);
    }
    return;
}
void bfs(int x,int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    v1[x][y] = 1;
    while(q.size()){
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 8;i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(check(nx,ny)&&mp[nx][ny]&&!v2[nx][ny]){
                ans++;
                dfs(nx, ny);
            }
            if(check(nx,ny)&&!mp[nx][ny]&&!v1[nx][ny]){
                v1[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
void solve(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            v1[i][j] = v2[i][j] = 0;
    ans = 0;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++){
            cin >> mp1[i][j];
            mp[i][j]=mp1[i][j] - '0';
        }
    bool tag = 0;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            if((i==1||i==m||j==1||j==n)&&mp[i][j]==0&&!v1[i][j]){
                tag = 1;
                bfs(i, j);
            }
        }
    }
    if(!tag)
        cout << 1 << '\n';
    else
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
*/