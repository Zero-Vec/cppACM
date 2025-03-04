#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int pre[N];
struct Edge{
    int x, y, e;
    bool operator<(const Edge& u)const{
        return e < u.e;
    }
};
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    int x, y, e;
    vector<Edge> v;
    while(m--){
        cin >> x >> y >> e;
        v.push_back({x, y, e});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(const auto &edge:v){
        if(root(edge.x)==root(edge.y))continue;
        ans = max(ans, edge.e);
        pre[root(edge.x)] = root(edge.y);
    }
    cout << ans << '\n';
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