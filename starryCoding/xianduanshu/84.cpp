#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];       // 原数组
int n;         // 原数组大小
ll t[N << 2];  // 开4倍空间，t[x]表示结点x所表示的区间的元素之和
ll lz[N << 2]; // lz[o]表示：结点o还有lazy[o]这么大的一个数字，还没加给左右儿子

void update(int s, int e, int o, ll x)
{
    //给结点o区间每个元素异或x，看区间元素个数，偶数相当于异或0，奇数相当于异或一个x
    t[o] ^= ((e - s + 1) & 1) ? x : 0;
    lz[o] ^= x;//还有x这个任务得下放
}

void pushup(int o)
{
    // 上拉操作，用儿子信息更新自己信息
    t[o] = t[o << 1] ^ t[o << 1 | 1];
}

// 建树、递归
void buildTree(int s = 1, int e = n, int o = 1)
{
    if (s == e)
    {
        t[o] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    buildTree(s, mid, o << 1);
    buildTree(mid + 1, e, o << 1 | 1);
    pushup(o);
}

void pushdown(int s, int e, int o)
{
    // 下放操作：当前操作区间和结点编号
    if (!lz[o])
        return;
    // ls表示左儿子编号，rs表示右儿子编号
    int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
    // 注意此处的lazy传递是重点！
    // lz[o]表示区间每个点都要加上lz[o]
    // 于是对于t(区间和)来说要乘上一个区间长度
    update(s, mid, o << 1, lz[o]);
    update(mid + 1, e, o << 1 | 1, lz[o]);
    // 完成任务
    lz[o] = 0;
}

// 区间修改
// 将区间[l,r]上都加上x,采用递归形式，当走到目标区间内，就对应的t[o]和lz[o]作出修改，本函数是线段树的精髓
void add(int l, int r, ll x, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
    {
        // 当前操作区间已经完全进入目标区间
        // 当前节点信息应当直接被修改并打上lz标记，不再往下走
        update(s, e, o, x);
        return;
    }
    // 向下走之前，一定要pushdown
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    // 判断是否需要向左走，如果左儿子区间[s,mid]和[l,r]有交集，就要走
    if (mid >= l)
        add(l, r, x, s, mid, o << 1);
    if (mid + 1 <= r)
        add(l, r, x, mid + 1, e, o << 1 | 1);
    // 递归回来的时候记得pushup
    pushup(o);
}

ll query(int l, int r, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
    {
        // 当前操作区间已经完全进入目标区间
        // 到当前节点时，t[o]为正确的值
        return t[o];
    }

    ll res = 0; // 记录结果

    // 向下走之前，一定要pushdown
    pushdown(s, e, o);

    // 注意mid = (s + e) >> 1,而不是(l + r) >> 1
    int mid = (s + e) >> 1;
    // 判断是否需要向左走，如果左儿子区间[s, mid]和[l, r]有交集，就要走
    if (mid >= l)
        res ^= query(l, r, s, mid, o << 1); // 无需返回值
    // 判断是否需要向右走，如果右儿子区间[mid+1,e]和[l, r]有交集，就要走
    if (mid + 1 <= r)
        res ^= query(l, r, mid + 1, e, o << 1 | 1);
    // query没有进行修改，所以可以不pushup，当然写上也不影响

    return res;
}

void solve()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    buildTree();
    int op, l, r;
    ll x;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> x;
            add(l, r, x, 1, n, 1);
        }
        else if (op == 2)
        {
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << '\n';
        }
    }
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