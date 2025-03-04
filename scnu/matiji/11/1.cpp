#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n,fa[N],so[N],nex[N];
void init(int n){
    for (int i = 1; i <= n;i++){
        fa[i] = i;
        so[i] = i;
    }
}
int find(int x){
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}
void merge(int i,int j){
    int x = find(i), y = find(j);
    if(x!=y){
        nex[so[x]] = y;
        fa[y] = x;
        so[x] = so[y];
    }
}
void solve(){
    cin >> n;
    init(n);
    for (int i = 1; i < n;i++){
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = find(1); i;i=nex[i])
        cout << i << ' ';
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