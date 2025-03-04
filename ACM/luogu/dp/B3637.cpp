#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
int dp[N], a[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j < i;j++)
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
    cout << *max_element(dp + 1, dp + 1 + n) << '\n';
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