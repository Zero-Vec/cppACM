#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    int l, r, cnt, lz;
    vector<int> val;
}tree[4*N];
int n, m, a[N];
vector<int> ans;

void lazy(int p,int v){
    tree[p].lz += v;
    for (int i = 0;i<tree[p].cnt;i++)
        tree[p].val[i] += v;
}

void pushdown(int p){
    lazy(p * 2, tree[p].lz);
    lazy(p * 2 + 1, tree[p].lz);
    tree[p].lz = 0;
}

void pushup(int p){
    vector<int> tmp;
    int i = 0, j = 0;
    int cnt_l = tree[p * 2].cnt, cnt_r = tree[p * 2 + 1].cnt;
    vector<int> val_l = tree[p * 2].val, val_r = tree[p * 2 + 1].val;
    while(i<cnt_l&&j<cnt_r)
        tmp.emplace_back(val_l[i] > val_r[j] ? val_l[i++] : val_r[j++]);
    while(i<cnt_l)
        tmp.emplace_back(val_l[i++]);
    while(j<cnt_r)
        tmp.emplace_back(val_r[j++]);
    tree[p].val.clear();
    for (int i = 0; i < tree[p].cnt;i++)
        tree[p].val.emplace_back(tmp[i]);
}

void build(int p,int l,int r){
    tree[p].l = l, tree[p].r = r;
    if(l == r){
        tree[p].cnt = 1;
        tree[p].val.emplace_back(a[l]);
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].cnt = min(tree[p * 2].cnt + tree[p * 2 + 1].cnt, 36);
    pushup(p);
}

void update(int l,int r,int c,int p){
    int s = tree[p].l, t = tree[p].r;
    if(l <= s && t <= r)
        return lazy(p, c);
    if(tree[p].lz)
        pushdown(p);
    int mid = s + ((t - s) >> 1);
    if(l <= mid)
        update(l, r, c, p * 2);
    if(r > mid)
        update(l, r, c, p * 2 + 1);
    pushup(p);
}

void merge(int p){
    vector<int> tmp;
    int i = 0, j = 0, cnt = tree[p].cnt;
    vector<int> val = tree[p].val;
    while(i<cnt&&j<ans.size())
        tmp.emplace_back(val[i] > ans[j] ? val[i++] : ans[j++]);
    while(i<cnt)
        tmp.emplace_back(val[i++]);
    while(j<ans.size())
        tmp.emplace_back(ans[j++]);
    ans.clear();
    for (int i = 0; i < min((int)tmp.size(), 36);i++)
        ans.emplace_back(tmp[i]);
}

void query(int l,int r,int p){
    int s = tree[p].l, t = tree[p].r;
    if(l<=s&&t<=r){
        merge(p);
        return;
    }
    if(tree[p].lz)
        pushdown(p);
    int mid = s + ((t - s) >> 1);
    if(l<=mid)
        query(l, r, p * 2);
    if(r>mid)
        query(l, r, p * 2 + 1);
    return;
}

int op, l, r, v;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    build(1, 1, n);
    while(m--){
        cin >> op >> l >> r;
        if(op == 1){
            cin >> v;
            update(l, r, v, 1);
        }
        else{
            if(l == r){
                cout << "-1" << '\n';
                continue;
            }
            ans.clear();
            query(l, r, 1);
            int mx = 0;
            for (int i = 0; i < ans.size();i++)
                for (int j = i + 1; j < ans.size();j++)
                    mx = max(mx, ans[i] & ans[j]);
            cout << mx << '\n';
        }
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