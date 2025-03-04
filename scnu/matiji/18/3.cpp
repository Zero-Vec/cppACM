#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9, p = 1e9 + 7;
struct query{
    ll l, r, x, old;
} q[N];
struct arr{
    ll x, old;
} a[N];
ll n, m, vis[N], t[N], res[N];
bool cmp1(query aa, query bb) { return aa.x > bb.x; }
bool cmp2(arr aa, arr bb) { return aa.x < bb.x; }
ll lowbit(ll x) { return x & -x; }
void update(ll x,ll k){
    while(x < N){
        t[x] += k;
        x += lowbit(x);
    }
}
ll ask(ll x){
    ll ans = 0;
    while(x > 0){
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i].x, a[i].old = i;
    for (int i = 1; i <= m;i++)
        cin >> q[i].l >> q[i].r >> q[i].x, q[i].old = i;
    sort(a + 1, a + 1 + n, cmp2);
    sort(q + 1, q + 1 + m, cmp1);
    ll id = n;
    for (int i = 1; i <= m;i++){
        if(!vis[q[i].x]){
            vis[q[i].x] = 1;
            while(id >= 1 && a[id].x >= q[i].x){
                update(a[id].old, 1);
                id--;
            }
        }
        res[q[i].old] = ask(q[i].r) - ask(q[i].l - 1);
    }
    for (int i = 1; i <= m;i++)
        cout << res[i] << '\n';
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