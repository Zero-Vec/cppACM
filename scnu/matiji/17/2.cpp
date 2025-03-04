#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
ll a[N], t[N], n, pre[N], suf[N];
vector<ll> ls;
int bin(ll x) { return lower_bound(ls.begin(), ls.end(), x) - ls.begin() + 1; }
ll lowbit(ll x) { return x & -x; }
void update(int k,ll x){
    for (int i = k; i <= ls.size();i+=lowbit(i))
        t[i] += x;
}
ll getsum(int k){
    ll ans = 0;
    for (int i = k; i >= 1;i-=lowbit(i))
        ans += t[i];
    return ans;
}
void solve(){
    // 三元组逆序对 3 <= n <= 5e5  树状数组
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i], ls.push_back(a[i]);
    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        pre[i] = getsum(ls.size()) - getsum(bin(a[i]));
        update(bin(a[i]), 1);
    }
    // for (auto i:ls)
    //     cout << i << '\n';
    // for (int i = 1; i <= ls.size();i++)
    //     cout << t[i] << " \n"[i == ls.size()];
    memset(t, 0, sizeof t);
    for (int i = n; i >= 1;i--){
        suf[i] = getsum(bin(a[i]) - 1);
        update(bin(a[i]), 1);
    }
    for (int i = 1; i <= n;i++)
        ans += pre[i] * suf[i];
    cout << ans << '\n';
    // for (int i = 1; i <= n;i++)
    //     cout << pre[i] << " " << suf[i] << '\n';
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