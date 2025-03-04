#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int n, mx;
int pre[N];
int fo;
vector<int> v[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            mx = max(mx, x);
            v[i].push_back(x);
        }
    }
    for (int i = 1; i <= mx; i++)
        pre[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v[i].size() - 1; j++)
        {
            pre[root(v[i][j])] = root(v[i][j + 1]);
        }
    }
    set<int> s;
    for (int i = 1; i <= mx; i++)
        s.insert(root(i));
    cout << mx << ' ' << s.size() << '\n';
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (root(x) == root(y))
            cout << 'Y' << '\n';
        else
            cout << 'N' << '\n';
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