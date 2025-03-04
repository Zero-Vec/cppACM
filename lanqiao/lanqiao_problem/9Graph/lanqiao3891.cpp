#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
const int N = 1e5 + 9;
vector<int> g[N];
int siz[N];
void dfs(int x){
    siz[x] = 0;
    for (auto i : g[x]){
        dfs(i);
        siz[x] += siz[i] + 1;
    }
}
struct node{
    int id, siz;
    bool operator<(const node &u) const{
        return siz == u.siz ? id < u.id : siz > u.siz;
    }
};
void solve()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
    }
    dfs(1);
    vector<node> v;
    for (int i = 0; i < n; i++)
        v.push_back({i + 1, siz[i + 1]});
    sort(v.begin(), v.end());
    for (int i = 0; i < n;i++){
        if(v[i].id==m){
            cout<<i+1;
            return;
        }
    }
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