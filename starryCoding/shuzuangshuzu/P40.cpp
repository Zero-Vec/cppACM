#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], t[N];
int n, q;
int lowbit(ll x){
    return x & -x;
}
void update(int k,int x){
    for (int i = k; i <= n;i+=lowbit(i))
        t[i] += x;
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1;i-=lowbit(i))
        res += t[i];
    return res;
}
void solve(){
    // 树状数组可以求一个数前面有多少个数比它小
    // 树状数组单点修改
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        update(i, a[i]);
    }
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int k, v;
            cin >> k >> v;
            update(k, v);
        }
        else{
            int l, r;
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