#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, m;
ll w[N];
vector<int> g[N];
bool vt[N], v[N];
int ru[N], ru1[N];
priority_queue<int> pq;
vector<int> ans;
vector<int> id;
void dfs2(int x)
{
    if (ru1[x])
        return;
    if (vt[x] && g[x].size())
        ans.push_back(x);
    for (auto i : g[x])
    {
        ru1[i]--;
        w[i] += w[x];
        dfs2(i);
    }
    return;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        vt[v] = 1;
        g[u].push_back(v);
        ru[v]++;
        ru1[v]++;
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    for (int i = 1; i <= n; i++)
        if (!vt[i])
        {
            if (g[i].size()){
                pq.push(i), id.push_back(i);
                //cout << i << '\n';
            }
        }
    vector<int> tmp;
    while(pq.size()){
        int t = pq.top();
        pq.pop();
        ans.push_back(t);
        for(auto j:g[t]){
            ru[j]--;
            if(!ru[j]){
                pq.push(j);
            }
        }
    }
    
    for(auto i:ans)
        cout << i << " ";
    for(auto i:tmp)
        cout << i << " ";
    cout << '\n';

    for (auto i : id)
        dfs2(i);
    // dfs(id);
    /*
    for (int i = 1; i <= n;i++)
        cout << w[i] << '\n';
    */
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].empty())
        {
            if (!cnt)
            {
                cout << w[i];
                cnt++;
            }
            else
            {
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
    // cin >> t;
    while (t--)
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
/*
8 9
1 2 3 4 5 6 7 8
1 8 1 3 8 4 3 4 3 5 5 6 6 4 7 3 3 2
*/
/*
12 11
1 2 3 4 5 6 7 8 9 10 11 12
1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 1 10 11 2 1 12
*/