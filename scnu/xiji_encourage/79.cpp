#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int dp[N];
char a[N];
void solve()
{
    cin >> a + 1;
    int n = strlen(a + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
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