#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, T = 20;

vector<int> g[N];
int dfn[N], idx;
int tMax[N << 2], tMin[N << 2];
int n;

int fa[N][30], dep[N];

void dfs(int x)
{
    dep[x] = dep[fa[x][0]] + 1;
    dfn[x] = ++idx;
    for (int i = 1; i <= T; ++i)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (const auto &i : g[x])
    {
        dfs(i);
    }
}

void pushup(int o)
{
    tMax[o] = max(tMax[o << 1], tMax[o << 1 | 1]);
    tMin[o] = min(tMin[o << 1], tMin[o << 1 | 1]);
}

void buildTree(int s = 1, int e = n, int o = 1)
{
    if (s == e)
    {
        tMax[o] = dfn[s];
        tMin[o] = dfn[s];
        return;
    }

    int mid = s + e >> 1;
    buildTree(s, mid, o << 1);
    buildTree(mid + 1, e, o << 1 | 1);
    pushup(o);
}

int queryMax(int l, int r, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
        return tMax[o];

    int ans = 0;
    int mid = s + e >> 1;
    if (mid >= l)
        ans = max(ans, queryMax(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        ans = max(ans, queryMax(l, r, mid + 1, e, o << 1 | 1));
    return ans;
}

int queryMin(int l, int r, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
        return tMin[o];

    int ans = N;
    int mid = s + e >> 1;
    if (mid >= l)
        ans = min(ans, queryMin(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        ans = min(ans, queryMin(l, r, mid + 1, e, o << 1 | 1));
    return ans;
}

int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = T; i >= 0; --i)
    {
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    }
    if (x == y)
        return x;
    for (int i = T; i >= 0; --i)
    {
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        cin >> fa[i][0];
        g[fa[i][0]].push_back(i);
    }
    dfs(1);
    buildTree();
    //    for(int i = 1; i <= n; ++i) cout << dfn[i] << ' ';
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
        mp[dfn[i]] = i;
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int l, r;
        cin >> l >> r;
        int x = mp[queryMin(l, r)], y = mp[queryMax(l, r)];
        cout << lca(x, y) << '\n';
    }

    return 0;
}