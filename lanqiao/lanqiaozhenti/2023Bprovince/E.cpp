#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[10]; // 以尾数i结尾的最长序列
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int fr = s[0] - '0', bk = s[s.size() - 1] - '0';
        dp[bk] = max(dp[bk], dp[fr] + 1);
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = max(ans, dp[i]);
    cout << n - ans;
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