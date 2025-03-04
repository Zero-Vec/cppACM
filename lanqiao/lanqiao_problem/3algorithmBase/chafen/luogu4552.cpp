#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], d[N];
int n;
void solve(){
    cin >> n;
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        if(i==1)continue;
        if (d[i] > 0)
            cnt1 += d[i];
        else if (d[i] < 0)
            cnt2 -= d[i];
    }
    cout << 1ll * (min(cnt1, cnt2) + abs(cnt1 - cnt2)) << '\n';
    cout << abs(cnt1 - cnt2) + 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}