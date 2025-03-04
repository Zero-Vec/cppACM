#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e3 + 9, p = 2333;
int dp[N][N], mp[N][N], m, n;
void solve(){
    cin >> m >> n;
    for (int i = m; i >= 1;i--)
        for (int j = 1; j <= n;j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n;i++)
        if(mp[1][i] == 1)
            break;
        else
            dp[1][i] = 1;
    for (int i = 1; i <= m; i++)
        if (mp[i][1] == 1)
            break;
        else
            dp[i][1] = 1;
    for (int i = 2; i <= m;i++)
        for (int j = 2; j <= n;j++){
            if(mp[i][j] == 1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % p;
            }
        }
    cout << dp[m][n] << '\n';
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