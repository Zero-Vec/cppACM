#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int h;
    cin >> h;
    double w = (h - 100) * 0.9 * 2;
    cout << fixed << setprecision(1) << w;
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