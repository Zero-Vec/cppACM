#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 525600 + 9;
const int inf = 0x3f3f3f3f;
int m[N], dp[N], c[N];
int sum;
void solve(){
    //cout << 365 * 24 * 60;
    int n, M;
    cin >> n >> M;
    for (int i = 0; i < n;i++)
        cin >> m[i];
    for (int i = 0; i < n;i++){
        cin >> c[i];
        sum += c[i];
    }
    memset(dp, inf, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n;i++)
        for (int j = sum; j >= c[i];j--){
            //一定得从sum倒着来
            dp[j] = min(dp[j], dp[j - c[i]] + m[i]);//求出到达这个金币所需的最短时间
        }
    for (int i = sum; i >= 0;i--)
        if(dp[i]<=M){
            cout << i;
            break;
        }
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