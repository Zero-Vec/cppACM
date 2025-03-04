#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
char s[N][N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            cin >> s[i][j];
    ll ans = 0;
    for (int i = 1; i <= (n + 1) / 2;i++){
        for (int j = 1; j <= n / 2;j++){
            int k = s[i][j] - '0' + s[n - j + 1][i] - '0' + s[j][n - i + 1] - '0' + s[n - i + 1][n - j + 1] - '0';
            ans += min(k, 4 - k);
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