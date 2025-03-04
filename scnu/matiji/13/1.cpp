#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n, k;
int pre[N];
struct node{
    int x, y;
    ll c;
    bool operator<(const node &u)const{
        return c < u.c;
    }
};
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
vector<node> g;
void solve(){
    cin >> n >> k;
    while(k--){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        g.push_back({u, v, c});
    }
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    sort(g.begin(), g.end());
    ll ans = 0;
    for(auto [x,y,c]:g){
        if(root(x)==root(y))continue;
        ans += c;
        pre[root(x)] = root(y);
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