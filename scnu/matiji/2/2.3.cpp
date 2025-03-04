#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n,m,sum,ans;
int ma[N][N], ma2[N][N];
bool check(int l,int w){
    for (int i = 1; i <= n - l + 1;i++)
        for (int j = 1; j <= m - w + 1;j++){
            int num = ma2[i][j];
            for (int x = 0; x < l;x++)
                for (int y = 0; y < w;y++){
                    int xx = i + x, yy = j + y;
                    ma2[xx][yy] -= num;
                    if(ma2[xx][yy]<0)
                        return false;
                }
        }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            if(ma2[i][j]!=0)
                return false;
    return true;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cin >> ma[i][j];
            sum += ma[i][j];
        }
    for (int l = n; l >= 1; l--)
        for (int w = m; w >= 1; w--){
            if(sum%(l*w))continue;
            memcpy(ma2, ma, sizeof ma);
            if (check(l, w)){
                ans = sum / (l * w);
                cout << ans;
                return;
            }
        }
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