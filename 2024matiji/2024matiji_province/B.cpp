#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
string s[N], t[N];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        t[i] = s[i];
        sort(t[i].begin(), t[i].end());
    }
    ll ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int len = t[i].size();
        if (t[i][0] == t[i][len - 1])
        {
            if (t[i][0] == '0')
                continue;
            else
            {
                ans += len;
            }
        }
        else
        {
            int num = 0;
            for (int j = 0; j < len; j++)
            {
                if (s[i][j] == '1')
                    num++;
                else
                    break;
            }
            mx = max(mx, num);
            num = 0;
            for (int j = len - 1; j >= 0; j--)
            {
                if (s[i][j] == '1')
                    num++;
                else
                    break;
            }
            mx = max(mx, num);
        }
    }
    cout << ans + mx;
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