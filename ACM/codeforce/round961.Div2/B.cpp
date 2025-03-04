#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
void solve(){
    ll n, m;
    cin >> n >> m;
    map<int, ll> mp;
    for (int i = 1; i <= n;i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for(auto [x,y]:mp){
        ans = max(ans, min(y, m / x) * x);
        if(mp.count(x + 1)){
            for (ll i = 1; i <= y && i <= m / x;i++){
                ans = max(ans, i * x + min(mp[x + 1], (m - i * x) / (x + 1)) * (x + 1));
            }
        }
    }
    cout << ans << '\n';
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