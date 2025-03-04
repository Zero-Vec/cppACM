#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 50;
int n, m;
vector<int> g[N];
int v[N];
int ans = 0;
void dfs(int x,int dep){
    ans = max(ans, dep);
    for(auto i:g[x]){
        if(v[i])continue;
        for(auto j:g[x])
            v[j]++;
        dfs(i, dep + 1);
        for(auto j:g[x])
            v[j]--;
    }
    return;
}
void solve(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        if(u == v)continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n;i++){
        v[i] = 1;
        dfs(i, 1);
        v[i] = 0;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}