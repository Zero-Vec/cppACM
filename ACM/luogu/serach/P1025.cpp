#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, ans;
void dfs(int last,int sum,int cnt){
    if(cnt==k){
        if(sum==n)
            ans++;
        return;
    }
    for (int i = last; sum + i * (k - cnt) <= n;i++){
        dfs(i, sum + i, cnt + 1);
    }
    return;
}
void solve(){
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << ans;
}
int main()
{
    //数的划分
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}