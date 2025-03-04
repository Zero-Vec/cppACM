#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
const ll inf = 2e18;
int n, m;
struct node
{
    ll x;
    ll e;
    bool operator<(const node &u) const
    {
        return e > u.e;
    }
};
vector<node> g[N];
ll d[N];
bool v[N];
void dij(int x)
{
    d[x] = 0;
    priority_queue<node> pq;
    pq.push({x, d[x]});
    while (pq.size())
    {
        auto [x, e] = pq.top();
        pq.pop();
        if (v[x])
            continue;
        v[x] = 1;
        // 拓展
        for (auto [y, ey] : g[x])
        {
            if (d[x] + ey < d[y])
            {
                d[y] = ey + d[x];
                pq.push({y, d[y]});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    dij(1);
    for (int i = 1; i <= n; i++)
        cout << (d[i] >= inf ? -1 : d[i]) << ' ';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}