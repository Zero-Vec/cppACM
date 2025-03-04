#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
char mp[N][N];
bool v[N][N];
int n;
bool dfs(int x,int y){
    if(x==n&&y==n)
        return true;
    if(x<1||y<1||x>n||y>n||v[x][y]==1||mp[x][y]=='X')
        return false;
    if(x!=1||y!=1)
        v[x][y] = 1;
    if(dfs(x+1,y))
        return true;
    if(dfs(x,y+1))
        return true;
    if(dfs(x-1,y))
        return true;
    if(dfs(x,y-1))
        return true;
    return false;
}
void solve(){
    cin >> n;
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            cin >> mp[i][j];
    if(!dfs(1,1))
        cout << 0 << '\n';
    else if(!dfs(1,1))
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}