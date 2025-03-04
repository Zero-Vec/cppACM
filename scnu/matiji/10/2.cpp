#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll cnt1, cnt2, x, y;
bool check(ll v){
    ll k = x * y;
    if(v<v/x+cnt1)
        return false;
    if(v<v/y+cnt2)
        return false;
    if(v<v/k+cnt1+cnt2)
        return false;
    return true;
}
void solve(){
    cin >> cnt1 >> cnt2 >> x >> y;
    ll l = 0, r = 2e14;
    while(l+1!=r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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