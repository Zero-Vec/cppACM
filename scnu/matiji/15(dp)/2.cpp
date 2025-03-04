#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// dp[i][j] 表示抽 i 次以后总额为 j 的方案数
const int N = 1e3 + 9;
ll dp[N][N], n;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
void solve(){
    cin >> n;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    for (int i = 2; i <= n;i++)
        for (int j = 1; j <= 4 * n;j++)
            for (int k = 1; k <= 4;k++)
                if(j-k > 0)
                    dp[i][j] += dp[i - 1][j - k];
    ll sum1 = 0, sum2 = 0;
    for (int i = n; i < 2 * n;i++)
        sum1 += dp[n][i];
    for (int i = 3 * n + 1; i <= 4 * n;i++)
        sum2 += dp[n][i];
    ll fenmu = 1;
    for (int i = 1; i <= n;i++)
        fenmu *= 4ll;
    ll g = gcd(sum1, fenmu);
    cout << sum1 / g << '/' << fenmu / g << '\n';
    g = gcd(sum2, fenmu);
    cout << sum2 / g << '/' << fenmu / g << '\n';
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