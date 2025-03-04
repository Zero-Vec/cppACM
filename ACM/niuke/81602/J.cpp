#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    double l, x, y;
    cin >> l >> x >> y;
    if (l * l >= x * x + y * y)
    {
        cout << "Yes\n";
        cout << 0 << '\n';
    }
    else if (l * l >= (x - l) * (x - l) + y * y)
    {
        cout << "Yes\n";
        cout << l << '\n';
    }
    else
    {
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