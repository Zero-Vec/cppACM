#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[15][15];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            a[i][j] = 1;
    int h, w;
    cin >> h >> w;
    int ans = 0;
    for (int k = 0; k < 4;k++){
        int nx = dx[k] + h, ny = dy[k] + w;
        if(a[nx][ny])
            ans++;
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