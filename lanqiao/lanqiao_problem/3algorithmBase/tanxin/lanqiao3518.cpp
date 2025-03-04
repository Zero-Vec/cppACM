#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], b[N], c[N], tmp[N];
int n;
int ans;
void work(ll x[], ll y[], ll z[])
{
    for (int i = 1; i <= n; i++)
        tmp[i] = x[i] - y[i] - z[i];
    sort(tmp + 1, tmp + 1 + n);
    if (tmp[n] <= 0)
        return;
    int cnt = 1;
    ll sum = tmp[n];
    for (int i = n - 1; i >= 1; i--)
    {
        sum += tmp[i];
        if (sum <= 0)
        {
            break;
        }
        else
        {
            cnt++;
        }
    }
    ans = max(ans, cnt);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    work(a, b, c);
    work(b, a, c);
    work(c, a, b);
    cout << (ans ? ans : -1);
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