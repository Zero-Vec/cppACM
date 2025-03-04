#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
const int p = 1e6 + 7;
ll dp[N][N];//表示前i种花摆放1~j的总方案数
int a[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 0; i <= n;i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 0; k <= j && k <= a[i];k++){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
            }
        }
    }
    cout << dp[n][m];
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