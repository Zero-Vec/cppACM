#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, ans;
void solve(){
    cin >> n;
    for (ll l = 1, r = 1; l <= n;l = r + 1){
        r = min(n, n / (n / l));
        ans += (n / l) * (r - l + 1);
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