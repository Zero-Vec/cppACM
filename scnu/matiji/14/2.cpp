#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
ll a[N], t[N], n;
int lowbit(ll x) { return x & -x; }
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
void solve(){
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        a[i]++;
        ans += getsum(n) - getsum(a[i]);
        update(a[i]);
    }
    cout << ans << '\n';
    for (int i = 1; i < n;i++){
        ans += n - 2 * a[i] + 1;
        cout << ans << '\n';
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