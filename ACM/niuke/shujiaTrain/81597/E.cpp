#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll x;
set<ll> s;
void solve(){
    cin >> x;
    if(x==1){
        cout << -1 << '\n';
        return;
    }
    if(x&1){
        cout << x - 1 << '\n';
        return;
    }
    for(auto i:s){
        if(x-i<=0)
            break;
        ll t = x - i;
        if((x^t)==i){
            cout << t << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    ll a = 1;
    for (int i = 1; i <= 54;i++){
        a *= 2;
        s.insert(a);
    }
    cin >> t;
    while(t--)
        solve();
    return 0;
}