#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int N = 5000 + 10;
int T, n, p[N], q[N], s[N];
int dp[N][N], rt[N][N], m[N][N];
void dfs(int l, int r)
{
    if (l > r)
        return;
    cout << rt[l][r] << endl;
    dfs(l, rt[l][r] - 1);
    dfs(rt[l][r] + 1, r);
}
void solve(void)
{
    memset(dp, 0x3f3f3f3f, sizeof dp);
    memset(rt, 0x3f3f3f3f, sizeof rt);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i <= n; i++)
    {
        cin >> q[i];
    }
    s[0] = q[0];
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = p[i] + q[i] + q[i - 1];
        rt[i][i] = i;
        s[i] = s[i - 1] + p[i] + q[i];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int r = rt[i + 1][j]; r >= rt[i][j - 1]; r--)
            {
                if (r == i)
                {
                    if (dp[i][j] >= dp[r + 1][j] + s[j] - s[i - 1] + q[i - 1])
                    {
                        dp[i][j] = dp[r + 1][j] + s[j] - s[i - 1] + q[i - 1];
                        rt[i][j] = r;
                    }
                }
                else if (r == j)
                {
                    if (dp[i][j] >= dp[i][r - 1] + s[j] + s[i - 1] + q[i - 1])
                    {
                        dp[i][j] = dp[i][r - 1] + s[j] - s[i - 1] + q[i - 1];
                        rt[i][j] = r;
                    }
                }
                else
                {
                    if (dp[i][j] >= dp[i][r - 1] + dp[r + 1][j] + s[j] - s[i - 1] + q[i - 1])
                    {
                        dp[i][j] = dp[i][r - 1] + dp[r + 1][j] + s[j] - s[i - 1] + q[i - 1];
                        rt[i][j] = r;
                    }
                }
            }
        }
    }
    dfs(1, n);
}

signed main(void)
{
    IOS;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}