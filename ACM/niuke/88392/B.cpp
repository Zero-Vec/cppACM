#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll sum = 0;
    for (int i = 1; i <= n;i++){
        ll x;
        cin >> x;
        sum += x;
    }
    ll gs = sum / k;
    cout << min(m + 1, gs) << '\n';
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