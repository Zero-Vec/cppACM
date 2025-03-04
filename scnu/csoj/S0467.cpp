#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, k, m;
int pre[N];
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve(){
    cin >> n >> k >> m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    while (k--){
        int x, y;
        cin >> x >> y;
        pre[root(x)] = root(y);
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        if(root(x)==root(y))
            cout << "YES" << '\n';
        else
            cout << "NO\n";
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