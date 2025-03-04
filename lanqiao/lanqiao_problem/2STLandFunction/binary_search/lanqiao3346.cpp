#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], b[N], pre[N];
ll n, m, k, s;
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++){
        cin >> b[i];
        pre[i] = pre[i - 1] + b[i];
    }
    ll ans = 0;
    for (int i = 0; i <= n;i++){
        s += a[i];
        if(s>k)
            break;
        ll t = k - s;
        ll l = 0, r = m + 1;
        while(l+1!=r){
            ll mid = (l + r) / 2;
            if(pre[mid]<=t)
                l = mid;
            else
                r = mid;
        }
        ans = max(ans, l + i);
    }
    cout << ans;
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