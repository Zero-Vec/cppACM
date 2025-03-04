#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1020];
ll a[1020];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    if(!k){
        ll ans = a[1];
        for (int i = 1; i <= n;i++){
            dp[i] = max(a[i], dp[i - 1] + a[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans;
    }
    else{
        ll sum = a[1];
        for (int i = 1; i < n;i++){
            swap(a[i],a[i + 1]);
            memset(dp, 0, sizeof(dp));
            ll ans = a[1];
            for (int i = 1; i <= n;i++){
                dp[i] = max(a[i], dp[i - 1] + a[i]);
                ans = max(ans, dp[i]);
            }
            sum = max(sum, ans);
            swap(a[i], a[i + 1]);
        }
        cout << sum;
    }
    return 0;
}