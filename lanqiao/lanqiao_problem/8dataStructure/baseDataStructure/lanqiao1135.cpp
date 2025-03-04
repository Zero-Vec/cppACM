#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int pre[N];//记录每个点的父节点
int n, m;
int root(int x){//找到x的根(父亲的父亲的父亲...)
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    int op, x, y;
    while(m--){
        cin >> op >> x >> y;
        if(op==1){
            pre[root(x)] = root(y);
        }
        else{
            cout << (root(x) == root(y) ? "YES\n" : "NO\n");
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