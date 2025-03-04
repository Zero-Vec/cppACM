#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int h[N][N], n, m, k;
int x2, y2;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int dp[N][N][2];
bool dfs(int x, int y, int t)
{
    // 起点和目前使用燃料次数
    if (x == x2 && y == y2)
        return true;
    if(dp[x][y][t]!=-1)
        return dp[x][y][t];
    for (int i = 0; i < 4; i++)
    {
        if (x < 1 || x > n || y < 1 || y > m)
            continue;
        int nx = dx[i] + x, ny = dy[i] + y;
        if (!t)
        { // 目前还没用
            // 不用
            if (h[x][y] > h[nx][ny] && dfs(nx, ny, 0))
                return dp[x][y][t] = true;
            // 用
            if (h[x][y] + k > h[nx][ny] && dfs(nx, ny, 1))
                return dp[x][y][t] = true;
        }
        else
        {
            if (h[x][y] > h[nx][ny] && dfs(nx, ny, 1))
                return dp[x][y][t] = true;
        }
    }
    return dp[x][y][t] = false;
}
void solve()
{
    int x1, y1;
    cin >> n >> m >> k;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];
    memset(dp, -1, sizeof dp);
    cout << (dfs(x1, y1, 0) ? "Yes\n" : "No\n");
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}