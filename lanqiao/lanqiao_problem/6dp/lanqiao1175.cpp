#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int dp[N][N];
int n, V;
void solve(){
    cin >> n >> V;
    for (int i = 1; i <= n;i++){
        int v, w;
        cin >> v >> w;
        for (int j = 0; j <= V;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=v)
                dp[i][j] = max(dp[i][j], dp[i][j - v] + w);
        }
    }
    cout << dp[n][V];
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