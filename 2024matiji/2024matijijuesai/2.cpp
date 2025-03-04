#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, m;
ll w[N];
vector<int> g[N];
bool vt[N], v[N];
int ru[N];
priority_queue<int,vector<int>,greater<int> > pq;
void dfs(int x){
    for(auto i:g[x]){
        w[i] += w[x];
        dfs(i);
    }
    return;
}
vector<int> ans;
vector<int> id;
void dfs2(int x){
    if(ru[x])
        return;
    if(vt[x]&&g[x].size())
        ans.push_back(x);
    for(auto i:g[x]){
        ru[i]--;
        w[i] += w[x];
        dfs2(i);
    }
    return;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> w[i];
    for (int i = 1; i <= m;i++){
        int u, v;
        cin >> u >> v;
        vt[v] = 1;
        g[u].push_back(v);
        ru[v]++;
    }
    for (int i = 1; i <= n;i++)
        sort(g[i].begin(), g[i].end());
    vector<int> tmp;
    for (int i = 1; i <= n;i++)
        if(!vt[i]){
            if(g[i].size())
                id.push_back(i), ans.push_back(i);
            else
                tmp.push_back(i);
        }
    /*
    pq.push(id);
    vector<int> ans;
    vector<int> tmp;
    while(pq.size()){
        int t = pq.top();
        pq.pop();
        if(v[t])continue;
        v[t] = 1;
        if(g[t].empty()){
            tmp.push_back(t);
            continue;
        }
        ans.push_back(t);
        for(auto j:g[t])
            pq.push(j);
    }
    for(auto i:ans)
        cout << i << " ";
    sort(tmp.begin(), tmp.end());
    for(auto i:tmp)
        cout << i << " ";
    cout << '\n';
    */
    for(auto i:id)
        dfs2(i);
    for (int i = 1; i <= n;i++)
        if(vt[i]&&g[i].empty())
            tmp.push_back(i);
    sort(tmp.begin(), tmp.end());
    cout << ans[0];
    for (int i = 1; i < ans.size();i++)
        cout << " " << ans[i];
    for (int i = 0; i < tmp.size();i++)
        cout << " " << tmp[i];
    cout << '\n';
    //dfs(id);
    /*
    for (int i = 1; i <= n;i++)
        cout << w[i] << '\n';
    */
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if(g[i].empty()){
            if(!cnt){
                cout << w[i];
                cnt++;
            }
            else{
                cout << " " << w[i];
            }
        }
    }
    cout << '\n';
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
7 8
1 2 3 4 5 6 7
1 2 1 3 2 4 3 4 3 5 5 6 6 4 4 7
*/
/*
7 8
1 2 3 4 5 6 7
1 3 1 2 2 4 3 4 3 5 5 6 6 4 4 7
*/
/*
7 8
1 2 3 4 5 6 7
1 3 1 2 2 4 3 4 3 5 5 6 6 4 6 7
*/
/*
8 9
1 2 3 4 5 6 7 8
1 3 1 2 2 4 3 4 3 5 5 6 6 4 6 7 8 3
*/
/*
9 9
1 2 3 4 5 6 7 8 9
1 3 1 2 2 4 3 4 3 5 5 6 6 4 6 9 7 3
*/
/*
7 8
1 2 3 4 5 6 7
1 2 1 3 2 4 3 4 3 5 5 6 6 4 3 7
*/