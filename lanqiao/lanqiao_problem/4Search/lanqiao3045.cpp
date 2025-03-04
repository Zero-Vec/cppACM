#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
typedef pair<int, int> PII;
int mp[N][N];
bool v[N][N];
int x1, y1;
int x2, y2;
int n, m;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int cnt;
int bfs(){
    queue<PII> q;
    q.push(make_pair(x1, y1));
    v[x1][y1] = 1;
    while(q.size()){
        int s = q.size();
        while(s--){
            int qx = q.front().first, qy = q.front().second;
            q.pop();
            if(qx==x2&&qy==y2)
                return cnt;
            for (int i = 0; i < 4;i++){
                int nx = qx + dx[i], ny = qy + dy[i];
                if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]==1)continue;
                v[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
        cnt++;
    }
}
void solve(){
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> mp[i][j];
    cout << bfs();
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n, m, x2, y2;
int mp[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool st[N][N];
int dfs(int x,int y,int sum){
    if(x==x2&&y==y2){
        return sum;
    }
    st[x][y] = 1;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx<1||ny<1||nx>n||ny>m)continue;
        if(mp[nx][ny]==1)continue;
        if(!st[nx][ny]){
            ans = min(dfs(nx, ny, sum + 1), ans);
            st[nx][ny] = 0;
        }
    }
    return ans;
}
void solve(){
    cin >> n >> m;
    int x1, y1;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> mp[i][j];
    cout << dfs(x1, y1, 0);
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
*/