#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, key;
const int N = 1e5 + 9;
string mp[N];
int ans, cnt;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void dfs(int x,int y){
    if(mp[x][y]>'1')
        key++;
    mp[x][y] = '0';
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx<0||ny<0||nx>n-1||ny>m-1||mp[nx][ny]=='0')continue;
        dfs(nx, ny);
    }
    return;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin >> mp[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == '0')continue;
            ans++;
            key = 0;
            dfs(i, j);
            if (key)
                cnt++;
        }
    }
    cout << ans << " " << cnt;
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