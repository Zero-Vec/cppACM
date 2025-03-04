#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 9;
int a[N][15];
// num1初始化后的固定属性，相应区域1的个数；lz懒标记；ans是正确的个数，动态变化
struct node{
    int l, r, num1, lz, ans;
} tree[16][4 * N];
void build(int tr,int p,int l,int r){
    tree[tr][p].lz = -1;
    tree[tr][p].l = l, tree[tr][p].r = r;
    if(l == r){
        tree[tr][p].num1 = a[l][tr];
        tree[tr][p].ans = (a[l][tr] == 0 ? 1 : 0);
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(tr, p * 2, l, mid);
    build(tr, p * 2 + 1, mid + 1, r);
    tree[tr][p].num1 = tree[tr][p * 2].num1 + tree[tr][p * 2 + 1].num1;
    tree[tr][p].ans = tree[tr][p * 2].ans + tree[tr][p * 2 + 1].ans;
}
void lazy(int tr,int p,int v){
    int s = tree[tr][p].l, t = tree[tr][p].r;
    tree[tr][p].lz = v;
    if(v)
        tree[tr][p].ans = tree[tr][p].num1;
    else
        tree[tr][p].ans = t - s + 1 - tree[tr][p].num1;
}
void pushdown(int tr,int p){
    lazy(tr, 2 * p, tree[tr][p].lz);
    lazy(tr, 2 * p + 1, tree[tr][p].lz);
    tree[tr][p].lz = -1;
}
void update(int tr,int p,int l,int r,int c){
    int s = tree[tr][p].l, t = tree[tr][p].r;
    if(l <= s && t <= r)
        return lazy(tr, p, c);
    if(tree[tr][p].lz!=-1)
        pushdown(tr, p);
    int mid = s + ((t - s) >> 1);
    if(l <= mid)
        update(tr, p * 2, l, r, c);
    if(r>mid)
        update(tr, p * 2 + 1, l, r, c);
    tree[tr][p].ans = tree[tr][p * 2].ans + tree[tr][p * 2 + 1].ans;
}
void solve(){
    int n, m, q;
    string str;
    cin >> n >> m >> q;
    for (int i = 1; i <= n;i++){
        cin >> str;
        for (int j = 1; j <= m;j++)
            a[i][j] = str[j - 1] - '0';
    }
    for (int i = 1; i <= m; i++)
        build(i, 1, 1, n);
    while(q--){
        int x1, x2, y1, y2, w, ans = 0;
        cin >> x1 >> x2 >> y1 >> y2 >> w;
        for (int i = y1; i <= y2;i++)
            update(i, 1, x1, x2, w);
        for (int i = 1; i <= m;i++)
            ans += tree[i][1].ans;
        cout << ans << '\n';
    }
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