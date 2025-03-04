#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, q;
ll a[N], td[N], tdi[N];
int lowbit(int x){
    return x & -x;
}
void update(int k, ll x){
    for (int i = k; i <= n;i+=lowbit(i)){
        td[i] += x, tdi[i] += k * x;
    }
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1;i-=lowbit(i)){
        res += (k + 1) * td[i] - tdi[i];
    }
    return res;
}
void solve(){
    //树状数组区间修改 引入差分
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        update(i, a[i]), update(i + 1, -a[i]);
    }
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int l, r, v;
            cin >> l >> r >> v;
            update(l, v), update(r + 1, -v);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << getsum(r) - getsum(l - 1) << '\n';
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