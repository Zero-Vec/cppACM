#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b)
{
    return !b ? a : (gcd(b, a % b));
}
void solve()
{
    int n;
    cin >> n;
    ll a = 0, b = 0, suma = 0, sumb = 0;
    char k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> k >> b;
        if (suma == 0)
        {
            suma = a, sumb = b;
        }
        else
        {
            suma = a * sumb + b * suma;
            sumb = sumb * b;
        }
        ll maxn = gcd(suma, sumb);
        suma /= maxn, sumb /= maxn;
    }
    if (suma % sumb == 0)
    {
        cout << suma / sumb;
    }
    else if (suma && suma < sumb)
    {
        cout << suma << '/' << sumb;
    }
    else
    {
        cout << suma / sumb << " " << suma % sumb << '/' << sumb;
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