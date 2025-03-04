#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N], n, pre[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int i, int j)
{
    int x = root(i), y = root(j);
    if (x != y)
        pre[x] = y;
    return;
}
void solve()
{
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