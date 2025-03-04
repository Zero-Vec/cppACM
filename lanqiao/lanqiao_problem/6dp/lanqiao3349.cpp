// 本题的难点仍在于状态转移方程的设计与列写
// 由于两台机器完全相同，若总时间为sum，其中一台洗车时间为i，则另一台洗车时间为sum-i
// i与sum-i中的较大值即为最终答案
// 故本题可以只考虑其中一台机器，枚举其所有洗车方案(可能花费的洗车时间)并使用动态规划验证该方案是否可行
// 最终遍历该台机器所有可行的洗车方案，计算并比较出最终的洗车时间
// 注：本题有一种错误解法，即把数组排序以后令两台机器分别从头和尾开始往中间遍历洗车
// 这种解法是基于贪心思想的，但它并不能保证两台机器的洗车时间尽可能的接近，因此无法得出正确答案
// 事实上在允许的时间复杂度内，本题并不存在直接找出最佳洗车方案的算法，
// 只能使用动态规划来验证每一种洗车方案,然后比较得出最终答案
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
bool dp[N][11000];//dp[i][j]表示前i辆车（每辆车可以洗或不洗），洗车总时间能否为j
int t[N];
void solve(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> t[i];
        sum += t[i];
    }
    for (int i = 0; i <= n;i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= sum;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=t[i])
                dp[i][j] = dp[i][j] | dp[i - 1][j - t[i]];
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= sum;i++){
        if(dp[n][i]){
            int tmp = max(sum - i, i);
            ans = min(ans, tmp);
        }
    }
    cout << ans;
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