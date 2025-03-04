#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// 01背包问题 每个只能选一次 倒序遍历
// dp[i][j][k] 表示 到第i行为止该行选j个元素 余数为k的最大值
const ll N = 110, INF = 1e9;
ll a[N][N], dp[N][N][N], n, m, mod;
void solve(){
    cin >> n >> m >> mod;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    memset(dp, -INF, sizeof dp);
    // for (int i = 0; i < mod;i++)
    //     dp[0][0][i] = 0;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(j == 1){
                for (int k = 0; k <= m / 2;k++)
                    for (int l = 0; l < mod;l++)
                        dp[i][0][l] = max(dp[i][0][l], dp[i - 1][k][l]);
            }
            // 前面两层循环的目的是遍历aij 下面这个是看aij进去之前取了多少个
            for (int k = m / 2 - 1; k >= 0;k--)
                for (int l = 0; l < mod;l++)
                    dp[i][k + 1][(l + a[i][j]) % mod] =
                        max(dp[i][k + 1][(l + a[i][j]) % mod], dp[i][k][l] + a[i][j]);
        }
    }
    ll ans = -INF;
    // 枚举最后一行取多少个
    for (int j = 0; j <= m / 2;j++){
        // cout << dp[n][j][2] << '\n';
        ans = max(ans, dp[n][j][0]);
    }
    cout << ans << '\n';
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
/*

#include <bits/stdc++.h>
using namespace std;

const int MAX = 75;
const int INF = 0x3f3f3f3f;
int ary[MAX][MAX], dp[MAX][MAX][MAX];

int main()
{
    // 录入数据
    int n, m, k, ans = -INF;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ary[i][j];

    // 状态数组初始化
    memset(dp, -INF, sizeof(dp));
    dp[0][0][0] = 0;

    // 状态转移
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            // 行之间的状态转移
            if (j == 1)
            {
                for (int l = 0; l <= m / 2; l++)
                    for (int r = 0; r < k; r++)
                        dp[i][0][r] = max(dp[i][0][r], dp[i - 1][l][r]);
            }
            // 列之间的状态转移
            for (int l = m / 2 - 1; l >= 0; l--)
                for (int r = 0; r < k; r++)
                    dp[i][l + 1][(r + ary[i][j]) % k] = max(dp[i][l + 1][(r + ary[i][j]) % k],
                                                            dp[i][l][r] + ary[i][j]);
        }

    // 在最后一层寻找最大值
    for (int j = 0; j <= m / 2; j++)
        ans = max(ans, dp[n][j][0]);

    // 输出结果
    cout << ans << endl;

    return 0;
}

*/