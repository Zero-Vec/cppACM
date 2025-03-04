#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int dp[N], u, v, n, m, in[N];
vector<int> g[N];
void topo(){
    queue<int> q;
    for (int i = 1; i <= n;i++){
        if(!in[i])
            q.push(i);
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto j:g[x]){
            dp[j] = max(dp[j], dp[x] + 1);
            in[j]--;
            if(!in[j])
                q.push(j);
        }
    }
    return;
}
void solve(){
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    topo();
    int ans = 0;
    for (int i = 1; i <= n;i++)
        ans = max(ans, dp[i]);
    cout << ans;
}
int main()
{
    //即找最大的点的dp值
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}