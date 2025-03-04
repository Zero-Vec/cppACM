// https://codeforces.com/problemset/problem/1808/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v;
    v.resize(m + 1);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            ll x;
            cin >> x;
            v[j].push_back(x);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m;i++){
        vector<ll> &t = v[i];
        sort(t.begin(), t.end());
        for (int j = 1; j < n;j++){
            ans += 1ll * j * (n - j) * (t[j] - t[j - 1]);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}