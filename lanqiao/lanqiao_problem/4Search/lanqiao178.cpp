#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans, pre;
int color[N][N];//表示岛屿的颜色编号
bool v[N * N];
void dfs(int x,int y){
    color[x][y] = ans;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(mp[nx][ny]=='.'||color[nx][ny])continue;
        dfs(nx, ny);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(mp[i][j]=='.'||color[i][j])continue;
            ans++;//找到岛屿
            dfs(i, j);//对该片岛屿进行涂色
        }
    }
    //完全淹没岛屿
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (mp[i][j] == '.')continue;
            bool flag = true;//找到不会被淹没的岛屿
            for (int k = 0; k < 4;k++){
                int x = i + dx[k], y = j + dy[k];
                if(mp[x][y]=='.')
                    flag = false;
            }
            if(flag&&!v[color[i][j]]){
                pre++;
                v[color[i][j]] = true;
            }
        }
    }
    cout << ans - pre;
    return 0;
}