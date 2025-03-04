#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
struct node
{
    int a, b, sum;
    bool operator<(const node &u) const
    {
        return sum < u.sum;
    }
} d[N];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i].a >> d[i].b;
        if (d[i].a < d[i].b)
            swap(d[i].a, d[i].b);
        d[i].sum = d[i].a + d[i].b;
    }
    sort(d + 1, d + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n / 2; i++)
        ans += d[i].b;
    for (int i = n / 2 + 1; i <= n; i++)
        ans -= d[i].a;
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