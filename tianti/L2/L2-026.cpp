#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int n;
int d[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        if(x==-1)
            g[100001].push_back(i);
        else
            g[x].push_back(i);
    }
    queue<int> q;
    q.push(100001);
    while(q.size()){
        int k = q.front();
        q.pop();
        for (int i = 0; i < g[k].size();i++){
            d[g[k][i]] = d[k] + 1;
            q.push(g[k][i]);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n;i++)
        mx = max(mx, d[i]);
    cout << mx << '\n';
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if(d[i]==mx){
            if(!cnt){
                cout << i;
                cnt++;
            }
            else
                cout << ' ' << i;
        }
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
bool v[N];
vector<int> g[N];
int n;
int dep;
vector<int> ans;
void maxdep(int x,int cnt){
    if(g[x].size()==1){
        dep = max(dep, cnt);
        return;
    }
    for(auto i:g[x]){
        if(v[i])continue;
        v[i] = 1;
        maxdep(i, cnt + 1);
    }
    return;
}
void dfs(int x,int cnt){
    if(g[x].size()==1){
        if(cnt==dep)
            ans.push_back(x);
        return;
    }
    for(auto i:g[x]){
        if(v[i])continue;
        v[i] = 1;
        dfs(i, cnt + 1);
    }
    return;
}
void solve(){
    cin >> n;
    int fa;
    for (int i = 1; i <= n;++i){
        int x;
        cin >> x;
        if(x!=-1){
            g[x].push_back(i);
            g[i].push_back(x);
        }
        if(x==-1)
            fa = i;
    }
    v[fa] = 1;
    maxdep(fa, 1);
    cout << dep << '\n';
    memset(v, 0, sizeof v);
    v[fa] = 1;
    dfs(fa, 1);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size();i++){
        if(!i)
            cout << ans[i];
        else
            cout << ' ' << ans[i];
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
*/