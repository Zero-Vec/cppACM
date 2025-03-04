#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, k;
ll check(ll x){
    ll res = 0;
    for (int i = 1; i <= n;i++)
        res += min(m, x / i);
    return res;
}
void solve(){
    cin >> n >> m >> k;
    ll l = 0, r = 1e14;
    while(l + 1 != r){
        ll mid = (l + r) >> 1;
        if(check(mid) >= k)
            r = mid;
        else
            l = mid;
    }
    cout << r;
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