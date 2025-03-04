#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){
    return !b ? a : gcd(b, a % b);
}
void solve(){
    string s;
    ll b;
    cin >> s >> b;
    int len = s.size();
    ll res = 0;
    for (int i = 0; i < len;i++){
        int t = s[i] - '0';
        res *= 10;
        res += t;
        res %= b;
    }
    cout << gcd(res, b);
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