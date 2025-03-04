#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
ll a[N], b[N];
ll n, l, r, c;
bool check(ll x){
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll k = 0;
        if(l > b[i])
            k = (l - b[i] + a[i] - 1) / a[i];
        ll t = b[i] + k * a[i];
        if(x >= t)
            ans += 1ll * (x - t) / a[i] + 1ll;
    }
    return ans >= c;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    cin >> l >> r >> c;
    /*
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        ll k = (l - b[i] + a[i] - 1) / a[i];
        ll t = b[i] + k * a[i];
        ans += 1ll * (r - t) / a[i] + 1ll;
    }
    */
    //cout << (ans >= c ? ans : -1);
    ll lc = l - 1, rc = r + 1;
    while(lc+1!=rc){
        ll mid = (lc + rc) >> 1;
        if(check(mid))
            rc = mid;
        else
            lc = mid;
    }
    cout << (rc == r + 1 || rc == r ? -1 : rc);
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