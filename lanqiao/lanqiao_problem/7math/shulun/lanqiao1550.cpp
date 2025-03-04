#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N][N], b[N][N], c[N][N];
int n, m, k;
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= k;j++)
            cin >> b[i][j];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= k;j++){
            for (int z = 1; z <= m;z++){
                c[i][j] += a[i][z] * b[z][j];
            }
            cout << c[i][j] << " \n"[j == k];
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