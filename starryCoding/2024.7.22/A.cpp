#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, m, a;
    cin >> n >> m >> a;
    ll t1 = (n + a - 1) / a, t2 = (m + a - 1) / a;
    cout << t1 * t2 << '\n';
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