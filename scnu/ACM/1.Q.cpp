#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
const int N = 210;
ll a[N][N];
int n, m;
void solve(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            ll t = a[i][j];
            //加上四个方向
            for (int k = i - 1, z = j - 1; k >= 1 && z >= 1;k--,z--)
                t += a[k][z];
            for (int k = i + 1, z = j - 1; k <= m && z >= 1; k++, z--)
                t += a[k][z];
            for (int k = i + 1, z = j + 1; k <= m && z <= n; k++, z++)
                t += a[k][z];
            for (int k = i - 1, z = j + 1; k >= 1 && z <= n; k--, z++)
                t += a[k][z];
            ans = max(t, ans);
        }
    }
    cout << ans << '\n';
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