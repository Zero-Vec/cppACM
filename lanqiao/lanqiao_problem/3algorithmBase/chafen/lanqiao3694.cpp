#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
using ll = long long;
ll a[N][N], d[N][N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //二维差分板子题
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
    while(q--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        d[x1][y1] += c, d[x2 + 1][y2 + 1] += c, d[x1][y2 + 1] -= c, d[x2 + 1][y1] -= c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = d[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " \n"[j == m];
    return 0;
}