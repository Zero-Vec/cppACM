#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    while(a>=2 && b>=1){
        ans += 3;
        a -= 2, b--;
    }
    cout << ans + a;
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