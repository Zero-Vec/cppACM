#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll> s;
void solve(){
    ll x;
    cin >> x;
    for(auto i:s){
        if(s.count(x-i)){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    for (ll i = 1; i <= 1e4;i++)
        s.insert(i * i * i);
    while (t--)
        solve();
    return 0;
}