#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 2e8;
int a[40][40];
int r[40], l[40];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    memset(r, -inf, sizeof r);
    memset(l, -inf, sizeof l);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            r[i] = max(r[i], a[i][j]);
    for (int j = 1; j <= m;j++)
        for (int i = 1; i <= n;i++)
            l[j] = max(l[j], a[i][j]);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            if(a[i][j] == r[i] && a[i][j] == l[j])
                cout << a[i][j] << " " << i << " " << j << '\n';
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