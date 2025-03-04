#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll n, dp[N];
void solve(){
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n;i++){
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);
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