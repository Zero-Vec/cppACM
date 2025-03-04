#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int ans = 0, v[300], top;
struct edge{
    int x, y, w;
    bool operator<(const edge &u) const
    {
        return w < u.w;
    }
} e[N];
struct node{
    int f[N], a, b;
    inline int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    inline void merge(int i){
        a = find(e[i].x);
        b = find(e[i].y);
        if(a != b)
            f[b] = a;
    }
} ff[540], t;
int check(node &b){
    int i, j;
    for (i = 1; i < top;i++)
        if(b.find(v[i]) != b.find(v[i + 1]))
            return 0;
    return 1;
}
int find_block(int n){
    int l = 0, r = n + 1, m;
    while(l + 1 < r){
        m = (l + r) >> 1;
        if(check(ff[m]))
            r = m;
        else
            l = m;
    }
    return l;
}
int f[N];
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void solve(){
    int n, m, k, x, now = 1, i, j, y, q, l, r, p, c, a, b, siz;
    // cin >> n >> m >> q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m;i++)
        // cin >> e[i].x >> e[i].y >> e[i].w;
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    sort(e + 1, e + 1 + m);
    j = 1;
    for (i = 1; i <= n;i++)
        f[i] = i;
    for (i = 1; i <= m;i++){
        a = find(e[i].x);
        b = find(e[i].y);
        e[j] = e[i];
        if(a != b){
            f[b]=a;
            j++;
        }
    }
    m = j - 1;
    siz = max(10, (int)(sqrt(m / 3)));
    for (i = 1; i <= n;i++){
        t.f[i] = i;
    }
    ff[0] = t;
    for (i = 1;i<=m;i++){
        t.merge(i);
        if(i % siz == 0)
            ff[i / siz] = t;
    }
    while(q--){
        // cin >> l >> r >> p >> c;
        scanf("%d%d%d%d", &l, &r, &p, &c);
        top = 0;
        i = l / p * p + c;
        if(i < l)
            i += p;
        for (; i <= r;i+=p){
            top++;
            v[top] = i;
        }
        x = find_block(m / siz);
        t = ff[x];
        for (i = x * siz + 1; i <= m;i++){
            t.merge(i);
            if(check(t)){
                // cout << e[i].w << '\n';
                printf("%d\n", e[i].w);
                break;
            }
        }
        if(i > m)
            puts("error");
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