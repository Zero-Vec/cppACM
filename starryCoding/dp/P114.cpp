#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 310, inf = 2e18;
ll a[N], dp[N][N], n, pre[N];
void solve()
{
    // 区间dp
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            dp[i][j] = inf;
    // 枚举区间长度
    for (int i = 1; i <= n;i++)
        dp[i][i] = 0;
    for (int len = 2; len <= n;len++){
        // 枚举起点i
        for (int i = 1, j = i + len - 1; j <= n;i++,j++){
            for (int k = i; k < j;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1]);
        }
    }
    cout << dp[1][n] << '\n';
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