#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll quick_power(ll base,ll power,ll p){
    ll result = 1;
    while(power){
        if(power & 1)
            result = result * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return result;
}
void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << quick_power(a, b, c) << '\n';
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