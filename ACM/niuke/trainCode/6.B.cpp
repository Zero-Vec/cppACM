#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], b[N], n, c[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        b[i] = c[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int l = 1, r = 1;
    int ida = 0, idb = 0, mn = 2e9 + 9;
    while (l <= n && r <= n)
    {
        if (abs(a[l] - b[r]) < mn)
        {
            ida = l, idb = b[r], mn = min(abs(a[l] - b[r]), mn);
        }
        if (a[l] > b[r])
            r++;
        else
            l++;
    }
    for (int i = 1; i <= n; i++)
        if (c[i] == idb)
        {
            idb = i;
            break;
        }
    swap(a[ida], a[idb]);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
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