#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int cnt[10][N];
int prefix[10][N];
void dfs(int dep,int st,int mul,int sum,int n){
    if(mul>1e5)
        return;
    if(dep==n+1){
        cnt[n][mul]++;
        return;
    }
    int maxn = pow(1e5 / mul, 1.0 / (n + 1 - dep)) + 5;
    for (int i = st + 1; i < (dep == n ? sum : maxn); i++){
        dfs(dep + 1, i, mul * i, sum + i, n);
    }
    return;
}
void solve(){
    int t, n;
    cin >> t >> n;
    for (int i = 3; i < 10;i++){
        dfs(1, 0, 1, 0, i);
        for (int j = 1; j <= 1e5;j++){
            prefix[i][j] = prefix[i][j - 1] + cnt[i][j];
        }
    }
    while (t--){
        int l, r;
        cin >> l >> r;
        cout << prefix[n][r] - prefix[n][l - 1] << "\n";
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