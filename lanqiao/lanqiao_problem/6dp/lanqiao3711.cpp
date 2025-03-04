#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 998244353;
const int N = 1e5 + 9;
ll dp[N][64];//dp[i][j]表示到第i个元素位置，异或结果为j的个数
int a[N];
void solve(){
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < 64;j++){
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j ^ a[i]]) % p;
        }
    }
    cout << dp[n][x];
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