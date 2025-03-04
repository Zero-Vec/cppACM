#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if(n == 1){
        cout << a[1] << '\n';
        return;
    }
    ll ans = 0;
    while(n >= 4){
        ans += min(a[1] * 2 + a[n] + a[n - 1], a[2] * 2 + a[1] + a[n]);
        n -= 2;
    }
    // 少于 4 人直接分类讨论即可
    if(n == 3)
        ans += a[1] + a[2] + a[3];
    else
        ans += a[2];
    cout << ans << '\n';
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