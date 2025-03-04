#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=25;
ll ans;
int n, m, k;
vector<vector<int>> c_choice;
vector<vector<int>> g(N, vector<int>(N, 0));
vector<int> color(21, 0);
bool v[N];
//判断v节点c_choice色是否可行
bool check(int v,int choice){
    for (int i = 1; i <= n;i++){
        if(g[v][i] == 1 && color[i] == choice)
            return false;
    }
    return true;
}
void dfs(int x){
    if(x==n+1){
        c_choice.push_back(color);
        ans++;
        return;
    }
    for (int c = 1; c <= k;c++){
        if(check(x,c)){
            color[x] = c;
            dfs(x + 1);
            color[x] = 0;
        }
    }
    return;
}
void solve(){
    cin >> n >> m >> k;
    while(m--){
        int x, y;
        cin>>x>>y;
        g[x][y] = g[y][x] = 1;
    }
    dfs(1);
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