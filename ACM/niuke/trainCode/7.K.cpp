#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], n, k, mx;
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if(k == 1){
        cout << mx << "\n";
        return;
    }
    vector<ll> v;
    for (int i = 1; i <= n;i++){
        while(a[i]){
            v.push_back(a[i]);
            a[i] /= k;
        }
    }
    sort(v.begin(), v.end());
    ll ans = v.size();
    for (int i = 0; i < v.size();i++)
        ans = min(ans, (ll)v.size() - i - 1 + v[i]);
    cout << ans << "\n";
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