#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll s[N], v[N];
ll n, m;
bool check(ll x){
    ll ans = 0, mx = 0;
    for (int i = 1; i <= n;i++){
        if(x <= s[i])
            continue;
        else
            ans += (x - s[i]) * v[i];
        mx = max(mx, (x - s[i]) * v[i]);
    }
    return (ans - mx >= m);
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> s[i] >> v[i];
    ll l = 0, r = 2e12;
    while(l+1!=r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << (r == 2e12? -1 : r) << "\n";
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