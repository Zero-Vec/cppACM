#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    double x;
    int n;
    cin >> x >> n;
    int sign = -1;
    double term = 1.0;
    double cos_x = 1.0;
    for (int i = 1; i <= n;i++){
        term *= (x * x) / ((2 * i - 1) * (2 * i));
        cos_x += sign * term;
        sign = -sign;
    }
    cout << fixed << setprecision(8) << cos_x << '\n';
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