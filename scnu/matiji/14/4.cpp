#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    double x, y;
    int id;
} a[N], b[N];
struct edge{
    int u, v;
    double w;
} e[N << 1];
int n, m, pre[N];
double k;
bool cmp1(node x, node y) { return x.x < y.x; }
bool cmp2(node x, node y) { return x.y < y.y; }
bool cmp3(edge x, edge y) { return x.w < y.w; }
void init(int n){
    for (int i = 1; i <= n;i++)
        pre[i] = i;
}
int find(int x) { return pre[x] = (pre[x] == x ? x : find(pre[x])); }
void merge(int i,int j){
    int x = find(i), y = find(j);
    if(x != y)
        pre[x] = y;
}
bool sol(int l,int r){ // 分治求最近点对
    if(l>=r)
        return 1;
    int mid = (l + r) >> 1, cnt = 0;
    if(!sol(l,mid) || !sol(mid+1,r))
        return false;
    while(k<a[mid].x-a[l].x)
        l++;
    while(a[r].x-a[mid].x>k)
        r--;
    for (int i = l; i <= r;i++)
        b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1, cmp2);
    for (int i = 1; i <= cnt;i++){
        for (int j = i + 1; j <= cnt;j++){
            if(b[j].y-b[i].y>k)
                break;
            if(fabs(b[j].x-b[i].x) <= k && find(b[i].id) != find(b[j].id))
                return false;
        }
    }
    return true;
}
bool check(int x){
    init(n);
    for (int i = 1; i <= m;i++){
        if(e[i].w>e[x].w)
            break;
        merge(e[i].u, e[i].v);
    }
    return sol(1, n);
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i].x >> a[i].y, a[i].id = i;
    for (int i = 1; i <= m;i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(a + 1, a + 1 + n, cmp1);
    sort(e + 1, e + m + 1, cmp3);
    int l = 0, r = m, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << fixed << setprecision(3) << e[ans].w << '\n';
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