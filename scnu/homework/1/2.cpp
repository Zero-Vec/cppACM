#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 998244353;
const int N = 1e7 + 9;
int dp[N];
void solve()
{
    int n;
    cin >> n;
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n;i++){
        dp[i] = ((dp[i - 1] + dp[i - 2]) % P + P) % P;
    }
    cout << dp[n];
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