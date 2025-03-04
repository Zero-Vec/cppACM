#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n >= m)
        swap(n, m); // n <= m
    if ((n * m) & 1)
    {
        cout << "No\n";
        return;
    }
    if (a == 0 && b == 0)
    {
        if (n == 1 && m == 2)
        {
            cout << "Yes\n";
            return;
        }
        cout << "No\n";
    }
    else if (a == 1 && b == 1)
    {
        cout << "Yes\n";
    }
    else if (a == 0 && b == 1)
    {
        if (n == 1)
        {
            if (m == 2)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
            cout << "Yes\n";
    }
    else
    {
        if (n == 1)
        {
            if (m & 1)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
        else
            cout << "No\n";
    }
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