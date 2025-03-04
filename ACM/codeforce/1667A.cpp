// https://codeforces.com/problemset/problem/1667/A
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
const ll inf = 2e18;
ll a[N], b[N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll ans = inf;
    for (int i = 1; i <= n;i++){
        memset(b,0,sizeof b);
        ll cnt = 0;
        for (int j = i - 1; j >= 1;j--){
            ll k = 1ll * (-1) * b[j + 1] / a[j] + 1;
            b[j] = k * a[j] * (-1);
            cnt += k;
        }
        for (int j = i + 1; j <= n;j++){
            ll k = b[j - 1] / a[j] + 1;
            b[j] = k * a[j];
            cnt += k;
        }
        ans = min(ans, cnt);
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