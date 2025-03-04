#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
char mp[N][N];
int cnt[N][N];
int ans[N][N], ans1[N][N];
int n, m;
bool tag;
int getnum(int x,int y){
    int res = 0;
    for (int i = -1; i <= 1;i++)
        for (int j = -1; j <= 1;j++)
            res += ans[i + x][j + y];
    return res;
}
bool check(int x,int y){
    if(cnt[x][y]==-1)return true;
    if(cnt[x][y]==getnum(x,y))
        return true;
    return false;
}
void dfs(int x,int y){
    if(tag)return;
    if(x==n+1){
        for (int i = 1; i <= n;i++)
            if(!check(i,m))return;
        for (int i = 1; i <= m;i++)
            if(!check(n,i))return;
        tag = 1;
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m;j++)
                ans1[i][j] = ans[i][j];
        return;
    }
    for (int i = 0; i <= 1;i++){
        ans[x][y] = i;
        if((x>1&&y>1)&&!check(x-1,y-1))continue;
        if(y==m)
            dfs(x + 1, 1);
        else
            dfs(x, y + 1);
    }
    return;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> mp[i][j];
            if (mp[i][j] == '_')
                cnt[i][j] = -1;
            else
                cnt[i][j] = mp[i][j] - '0';
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout << ans1[i][j];
        cout << '\n';
    }
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