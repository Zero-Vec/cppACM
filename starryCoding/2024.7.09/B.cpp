#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, k, a[N];
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i + 1] - a[i] <= k)
            ans++;
        else
        {
            res = max(res, ans);
            ans = 1;
        }
    }
    res = max(res, ans);
    cout << n - res << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}