#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    vector<int> g;
    int w;
    int id;
    bool operator<(const node &u)const{
        return w < u.w;
    }
}d[N];
int n, m, a[N];
bool v[N];
map<int, int> mp;
void dfs(int id){
    v[id] = 1;
    for(auto i:d[id].g){
        if(v[mp[i]])continue;
        if(d[mp[i]].w>d[id].w){
            d[mp[i]].w = d[id].w;
            a[i] = d[mp[i]].w;
            dfs(mp[i]);
        }
    }
    return;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> d[i].w;
        a[i] = d[i].w;
        d[i].id = i;
    }
    for (int i = 1; i <= m;i++){
        int u, v;
        cin >> u >> v;
        d[u].g.push_back(v);
    }
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n;i++){
        mp[d[i].id] = i;
    }
    for (int i = 1; i <= n;i++){
        if(v[i])continue;
        dfs(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n;i++)
        ans += a[i];
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    /*
    for (int i = 1; i <= n;i++)
        cout << d[i].w << ' ' << d[i].id << '\n';
    */
    /*
    for(auto [i,j]:mp){
        cout << i << ' ' << j << '\n';
    }
    */
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