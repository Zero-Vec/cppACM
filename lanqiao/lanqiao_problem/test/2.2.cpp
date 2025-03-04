#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N];
map<int, int> mp;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = 1, num = 0, ans = 0;
    while (l <= r && r <= n)
    {
        if (!mp[a[r]])
        {
            mp[a[r]]++, r++, num++;
            ans = max(ans, num);
        }
        else
        {
            while (a[l] != a[r])
            {
                mp[a[l]]--, l++, num--;
            }
            mp[a[l]]--, l++, num--;
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