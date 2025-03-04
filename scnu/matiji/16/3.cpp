#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct edge{
    int e;
    edge *n;
    edge(int x=0,edge *y=NULL):e(x),n(y){}
} *pre[N];
void insert(int s,int e){
    edge *tmp(new edge(e, pre[s]));
    pre[s] = tmp;
}
int n, m, fin[N], ans[N], ind[N], outd[N];
ll f[N];
priority_queue<int, vector<int>, greater<int>> q;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> f[i];
    for (int i = 1, x, y; i <= m;i++){
        cin >> x >> y;
        insert(x, y);
        ++outd[x], ++ind[y];
    }
    for (int i = 1; i <= n;i++){
        if(!outd[i])
            fin[++fin[0]] = i;
        if(!ind[i])
            q.push(i);
    }
    while(q.size()){
        int u = q.top();
        q.pop();
        ans[++ans[0]] = u;
        for (edge *i = pre[u]; i;i=i->n){
            int e = i->e;
            f[e] += f[u];
            --ind[e];
            if(!ind[e])
                q.push(e);
        }
    }
    for (int i = 1; i <= n;i++)
        cout << ans[i] << " \n"[i == n];
    for (int i = 1; i <= fin[0];i++)
        cout << f[fin[i]] << " \n"[i == n];
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