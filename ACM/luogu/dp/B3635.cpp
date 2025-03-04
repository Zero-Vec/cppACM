#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll dp[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        dp[i] = dp[i - 1] + 1;
        if(i>=5)
            dp[i] = min(dp[i], dp[i - 5] + 1);
        if(i>=11)
            dp[i] = min(dp[i], dp[i - 11] + 1);
    }
    cout << dp[n] << '\n';
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