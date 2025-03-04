#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int N = 1e6 + 9;
ll dp[N];
ll prefix[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i - k - 1 < 1)
            dp[i] = 1;
        else
            dp[i] = prefix[i - k - 1] + 1;
        prefix[i] = (prefix[i - 1] + dp[i]) % P;
    }
    cout << prefix[n] + 1 << "\n";
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