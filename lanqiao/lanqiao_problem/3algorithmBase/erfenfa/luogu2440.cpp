#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
int n, k;
bool check(ll mid){
    ll ans = 0;
    for (int i = 1; i <= n;i++)
        ans += a[i] / mid;
    if(ans>=k)
        return true;
    return false;
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll l = 0, r = 1e8 + 9;
    while(l+1!=r){
        ll mid = (l + r) / 2;
        if(check(mid))l=mid;
        else    r=mid;
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