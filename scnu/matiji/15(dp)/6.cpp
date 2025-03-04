#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// 三柱汉诺塔 dp1[i] 表示 移动i个圆盘所需的次数 则 dp1[i] = 2dp1[i-1]+1  dp1[1] =  1 则dp1[n] = 2^n - 1
// 四柱汉诺塔 dp[n] = dp[n-k]+dp1[k]+dp[n-k] = 2dp[n-k]+dp1[k] = 2dp[n-k]+2^k-1
const int N = 60;
ll dp[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i < N;i++)
        dp[i] = 1e9;
    dp[0] = 0, dp[1] = 1, dp[2] = 3;
    if(n >= 1)
        cout << dp[1] << '\n';
    if(n >= 2)
        cout << dp[2] << '\n';
    for (int i = 3; i <= n;i++){
        for (int j = 1; j < i;j++)
            // dp[i] = min(dp[i], 1ll * (2 * dp[i - j] + pow(2, j) - 1));
            if(dp[i] > 2*dp[i-j]+pow(2,j)-1)
                dp[i] = 2 * dp[i - j] + pow(2, j) - 1;
        cout << dp[i] << '\n';
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