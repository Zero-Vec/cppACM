#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 114584;
const int N = 1e5 + 9;
ll dp[N];
int n, k;
void solve(){
    cin >> n >> k;
    if(k == 1){
        cout << 1;
        return;
    }
    for (int i = 1; i <= k;i++)
        dp[i] = 1;
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n;i++){
        for (int j = 1; j <= k;j++){
            if(i > j)
                dp[i] = (dp[i] + dp[i - j]) % p;
        }
    }
    cout << dp[n];
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