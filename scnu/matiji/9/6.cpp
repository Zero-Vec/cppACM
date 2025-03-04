#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
ll s[N][N], a[N][N], n, r;
void solve(){
    cin >> n >> r;
    while(n--){
        int x, y, v;
        cin >> x >> y >> v;
        x++, y++;
        a[x][y] += v;
    }
    for (int i = 1; i <= 1005;i++){
        for (int j = 1; j <= 1005;j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
    ll ans = -100;
    for (int i = r; i <= 1005;i++)
        for (int j = r; j <= 1005;j++)
            ans = max(ans, s[i][j] + s[i - r][j - r] - s[i - r][j] - s[i][j - r]);
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