#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e4 + 9;
const ll inf = 2e18;
ll dis[3][N];
int te, fe, s, t, f, n, m;
struct node{
    int y;
    ll ey;
    bool operator<(const node &u)const{
        return ey > u.ey;
    }
};
vector<node> g[N];
bool v[N];
void dij(int st,int c){
    dis[c][st] = 0;
    priority_queue<node> pq;
    pq.push({st, dis[c][st]});
    memset(v, 0, sizeof v);
    while(pq.size()){
        auto [x, e] = pq.top();
        pq.pop();
        if(v[x])continue;
        v[x] = 1;
        for(auto [y,ey]:g[x]){
            if(dis[c][x]+ey<dis[c][y]){
                dis[c][y] = dis[c][x] + ey;
                pq.push({y, dis[c][y]});
            }
        }
    }
}
void solve(){
    cin >> te >> fe >> s >> t >> f >> n >> m;
    for (int i = 0; i <= 2;i++)
        for (int j = 0; j < N;j++)
            dis[i][j] = inf;
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 1});
        g[y].push_back({x, 1});
    }
    dij(t, 0), dij(f, 1), dij(n, 2);
    ll ans = inf;
    for (int i = 1; i <= 4e4; i++){
        if (dis[0][i] == inf || dis[1][i] == inf || dis[2][i] == inf)continue;
        ans = min(ans, dis[0][i] * te + dis[1][i] * fe + dis[2][i] * (te + fe - s));
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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