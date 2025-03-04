#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
const int N = 1e3 + 9;
int pre[N];
ll ans;
int cnt;
struct Edge{
    int x, y, e;
    bool operator<(const Edge &u)const{
        return e < u.e;
    }
};
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    vector<Edge> v;
    int x, y, e;
    while(m--){
        cin >> x >> y >> e;
        v.push_back({x, y, e});
    }
    sort(v.begin(), v.end());
    for(const auto &edge:v){
        if(root(edge.x)==root(edge.y))continue;
        cnt++;
        ans += edge.e;
        pre[root(edge.x)] = root(edge.y);
    }
    cout << (cnt == n - 1 ? ans : -1);
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