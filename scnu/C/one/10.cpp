#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    double r;
    cin >> r;
    double pi = 3.14;
    cout << fixed << setprecision(2) << 4.0 / 3 * pi * r * r * r;
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