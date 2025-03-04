#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
ll n, w[N], dp[N];
void dfs(int x,int fa){
    dp[x] = w[x];
    for(auto y:g[x]){
        if(y==fa)continue;
        dfs(y, x); // 就是用来算dp[y]的
        dp[x] = max(dp[x], dp[x] + dp[y]); // 得先把dp[y]给算出来
    }
    return;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        dp[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i <= n;i++)
        cin >> w[i];
    for (int i = 1; i <= n - 1;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, -1);
    cout << *max_element(dp + 1, dp + 1 + n) << '\n';
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