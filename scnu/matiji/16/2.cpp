#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 998244353, N = 1e6 + 9;
ll a, n;
void solve(){
    // P序列
    cin >> n;
    ll mx = 0;
    map<ll, int> mp;
    for (int i = 1; i <= n;i++){
        cin >> a;
        mx = max(mx, a);
        mp[a]++;
    }
    ll ans = 1;
    // cout << mx << '\n';
    for(auto [x,y]:mp){
        if(x == mx)continue;
        ans = ans * (y + 1) % p;
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