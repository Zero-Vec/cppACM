// 本题的难点仍在于dp数组含义的设计 和 状态转移方程的列写
// 对于序列中的每个元素ai，其值只与前一个元素有关，与前面其他元素无关
// 且前一个元素与后一个元素成倍数关系，且不超过K
// 故令dp[i][j]表示序列长度为i，且以j结尾的合法序列的数量
// 设j的因子列表为ki，则dp[i][j]需要不断累加所有的dp[i-1][ki]
// 如当前j=8，其因子有1,2,4,8
// 则dp[i][8]=dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][8]
// 即长为i，以8结尾的序列数量等于长为i-1，以1,2,4,8结尾的序列的数量之和
// 可以理解为对于长为i-1的序列，只有末尾为1,2,4,8时，再添加一个元素才有可能是8
// 此外还要注意两个问题：
// 一是初始化，当长度为1时不论选择1~K中的何值，都只有一种方案，故dp[1][1]~dp[1][K]均初始化为1
// 二是在求j的因子时，为了提高效率只遍历到根号j，需要注意ki恰好为j的平方根时，不能重复累加
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
const int N = 2e3 + 9;
ll dp[N][N];
void solve(){
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= k;i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n;i++){
        for (int j = 1; j <= k;j++){
            for (int z = 1; z <= sqrt(j);z++){
                if(j%z==0){
                    if(z*z!=j)
                        dp[i][j] += (dp[i - 1][j / z] + dp[i - 1][z]) % p;
                    else
                        dp[i][j] += dp[i - 1][z] % p;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= k;i++)
        ans = (ans+dp[n][i]) % p;
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