#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 移走的石头越多，答案越大，满足二分性
const int N = 5e4 + 9;
int a[N], l, n, m;
int check(int x)
{
    int ans = 0;
    for (int i = 1, last = 0; i <= n; i++)
    {
        if (a[i] - a[last] < x)
        {
            ans++;
            continue;
        }
        last = i;
    }
    if (l - a[n] < x)
        ans++;
    return ans;
}
void solve()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = 1e9 + 1;
    while (l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) <= m)
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
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