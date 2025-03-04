#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
/*
dfs算法，不撞南墙不回头算法，一条路走到底，相当于树的深度遍历
对于当前状态，我要把我能感染的给感染，然后跳转到下一个被感染的对象，以此类推直到不能感染为止
此时处于回溯状态，然后再在上一个状态下去感染其他状态，周而复始
如果下一个状态已经被感染了，那么跳过即可
*/
int d, n, x[N], y[N];
bool vis[N];
double dis(int i,int j){
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
void dfs(int dep){
    if(vis[dep])
        return;
    vis[dep] = 1;
    //枚举每个顶点
    for (int i = 1; i <= n;i++){
        if(dis(i,dep)<=d){
            dfs(i);
        }
    }
    return;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> y[i];
    }
    cin >> d;
    dfs(1);
    for (int i = 1; i <= n;i++){
        cout << (vis[i] ? 1 : 0) << "\n";
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