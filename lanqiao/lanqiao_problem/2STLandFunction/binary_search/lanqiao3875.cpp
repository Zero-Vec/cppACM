#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, m;
void solve()
{
    int cnt = 0;
    while (cin >> n >> m)
    {
        cnt++;
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
        while (m--)
        {
            int op, x, y;
            cin >> op >> x >> y;
            if (op == 1)
            {
                int t = x;
                v.erase(find(v.begin(), v.end(), x));
                auto it = find(v.begin(), v.end(), y);
                v.insert(it, t);
            }
            else if (op == 2)
            {
                int t = x;
                v.erase(find(v.begin(), v.end(), x));
                auto it = find(v.begin(), v.end(), y);
                v.insert(it + 1, t);
            }
            else if (op == 3)
            {
                int posx = find(v.begin(), v.end(), x) - v.begin();
                int posy = find(v.begin(), v.end(), y) - v.begin();
                swap(v[posx], v[posy]);
            }
            else
            {
                reverse(v.begin(), v.end());
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                ans += v[i];
        cout << "Case " << cnt << ": " << ans << '\n';
    }
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