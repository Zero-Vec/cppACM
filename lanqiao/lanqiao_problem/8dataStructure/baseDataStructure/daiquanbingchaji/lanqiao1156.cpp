#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, m;
/*
带权并查集：
增加一个距离数组，记录每个集合的元素到祖先的距离，可以维护任意一点到集合根的距离
*/
int pre[N], dis[N],siz[N];//dis存与当前祖先的权值,pre表示父节点编号
int root(int x){
    if(pre[x]==x)
        return x;
    int t = root(pre[x]);
    dis[x] += dis[pre[x]];
    return pre[x] = t;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        pre[i] = i;
        siz[i] = 1;
    }
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op==1){
            int tx = root(x), ty = root(y);
            if(tx!=ty){
                pre[tx] = ty;
                dis[tx] = siz[ty];
                siz[ty] += siz[tx];
            }
        }
        else{
            cout << (root(x) == root(y) ? abs(dis[x] - dis[y]) - 1 : -1) << '\n';
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