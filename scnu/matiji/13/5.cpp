#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
ll dp[N];
int m, n;
void solve(){
    cin >> m >> n;
    int k = m * (n - 1);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= k;i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[k];
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