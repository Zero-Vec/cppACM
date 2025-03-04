#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, m, x, y;
vector<ll> xl[N], yl[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        cin >> x >> y;
        xl[x].push_back(y);
        yl[y].push_back(x);
    }
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        if (xl[i].size() < 2)continue;
        ans = max(ans, *max_element(xl[i].begin(), xl[i].end()) - *min_element(xl[i].begin(), xl[i].end()));
    }
    for (int i = 1; i <= n; i++){
        if (yl[i].size() < 2)continue;
        ans = max(ans, *max_element(yl[i].begin(), yl[i].end()) - *min_element(yl[i].begin(), yl[i].end()));
    }
    cout << ans << '\n';
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