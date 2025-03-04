#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 0; i <= 20; i++)
    {
        int sum = 0, ji = 0, ou = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += ((a[j] >> i) & 1);
            if (sum & 1)
            {
                ans += (1ll << i) * (ou + 1);
                ji++;
            }
            else
            {
                ans += (1ll << i) * ji;
                ou++;
            }
        }
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