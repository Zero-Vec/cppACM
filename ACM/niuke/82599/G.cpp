#include<bits/stdc++.h>
using namespace std;
using ll = long long;
double dis(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(10) << min(dis(-a, b, c, d), dis(a, -b, c, d)) << '\n';
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