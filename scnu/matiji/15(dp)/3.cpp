#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
const int N = 110, INF = 2e18;
ll dp[N][N][2], n;
// dp[i][j][k] 表示前 i 个命令 交换 j 次 方向为 k 的最大答案
void solve(){
    string s;
    cin >> s >> n;
    int siz = s.size();
    s = ' ' + s;
    for (int i = 0; i <= siz;i++)
        for (int j = 0; j <= n;j++)
            dp[i][j][0] = dp[i][j][1] = -INF;
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= siz;i++){
        for (int j = 0; j <= n;j++){
            for (int k = 0; k <= j;k++){
                if(s[i] == 'F')
                    if(k % 2 == 1){
                        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0]);
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][0]);
                    }
                    else{
                        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0] + 1);
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][1] - 1);
                    }
                else if(k & 1){
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0] + 1);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][1] - 1);
                }
                else{
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][1]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][0]);
                }
            }
        }
    }
    cout << max(dp[siz][n][0], dp[siz][n][1]) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// dp[i][j][k] 表示前 i 个命令 交换 j 次 方向为 k 的最大答案
const int N = 110;
char s[N];
ll dp[N][N][2], n;
void solve(){
    cin >> s + 1;
    int n = strlen(s + 1);
    int m;
    cin >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            for (int k = 0; k <= 1;k++){
                for (int l = 0; l <= j; l++){
                    if (j - l >= 0){
                        if (s[i] == 'T'){
                            if (l & 1){
                                if(k == 0){
                                    dp[i][j][0] = dp[i - 1][j - l][0] + 1;
                                }
                                else{
                                    dp[i][j][1] = dp[i - 1][j - l][1] - 1;
                                }
                            }
                            else{
                                if (k == 0)
                                {
                                    dp[i][j][0] = dp[i - 1][j - l][1];
                                }
                                else
                                {
                                    dp[i][j][1] = dp[i - 1][j - l][0];
                                }
                            }
                        }
                        else{
                            if (l % 2)
                            {
                                if (k == 0)
                                {
                                    dp[i][j][0] = dp[i - 1][j - l][1];
                                }
                                else
                                {
                                    dp[i][j][1] = dp[i - 1][j - l][0];
                                }
                            }
                            else{
                                if (k == 0)
                                {
                                    dp[i][j][0] = dp[i - 1][j - l][0] + 1;
                                }
                                else
                                {
                                    dp[i][j][1] = dp[i - 1][j - l][1] - 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << max(dp[n][m][0], -dp[n][m][1]) << '\n';
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
*/