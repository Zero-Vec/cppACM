#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
struct node{
    int x, y, e;
    bool operator<(const node &u)const{
        return e > u.e;
    }
};
struct edge{
    int x, e;
};
vector<node> vp;
vector<edge> g[N];
int n, m, q, ans, ans1;
int x, y;
int pre[N];
bool v[N];
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void dfs(int i){
    if(i==y){
        ans1 = ans;
        return;
    }
    for(auto j:g[i]){
        if(v[j.x])continue;
        int t = ans;
        v[j.x] = 1;
        ans = min(ans, j.e);
        dfs(j.x);
        ans = t;
        v[j.x] = 0;
    }
    return;
}
void solve(){
    cin >> n >> m >> q;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        vp.push_back({u, v, w});
    }
    sort(vp.begin(), vp.end());
    for(auto i:vp){
        if(root(i.x)==root(i.y))continue;
        g[i.x].push_back({i.y, i.e});
        g[i.y].push_back({i.x, i.e});
        pre[root(i.x)] = root(i.y);
    }
    while(q--){
        cin >> x >> y;
        if(root(x)!=root(y))
            cout << -1 << '\n';
        else{
            ans = 1e7;
            v[x] = 1;
            dfs(x);
            v[x] = 0;
            cout << ans1 << '\n';
        }
    }
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