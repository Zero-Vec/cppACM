#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 35;
int w[N];
int n, m;
ll prefix[N];
int ans = 50;
void dfs(int i,ll sum,int cnt){
    if(sum==m){
        ans = min(cnt, ans);
        return;
    }
    if(i>n||cnt>=ans||sum>m||prefix[i]+sum<m)
        return;
    dfs(i + 1, sum + w[i] / 2, cnt + 1);
    dfs(i + 1, sum + w[i], cnt);
    dfs(i + 1, sum, cnt);
}
void solve(){
    cin >> n >> m;
    m *= 2;
    for (int i = 1; i <= n;i++){
        cin >> w[i];
        w[i] *= 2;
    }
    sort(w + 1, w + 1 + n,greater<int>());
    for (int i = n; i >=1;i--){
        prefix[i] = prefix[i + 1] + w[i];
    }
    dfs(1, 0, 0);
    cout << (ans == 50 ? -1 : ans);
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