#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cal(ll x){
    int ans = 0;
    while(x){
        ans += (x & 1);
        x >>= 1;
    }
    return ans;
}
void solve(){
    ll n;
    cin >> n;
    ll ans = cal(n);
    cout << ans << " ";
    ll res = 1;
    while(ans--){
        res *= 2;
    }
    cout << res - 1 << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}