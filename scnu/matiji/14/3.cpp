#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
ll a[N], t[N], n, m;
int lowbit(ll x) { return x & -x; }
void update(int k,ll x){
    for (int i = k; i <= n;i+=lowbit(i))
        t[i] ^= x;
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1;i-=lowbit(i))
        res ^= t[i];
    return res;
}
void solve(){
    // 区间异或和 也是树状数组的模板题
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        update(i, a[i]);
    }
    while(m--){
        ll op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
            update(x, y);
        else
            cout << (getsum(y) ^ getsum(x - 1)) << '\n';
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