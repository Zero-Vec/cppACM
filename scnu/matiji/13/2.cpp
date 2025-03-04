#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n;
ll t[N], adj[N];
int lowbit(int x){
    return x & -x;
}
void update(int k){
    for (int i = k; i <= n; i += lowbit(i))
        t[i]++;
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1;i-=lowbit(i))
        res += t[i];
    return res;
}
void solve()
{
    // 树状数组可以求一个数前面有多少个数比它小
    cin >> n;
    int x, mx = 0;
    for (int i = 1; i <= n;i++){
        cin >> x;
        mx = max(mx, x);
        int cnt = getsum(x - 1);
        if(cnt == i - 1)
            adj[x]--;
        else if(cnt == i - 2)
            adj[mx]++;
        update(x);
    }
    int ans = -1e5 - 1, res = 0;
    for (int i = 1; i <= n;i++)
        if(adj[i] > ans)
            ans = adj[i], res = i;
    cout << res << '\n';
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