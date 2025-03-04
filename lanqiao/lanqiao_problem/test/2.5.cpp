#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5, inf = 2e18;
struct Node{
    ll x, w;
    bool operator<(const Node &u)const{
        return w == u.w ? x < u.x : w > u.w;
    }
};
vector<Node> g[N];
ll d[N];
int n, m;
void dijkstra(int st){
    for (int i = 1; i <= n;i++)
        d[i] = inf;
    bitset<N> vis;
    priority_queue<Node> pq;
    pq.push({st, d[st] = 0});
    while(pq.size()){
        auto [x, w] = pq.top();
        pq.pop();
        if(vis[x])continue;
        vis[x] = true;
        for(const auto &[y,dw]:g[x]){
            if(d[x]+d[w]<d[y]){
                d[y] = d[x] + dw;
                pq.push({y, d[y]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m;
        
    }
    return 0;
}