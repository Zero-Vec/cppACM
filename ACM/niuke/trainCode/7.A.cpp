#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
char mp[N][N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> mp[i][j];
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, tag = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if (mp[i][j] == 'x')
            {
                x1 = i, y1 = j;
                tag = 1;
                break;
            }
        }
        if (tag)
            break;
    }
    tag = 0;
    for (int i = n; i >= 1;i--){
        for (int j = m; j >= 1;j--){
            if (mp[i][j] == 'x')
            {
                x2 = i, y2 = j;
                tag = 1;
                break;
            }
        }
        if (tag)
            break;
    }
    // cout << x1 << " " << y1 << '\n';
    // cout << x2 << " " << y2 << '\n';
    int l = y2 - y1 + 1, row = x2 - x1 + 1;
    int g = __gcd(l, row);
    for (int i = 1; i <= row / g;i++){
        for (int j = 1; j <= l / g;j++)
            cout << 'x';
        cout << '\n';
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