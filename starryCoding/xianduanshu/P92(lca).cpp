#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, T = 20;
vector<int> g[N];
int fa[N][30], dep[N], n;
void dfs(int x){
    for (int i = 1; i <= T;i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    dep[x] = dep[fa[x][0]] + 1;
    for(auto y:g[x])
        dfs(y);
}
int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x, y);
    //使得dep[x] >= dep[y]
    for (int i = T; i >= 0;i--)
        if(dep[fa[x][i]]>=dep[y])
            x = fa[x][i];
    if(x == y)
        return x;
    for (int i = T; i >= 0;i--)
        if(fa[x][i]!=fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void solve(){
    cin >> n;
    for (int i = 2; i <= n;i++){
        cin >> fa[i][0];
        g[fa[i][0]].push_back(i);
    }
    dfs(1);
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
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