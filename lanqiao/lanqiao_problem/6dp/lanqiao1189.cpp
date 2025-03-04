#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int a[N], b[N];
int n, m;
int dp[N][N];//dp[i][j]表示A序列[1~i]与B序列[1~j]中最长公共子序列的长度
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(a[i]==b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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