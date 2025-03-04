#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    //数三角形个数
    int n;
    cin >> n;
    ll ans = (n & 1 ? 1ll * (n + 1) * (2 * n * n + 3 * n - 1) / 8 : 1ll * n * (n + 2) * (2 * n + 1) / 8);
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