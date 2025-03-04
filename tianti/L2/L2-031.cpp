#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n;
vector<int> g[N];
bool v[N], st[N];
int ans;
int id;
int dep = 1;
void dfs(int x){
    if(g[x].size()==0){
        if(dep>ans){
            ans = dep;
            id = x;
        }
        return;
    }
    for(auto i:g[x]){
        if(v[i])continue;
        v[i] = 1;
        dep++;
        dfs(i);
        dep--;
        v[i] = 0;
    }
    return;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            st[x] = 1;
            g[i].push_back(x);
        }
    }
    int root;
    for (int i = 1; i <= n;i++)
        if(!st[i])
            root = i;
    v[root] = 1;
    dfs(root);
    cout << id;
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