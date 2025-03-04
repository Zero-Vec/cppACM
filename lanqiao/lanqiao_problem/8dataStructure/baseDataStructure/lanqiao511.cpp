#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int q[N], hh = 1, tt = 0;
int n, m;
int x;
int ans;
void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        bool tag = 0;
        for (int j = hh; j <= tt; j++)
        {
            if (q[j] == x)
            {
                tag = 1;
                break;
            }
        }
        if (tag)
            continue;
        if (tt - hh + 1 == m)
        {
            hh++;
            q[++tt] = x;
        }
        else
            q[++tt] = x;
        ans++;
    }
    cout << ans;
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