//http://csoj.scnu.edu.cn/contest/109/problem/1002
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll dp[N], a[N][5];
void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= 4;j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = k; j >= 0;j--){
            if(dp[j] != -1){
                for (int z = 1; z <= 4;z++){
                    if(dp[j + z] == -1){
                        dp[j + z] = dp[j] + a[i][z];
                    }
                    else{
                        dp[j + z] = min(dp[j + z], dp[j] + a[i][z]);
                    }
                }
            }
        }
    }
    cout << dp[k] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}