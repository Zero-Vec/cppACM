#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1100;
int a[N][N], dp[N][N], cnt[N][N];
int n, m;
void solve(){
    cin >> m >> n;
    for (int i = 0; i <= m;i++)
        for (int j = 0; j <= n;j++)
            cin >> a[i][j];
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            for (int k = 0; k <= j;k++){
                if(dp[i][j]<=dp[i-1][j-k]+a[i][k]){
                    dp[i][j] = dp[i - 1][j - k] + a[i][k];
                    cnt[i][j] = k;
                }
            }
    int t = n, s;
    for (int k = m; k >= 1;k--){
        s=cnt[k][t];
        t-=s;
        cout << k << " " << s << '\n';
    }
    cout << dp[m][n];
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