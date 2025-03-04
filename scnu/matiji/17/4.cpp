#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll n, a[N], c[N], sum[N], m, ans[N];
map<ll, ll> mp;
ll lowbit(ll x) { return x & -x; }
void update(int i,ll x){
    for (;i<=n;i+=lowbit(i))
        c[i] ^= x;
}
ll query(int i){
    ll ans = 0;
    for (; i > 0;i-=lowbit(i))
        ans ^= c[i];
    return ans;
}
struct qy{
    int l, r, id;
    bool operator<(const qy &u)const{
        return r < u.r;
    }
} q[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    cin >> m;
    for (int i = 1; i <= m;i++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int pos = 1;
    for (int i = 1; i <= m;i++){
        while(pos<=q[i].r){
            if(mp.find(a[pos])!=mp.end()){
                update(mp[a[pos]],a[pos]);
                update(pos, a[pos]);
                mp[a[pos]] = pos;
            }
            else{
                mp[a[pos]] = pos;
                update(pos, a[pos]);
            }
            pos++;
        }
        ans[q[i].id] = sum[q[i].l - 1] ^ sum[q[i].r] ^ query(q[i].r) ^ query(q[i].l - 1);
    }
    for (int i = 1; i <= m;i++)
        cout << ans[i] << '\n';
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