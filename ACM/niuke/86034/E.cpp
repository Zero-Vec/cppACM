#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
int d[N][N];
int a[N][N], n;
bool v[N][N];
struct node
{
    int x, y, st;
    bool operator<(const node &u) const
    {
        return st > u.st;
    }
};
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
priority_queue<node> pq;
void dij()
{
    pq.push({1, 1, a[1][1]});
    d[1][1] = a[1][1];
    while(pq.size()){
        auto t = pq.top();
        pq.pop();
        if(v[t.x][t.y])continue;
        v[t.x][t.y] = 1;
        for (int i = 0; i < 4;i++){
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(nx>0&&ny>0&&nx<=n&&ny<=n&&!v[nx][ny]){
                d[nx][ny] = max(a[nx][ny], d[t.x][t.y]);
                pq.push({nx, ny, d[nx][ny]});
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dij();
    // for (int i = 1; i <= n;i++)
    //     for (int j = 1; j <= n;j++)
    //         cout << d[i][j] << " \n"[j == n];
    cout << d[n][n];
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