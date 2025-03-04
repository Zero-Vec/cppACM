#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], b[N], c[N], n, q;
struct query{
    int l, r, id;
} qy[N];
vector<pair<int, int>> items;
ll lowbit(ll x) { return x & -x; }
void update(int i,int x){
    for (; i <= n;i+=lowbit(i))
        c[i] += x;
}
ll sum(int i){
    ll ans = 0;
    for (; i > 0;i-=lowbit(i))
        ans += c[i];
    return ans;
}
bool cmp1(int x, int y) { return a[x] < a[y]; }
bool cmp2(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
bool cmp3(query a, query b) { return a.l > b.l; }
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n;i++)
        cin >> a[i], b[i] = i;
    sort(b + 1, b + 1 + n, cmp1);
    items.push_back({b[1], b[2]});
    items.push_back({b[n - 1], b[n]});
    for (int i = 2; i < n;i++){
        ll val1 = a[b[i]] - a[b[i - 1]];
        ll val2 = a[b[i + 1]] - a[b[i]];
        if(val1<=val2)
            items.push_back({b[i], b[i - 1]});
        if(val2<=val1)
            items.push_back({b[i], b[i + 1]});
    }
    for(auto &it:items)
        if(it.first > it.second)
            swap(it.first, it.second);
    sort(items.begin(), items.end(), cmp2); // 降序
    for (int i = 1; i <= q;i++)
        cin >> qy[i].l >> qy[i].r, qy[i].id = i;
    sort(qy + 1, qy + q + 1, cmp3);
    int pos = 0;
    ll ans = 0;
    for (int i = 1; i <= q;i++){
        while(pos < items.size() && qy[i].l <= items[pos].first)
            update(items[pos++].second, 1);
        ans += sum(qy[i].r) * qy[i].id;
    }
    cout << ans << '\n';
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