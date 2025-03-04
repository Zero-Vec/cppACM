#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e3+9;
string a, b;
ll dp[N][N];
void solve(){
    cin>>a>>b;
    int siz1 = a.size(), siz2 = b.size();
    for (int i = 0; i <= siz1;i++)dp[i][0]=i;
    for (int j = 0; j <= siz2;j++)
        dp[0][j] = j;
    for (int i = 1; i <= siz1;i++){
        for (int j = 1; j <= siz2;j++){
            dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }
    cout << dp[siz1][siz2];
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