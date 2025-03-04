// https://ac.nowcoder.com/acm/contest/73854/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
void solve()
{
    int n;
    cin >> n;
    ll maxn = 0, minn = 1e9 + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    cout << ((maxn == a[n] || minn == a[1]) ? "YES\n" : "NO\n");
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