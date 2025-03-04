#include<bits/stdc++.h>
using namespace std;
int vis[15][15];//表示该位置已被多少个皇后占用
int n, ans;
void dfs(int dep){
    if(dep==n+1){
        ans++;
        return;
    }
    for (int i = 1; i <= n;i++){
        if(vis[dep][i])continue;
        //修改状态
        for (int j = dep; j <= n;j++)
            vis[j][i]++;
        for (int j = dep, k = i; j <= n && k <= n; j++,k++)
            vis[j][k]++;
        for (int j = dep, k = i; j >= 1 && k <= n; j--, k++)
            vis[j][k]++;
        for (int j = dep, k = i; j <= n && k >= 1; j++, k--)
            vis[j][k]++;
        for (int j = dep, k = i; j >= 1 && k >= 1; j--, k--)
            vis[j][k]++;
        dfs(dep + 1);
        //回溯恢复现场
        for (int j = dep; j <= n; j++)
            vis[j][i]--;
        for (int j = dep, k = i; j <= n && k <= n; j++, k++)
            vis[j][k]--;
        for (int j = dep, k = i; j >= 1 && k <= n; j--, k++)
            vis[j][k]--;
        for (int j = dep, k = i; j <= n && k >= 1; j++, k--)
            vis[j][k]--;
        for (int j = dep, k = i; j >= 1 && k >= 1; j--, k--)
            vis[j][k]--;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}