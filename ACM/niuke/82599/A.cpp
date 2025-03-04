#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int pre[N], n, dep[N], ans[N], op[N];
// ans[i]为每个根节点的当前深度 dep[i]为每个点到当前根节点的距离
int root(int x){
    if(pre[x]==x)
        return x;
    int tmp = pre[x];
    pre[x] = root(pre[x]);
    dep[x] += dep[tmp];
    return pre[x];
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        pre[i] = i, ans[i] = 0, dep[i] = 0;
    for (int i = 1; i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pre[b] = root(a);
        dep[b] = dep[a] + 1;
        ans[root(a)] = max(ans[root(a)], ans[b] + 1 + dep[a]);
        op[i] = ans[c];
    }
    for (int i = 1; i < n;i++)
        cout << op[i] << " \n"[i == n - 1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}