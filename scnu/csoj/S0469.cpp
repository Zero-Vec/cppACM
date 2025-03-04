#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll ans = 0;
    ll n;
    cin >> n;
    for (int l = 1, r=0; l <= n;l=r+1){
        ll rt = (ll)sqrt(l);
        r = min(n / (n / l), (rt + 1) * (rt + 1) - 1);
        ans += rt * (n / l) * (r - l + 1);
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