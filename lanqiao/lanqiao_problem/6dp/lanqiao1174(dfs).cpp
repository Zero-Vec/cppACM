#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int v[N], w[N];
int n, V;
int mem[N][N];
int dfs(int x,int spV){
    if(mem[x][spV]!=-1)
        return mem[x][spV];
    if(x>n)
        return mem[x][spV] = 0;
    if(spV<v[x])
        return mem[x][spV] = dfs(x + 1, spV);
    else
        return mem[x][spV] = max(dfs(x + 1, spV), dfs(x + 1, spV - v[x]) + w[x]);
}
void solve(){
    cin >> n >> V;
    for (int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];
    memset(mem, -1, sizeof mem);
    int res = dfs(1, V);
    cout << res;
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