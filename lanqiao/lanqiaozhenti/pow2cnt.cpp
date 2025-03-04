#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
map<int, int> mp;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            int t = pow(2, j) - a[i];
            if (mp.count(t))
            {
                if (t != a[i])
                {
                    ans += mp[t];
                }
                else
                    ans += mp[t] - 1;
            }
        }
    }
    ans /= 2;
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