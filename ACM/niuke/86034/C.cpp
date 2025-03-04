#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x, y, t, a, b, c;
    cin >> x >> y >> t >> a >> b >> c;
    double ans = 0;
    if(x>t){
        double k1 = 1.0 * (100 - x) / b;
        double k2 = 1.0 * (x - t) / y + 1.0 * (100 - t) / c;
        ans = min(k1, k2);
    }
    else{
        //ans += 1.0* (t - x) / c;
        ans += 1.0 * (100 - x) / c;
    }
    cout << fixed << setprecision(9) << ans;
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