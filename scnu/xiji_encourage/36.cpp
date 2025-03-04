#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
int a[N], n, ans[N];
void dfs(int dep){
    if(dep == n + 1){
        for (int i = 1; i <= n;i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n;i++){
        if(!a[i]){
            a[i] = 1;
            ans[dep] = i;
            dfs(dep + 1);
            a[i] = 0;
        }
    }
    return;
}
void solve(){
    cin >> n;
    dfs(1);
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