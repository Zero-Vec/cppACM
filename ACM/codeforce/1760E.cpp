#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];

ll f(ll a[], int n)
{
    ll res = 0, c1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
            c1++;
        else
            res += c1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int c1 = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            c1++;
        else
            ans += c1;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            ans = max(ans, f(a, n));
            a[i] = 0;
            break;
        }
    }

    for (int i = n; i >= 1; --i)
    {
        if (a[i] == 1)
        {
            a[i] = 0;
            ans = max(ans, f(a, n));
            a[i] = 1;
            break;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}