#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110, p = 1e6 + 7;
ll dp[N][N], n, m, a[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) // 到第i种花为止
        for (int k = 0; k <= a[i]; k++) // 第i种花放了k盘
            for (int j = k; j <= m; j++)  // 一共放了j盘花
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
    cout << dp[n][m] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}