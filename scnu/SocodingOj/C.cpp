#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 35;
vector<int> g[N];
bool tag;
bool v[N];
int ls[N], rs[N];
int n;
void dfs(int x,int l,int r,int L,int R){
    if(tag==0)
        return;
    v[x] = 1;
    for(auto i:g[x]){
        if(v[i])continue;
        if(i<x&&!ls[x]&&l<=i&&i<=r){
            ls[x] = i;
            dfs(i, l, i - 1, i + 1, x-1);
        }
        else if(i>x&&!rs[x]&&L<=i&&i<=R){
            rs[x] = i;
            dfs(i, x+1, i - 1, i + 1, R);
        }
        else{
            tag = 0;
            return;
        }
    }
    return;
}
void solve(){
    cin >> n;
    for (int i = 1; i < n;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans;
    for (int i = 1; i <= n;i++){
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);
        memset(v, 0, sizeof v);
        tag = 1;
        dfs(i, 1, i - 1, i + 1, n);
        if(tag){
            ans.push_back(i);
        }
    }
    if(!ans.size()){
        cout << "Impossible";
    }
    else{
        cout << ans.size() << '\n';
        for(auto i:ans)
            cout << i << '\n';
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