#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll getnum(ll x)
{
    if (x & 1)
        return x / 4 + x / 2 + 1;
    else
        return x / 4 + x / 2;
    // return x / 4 + x / 2 + (x & 1);
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << getnum(r) - getnum(l - 1);
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