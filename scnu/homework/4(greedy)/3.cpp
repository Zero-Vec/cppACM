//最小生成树
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e3 + 9, inf = 2e9;
struct node{
    int x, y, e;
    bool operator<(const node &u)const{
        return e < u.e;
    }
};
int pre[N];
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        pre[i] = i;
    }
    vector<node> v;
    for (int i = 1; i <= m; i++){
        int x, y, e;
        cin >> x >> y >> e;
        v.push_back({x, y, e});
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 0;
    for(auto edge:v){
        if(root(edge.x)==root(edge.y))continue;
        cnt++;
        ans += edge.e;
        pre[root(edge.x)] = root(edge.y);
    }
    if(cnt==n-1)
        cout << ans;
    else
        cout << "Impossible";
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