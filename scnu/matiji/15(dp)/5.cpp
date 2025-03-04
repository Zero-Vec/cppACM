#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// dp[i] 表示到目前为止 所有递增子序列中异或和为 i 的, 子序列中最小的元素
const int N = 1e5 + 9, inf = 1e9;
int dp[1100], a[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= 1023;i++)
        dp[i] = inf;
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < 1024;j++){
            if(dp[j]<a[i]){
                dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < 1024;i++)
        if(dp[i] != inf)
            ans.push_back(i);
    cout << ans.size() << '\n';
    for(auto i:ans)
        cout << i << " ";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}