#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, x;
    cin >> n >> x;
    //cout << (sqrt(x) * sqrt(x) == x ? "ON" : "OFF");
    ll gs = 0;
    set<ll> s;
    for (int i = 1; i <= sqrt(x);i++){
        if(x%i==0){
            s.insert(i);
            s.insert(x / i);
        }
    }
    for(auto i:s){
        if(i<=n)
            gs++;
    }
    cout << (gs & 1 ? "ON" : "OFF");
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