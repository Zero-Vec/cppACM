#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll> s;
void solve(){
    for (ll i = 1; i <= 1e3; i++)
    {
        for (ll j = i; j <= 1e3; j++)
        {
            ll k = i * i * i + j * j * j;
            s.insert(k);
        }
    }
    for(auto i:s){
        cout << i << '\n';
    }
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