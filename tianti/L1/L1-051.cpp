#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b;
    cin >> a >> b;
    double ans = 0.1 * a * b;
    cout << fixed << setprecision(2) << ans;
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