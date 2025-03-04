#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){
    return !b ? a : gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return a * b / gcd(a, b);
}
void solve(){
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << " " << lcm(a, b) << '\n';
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