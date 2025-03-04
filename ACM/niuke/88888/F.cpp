#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

#define lson (rt << 1)
#define rson (rt << 1 | 1)
int lowbit(int x)
{
    return x & (-x);
}
int a[100005];
struct node
{
    i64 sum, lz;
} tr[100005 << 2];

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tr[rt].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tr[rt].sum = std::min(tr[lson].sum, tr[rson].sum);
}

void update(int rt, int l, int r, int L, int R, int x)
{
    if (l >= L && r <= R)
    {
        tr[rt].sum = x;
        return;
    }
    int mid = l + r >> 1;
    if (mid >= L)
        update(lson, l, mid, L, R, x);
    if (mid < R)
    {
        update(rson, mid + 1, r, L, R, x);
    }
    tr[rt].sum = std::min(tr[lson].sum, tr[rson].sum);
}

i64 query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
    {
        return tr[rt].sum;
    }
    i64 ans = 1e9 + 1;
    int mid = l + r >> 1;
    if (mid >= L)
        ans = std::min(ans, query(lson, l, mid, L, R));
    if (mid < R)
        ans = std::min(ans, query(rson, mid + 1, r, L, R));
    return ans;
}

void solve()
{
    int t;
    std::cin >> t;
    int n = 0;
    std::vector<int> pre(t + 1);
    for (int i = 1; i <= t; i++)
    {
        int x;
        std::cin >> x;
        n += x;
        pre[i] = pre[i - 1] + x;
        for (int j = pre[i - 1] + 1; j <= pre[i]; j++)
        {
            std::cin >> a[j];
        }
    }
    // std::cout << n << '\n';
    build(1, 1, n);

    int m;
    std::cin >> m;
    while (m--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int i, j, x;
            std::cin >> i >> j >> x;
            int pos = pre[i - 1] + j;
            update(1, 1, n, pos, pos, x);
        }
        else
        {
            int x;
            std::cin >> x;
            std::cout << query(1, 1, n, 1, pre[x]) << '\n';
        }
    }
}

// 线段树维护区间最小值，单点修改，区间查询的板子
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}