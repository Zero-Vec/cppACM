#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll h[N];
int n, m;
bool vis[N], tag;
vector<int> v[N], ans;
void dfs(int dep){
    if(tag)
        return;
    if(dep == n){
        cout << ans[0];
        for (int i = 1; i < ans.size();i++)
            cout << " " << ans[i];
        tag = 1;
        return;
    }
    for (int i = 1; i <= m;i++){
        if(vis[i])continue;
        bool flag = false;
        for (int j = 0; j < v[i].size();j++)
            if(h[dep+j]!=v[i][j]){
                flag = true;
                break;
            }
        if(flag)continue;
        vis[i] = 1;
        ans.push_back(i);
        dfs(dep + v[i].size() - 1);
        ans.pop_back();
        vis[i] = 0;
    }
    return;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> h[i];
    cin >> m;
    for (int i = 1; i <= m;i++){
        int k, x;
        cin >> k;
        while(k--){
            cin >> x;
            v[i].push_back(x);
        }
    }
    dfs(1);
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