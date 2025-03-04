#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100;
const ll inf = 2e18;
char mp[N][N];
int n, m, k;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int getid(int x, int y)
{
    return (x - 1) * m + y;
}
struct node
{
    ll x, w;
    bool operator<(const node &u) const
    {
        return w > u.w;
    }
};
vector<node> g[N * N];
bool v[N * N];
ll d[N * N];
void dij(int st)
{
    priority_queue<node> pq;
    d[st] = 0;
    pq.push({st, d[st]});
    while (pq.size())
    {
        node t = pq.top();
        pq.pop();
        if (v[t.x])
            continue;
        v[t.x] = 1;
        for (auto i : g[t.x])
        {
            if (d[t.x] + i.w < d[i.x])
            {
                d[i.x] = d[t.x] + i.w;
                pq.push({i.x, d[i.x]});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int st = getid(x1, y1), ed = getid(x2, y2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n * m; i++)
        d[i] = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int t1 = getid(i, j);
            if (mp[i][j] == '#' && (i != x1 && j != y1))
            {
                for (int z = 0; z < 4; z++)
                {
                    int ni = i + dx[z], nj = j + dy[z];
                    if (ni < 1 || nj < 1 || ni > n || nj > m)
                        continue;
                    int t2 = getid(ni, nj);
                    g[t1].push_back({t2, inf});
                }
            }
            if (mp[i][j] == '.' || (i == x1 && j == y1))
            {
                for (int z = 0; z < 4; z++)
                {
                    int ni = i + dx[z], nj = j + dy[z];
                    if (ni < 1 || nj < 1 || ni > n || nj > m)
                        continue;
                    int t2 = getid(ni, nj);
                    if (mp[ni][nj] == '.')
                    {
                        g[t1].push_back({t2, 1});
                    }
                    else
                    {
                        g[t1].push_back({t2, inf});
                    }
                }
            }
        }
    }
    cin >> k;
    while (k--)
    {
        int x1, y1, x2, y2, p;
        cin >> x1 >> y1 >> x2 >> y2 >> p;
        int st1 = getid(x1, y1), ed1 = getid(x2, y2);
        g[st1].push_back({ed1, p});
    }
    int e;
    cin >> e;
    dij(st);
    cout << (d[ed] <= e ? e - d[ed] : -1);
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