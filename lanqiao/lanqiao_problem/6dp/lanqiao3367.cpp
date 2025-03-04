#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int N = 1e5 + 9;
int n, m;
ll dp[N];
bool broken[N];
void solve(){
    cin >> n >> m;
    while(m--){
        int x;
        cin >> x;
        broken[x] = true;
    }
    dp[0] = 1;
    if(broken[1])
        dp[1] = 0;
    else
        dp[1] = 1;
    for (int i = 2; i <= n;i++){
        if(broken[i])
            dp[i] = 0;
        else
            dp[i] = (dp[i - 1] + dp[i - 2]) % P;
    }
    cout << dp[n] << "\n";
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