#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
ll n, k;
bool check(ll mid){
    ll cnt = 0;
    for (int i = 1; i <= n;i++){
        ll t = min(mid, a[i]);
        cnt += t;
    }
    return cnt / k >= mid;
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    ll l = 0, r = 1e18;
    while(l+1!=r){
        ll mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
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