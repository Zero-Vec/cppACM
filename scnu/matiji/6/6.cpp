#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 25;
ll f[N][N];//组合数
ll p[N];
void solve(){
    for (int i = 0; i < 25;i++)
        f[i][0] = 1;
    for (int i = 1; i <= 24;i++)
        for (int j = 1; j <= i;j++)
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
    p[0] = p[1] = 1;
    for (int i = 2; i <= 20; i++)
        p[i] = i * p[i - 1];
    
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 1; i <= n;i++)
        p[n] -= 1ll * (i & 1 ? 1 : -1) * f[n][i] * p[n - i];
    cout << p[n];
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[25];
void solve(){
    f[1] = 0, f[2] = 1;
    for (int i = 3; i <= 24;i++)
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    int n;
    cin >> n;
    cout << f[n];
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
*/