#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, k;
    cin >> n >> k;
    if(k==1){
        cout << 1 << '\n';
        return;
    }
    ll ans = 1;
    while(n){
        ans = max(ans, n % k);
        n /= k;
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