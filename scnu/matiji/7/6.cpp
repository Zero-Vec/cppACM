#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
int n;
ll f[N];
void solve(){
    cin >> n;
    f[1] = 0, f[2] = 1;
    for (int i = 3; i <= n;i++)
        f[i] = f[i - 2] + i * (i - 1) / 2;
    ll ans = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            ans += j;
    cout << ans + f[n] << '\n';
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