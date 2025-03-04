#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int n, pre[N], b[N], d[N];
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int i,int j){
    int x = root(i), y = root(j);
    if(x!=y)
        pre[x] = y;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> b[i];
        pre[i] = i;
    }
    for (int i = 1; i <= n;i++){
        cin >> d[i];
        if(i-d[i]>=1)
            merge(i, i - d[i]);
        if(i+d[i]<=n)
            merge(i, i + d[i]);
    }
    for (int i = 1; i <= n;i++){
        if(root(i)!=root(b[i])){
            cout << -1;
            return;
        }
    }
    cout << 1;
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