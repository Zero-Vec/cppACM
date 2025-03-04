#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int pre[N];
int n, m, k;
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
struct Edge{
    int x,y,e;
    bool operator<(const Edge& u)const{
        return e < u.e;
    }
};
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    int x, y, e;
    vector<Edge> v;
    while(m--){
        cin >> x >> y >> e;
        v.push_back({x, y, e});
    }
    sort(v.begin(), v.end());
    vector<Edge> v2;
    while(k--){
        cin >> x >> y;
        v2.push_back({x, y});
    }
    int ans = 0;
    for(const auto &edge:v){
        if(root(edge.x)==root(edge.y))continue;
        bool tag = 1;
        for(const auto &ee:v2){
            if(edge.x==ee.x&&edge.y==ee.y){
                tag = 0;
                break;
            }
        }
        if(!tag)continue;
        ans += edge.e;
        pre[root(edge.x)] = root(edge.y);
    }
    cout << ans<<'\n'<<n-1;
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