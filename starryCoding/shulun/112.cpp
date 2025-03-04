#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
ll a[N];
void solve(){
    //正难则反
    int n;
    cin >> n;
    cin >> a[1];
    for (int i = 2; i <= n;i++)
        a[i] = 0;
    ll ans = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 2 * i; j <= n;j+=i)
            a[j] = (a[j] + a[i]) % mod;
    for (int i = 1; i <= n;i++)
        ans = (ans + a[i]) % mod;
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