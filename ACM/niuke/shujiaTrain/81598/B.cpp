#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){
    return !b ? a : gcd(b, a % b);
}
void solve(){
    ll n, d;
    cin >> n >> d;
    ll g;
    for (int i = 1; i <= n;i++){
        ll x;
        cin >> x;
        if(i == 1)
            g = x;
        else
            g = gcd(g, x);
    }
    cout << min(d % g, g - d % g) << '\n';
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