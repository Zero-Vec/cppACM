#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N], n;
void solve()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1)
            sum = a[i];
        else
            sum = sum & a[i];
        // cout << sum << '\n';
    }
    if (sum > 0)
    {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    sum = a[1];
    for (int i = 1; i <= n; i++)
    {
        sum &= a[i];
        if (sum == 0)
            ans++, sum = a[i + 1];
    }
    cout << ans << '\n';
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