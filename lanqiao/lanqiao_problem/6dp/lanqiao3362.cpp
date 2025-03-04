#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//这题不会
ll mod = 1e9 + 7;
ll dp[55][2605]; // dp[i][j]表示只考虑前i条街道，总共建造j个房屋的方案数

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i <= K; i++)
        dp[0][i] = 1; // 初始化,便于后续递推

    for (int i = 1; i <= N; i++) // 依次考虑前1~N条街道
    {
        for (int j = 1; j <= M; j++) // 考虑依次在当前街道(第i条街道)建造1~M个房屋
        {
            for (int k = i - 1; k <= K - 1; k++)
            // 对于前i-1条街道，首先每条街道至少建一个房屋，总共至少建i-1个房屋,至多建K-1个房屋
            // 故从i-1遍历到K-1，即为前i-1条街道所有可能的房屋总数
            {
                // 当前街道建j个房屋，前i-1条街道总共建k个房屋，故前i条街道共建j+k个房屋，用dp[i][j+k]表示方案数
                // dp[i][j+k] 累加上 在前i-1个街道上建k个房屋的方案数，即dp[i-1][k]
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][k]) % mod;
            }
        }
    }
    cout << dp[N][K] << endl; // dp[N][K]即在前N条街道，总共建造K个房屋的方案数
    return 0;
}