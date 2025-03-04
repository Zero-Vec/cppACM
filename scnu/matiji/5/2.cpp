#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct accont{
    double count;
    double warn;
} a[1005];
void solve(){
    int n, m;
    int flag = 0;
    double ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i].count;
        a[i].warn = 0;
    }
    int x,y;
    double z;
    for (int i = 1; i <= m;i++){
        cin >> x >> y >> z;
        if(a[x].count<z)
            break;
        a[x].count -= z;
        a[y].count += floor(z);
        ans += z - floor(z);
        a[y].warn += z - floor(z);
        if(a[y].warn>1)
            break;
    }
    cout << fixed << setprecision(2) << ans << '\n';
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