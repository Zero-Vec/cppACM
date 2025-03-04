#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int w[N], v[N];//前者是体积，后者是价值
int f[N][N];//f[i][j]表示后i~n个物品，总容量不超过j的最大价值
void solve(){
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n;i++)
        cin >> w[i] >> v[i];
    for (int i = n; i >= 1;i--){
        for (int j = 0; j <= V;j++){
            //枚举当前物品选还是不选，体积不超过j的最大价值
            if(j<w[i])
                f[i][j] = f[i + 1][j];
            else
                f[i][j] = max(f[i + 1][j], f[i + 1][j - w[i]] + v[i]);
        }
    }
    cout << f[1][V];
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