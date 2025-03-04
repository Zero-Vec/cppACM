#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
ll dp[N][N][N];//表示第i行第j列上移k次的最大值
int a[N][N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            cin >> a[i][j];
    for (int i = n; i >= 1;i--){
        for (int j = 1; j <= i;j++){
            for (int k = 0; k <= n - i;k++){
                if(k>=1)dp[i][j][k] = a[i][j] + max(dp[i + 1][j][k - 1], dp[i + 1][j + 1][k]);
                else
                    dp[i][j][k] = dp[i + 1][j + 1][k] + a[i][j];
            }
        }
    }
    cout << max(dp[1][1][(n - 1) / 2], dp[1][1][n - 1 - (n - 1) / 2]);
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