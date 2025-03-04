#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, a[N], pre[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    map<int, int> mp;
    mp[0] = 1;
    ll ans = 0;
    // 枚举右端点
    for (int i = 1; i <= n;i++){
        ans += mp[pre[i] - i];
        mp[pre[i] - i]++;
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