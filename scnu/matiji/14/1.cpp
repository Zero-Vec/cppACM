#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], t[N], n, m;
vector<ll> ls;
int bin(ll x){
    return lower_bound(ls.begin(), ls.end(), x) - ls.begin() + 1;
}
int lowbit(ll x){
    return x & -x;
}
void update(int k){
    for (int i = k; i <= n;i+=lowbit(i))
        t[i]++;
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1;i-=lowbit(i))
        res += t[i];
    return res;
}
void solve()
{
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ls.push_back(a[i]);
    }
    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());
    for (int i = 1; i <= n;i++){
        ans += getsum(ls.size()) - getsum(bin(a[i]));
        update(bin(a[i]));
    }
    // cout << ans << '\n';
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        int len = (r - l + 1) / 2;
        if(len & 1)
            ans ^= 1;
        cout << (ans & 1 ? 1 : 0) << '\n';
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