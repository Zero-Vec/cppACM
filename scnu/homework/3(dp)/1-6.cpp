#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e3+9;
ll dp[N][N], a[N][N];
int r;
void solve(){
    cin>>r;
    for (int i = 1; i <= r;i++)
        for (int j = 1; j <= i;j++)
            cin >> a[i][j];
    for (int i = r; i >= 1;i--){
        for (int j = 1; j <= i;j++){
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[1][1];
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