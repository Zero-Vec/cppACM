#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a, b, c, d;
int ans = 2e9 + 10;
void solve(){
    cin >> a >> b >> c >> d;
    ans = min({a + b, a + d, b + c, c + d});
    cout << ans;
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