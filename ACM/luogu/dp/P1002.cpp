#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
ll dp[N][N], ax, ay, bx, by;
bool j[N][N];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool judge(int x,int y){
    return x >= 0 && y >= 0 && x <= ax && y <= ay;
}
void solve(){
    cin >> ax >> ay >> bx >> by;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < 8;i++){
        int nx = bx + dx[i], ny = by + dy[i];
        if(judge(nx,ny))
            mp[{nx, ny}] = 1;
    }
    mp[{bx, by}] = 1;
    for (int i = 0; i <= ay;i++){
        if(mp.count({0,i}))
            break;
        else
            dp[0][i] = 1;
    }
    for (int i = 0; i <= ax;i++){
        if(mp.count({i,0}))
            break;
        else
            dp[i][0] = 1;
    }
    for (int i = 1; i <= ax;i++){
        for (int j = 1; j <= ay;j++){
            if(mp.count({i,j}))
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[ax][ay] << '\n';
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