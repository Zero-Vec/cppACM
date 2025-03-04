#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node
{
    int x, i;
    bool operator<(const node &u) const
    {
        return x > u.x;
    }
};
int a[N], b[N], k, n;
void solve()
{
    // 挑战最后一个怪物或者不挑战最后一个怪物
    cin >> k >> n;
    priority_queue<node> pq;
    int mn = 1e9 + 9;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i] >> b[i];
        if (i != k)
            pq.push({a[i], i});
        mn = min(b[i], mn);
    }
    // 不挑战
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        node t = pq.top();
        pq.pop();
        ans += t.x;
        pq.push({b[t.i], t.i});
    }
    // 挑战
    ll ans1 = 0;
    for (int i = 1; i <= k; i++)
    {
        ans1 += a[i];
    }
    if (n < k)
    {
        cout << ans;
        return;
    }
    ans = min(ans, ans1 + (n - k) * mn);
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