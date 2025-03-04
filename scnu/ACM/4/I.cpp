#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<int> s;
int n, m;
int ans = -1;
int dx[] = {0, 1}, dy[] = {1, 0};
void dfs(int x,int y,vector<vector<int>> mp,vector<vector<bool>> v){
    if(x==n-1&&y==m-1){
        for (int i = 0; i <= n * m ;i++){
            if(!s.count(i)){
                ans = max(ans, i);
                return;
            }
        }
    }
    for (int i = 0; i < 2;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m)continue;
        if(v[nx][ny])continue;
        s.insert(mp[nx][ny]);
        v[nx][ny] = 1;
        dfs(nx, ny, mp, v);
        s.erase(mp[nx][ny]);
        v[nx][ny] = 0;
    }
    return;
}
void solve(){
    //tle了。。。
    s.clear();
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(m));
    vector<vector<bool>> v(n, vector<bool>(m));
    ans = -1;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> mp[i][j];
        }
    }
    s.insert(mp[0][0]);
    v[0][0] = 1;
    dfs(0, 0,mp,v);
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