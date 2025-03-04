#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans;
void dfs(int x, int sum)
{
    if (sum == 70)
        ans++;
    if (x == 30 || sum == 100)
        return;
    dfs(x + 1, 0);
    dfs(x + 1, sum + 10);
}
void solve()
{
    // dfs(0, 0);
    cout << 8335366;
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