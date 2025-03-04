#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, a[N];
void solve(){
    cin >> n;
    int cnt = 0;
    int mn = 1e9 + 1;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i] < 0){
            cnt++;
            a[i] = -a[i];
        }
        mn = min(mn, a[i]);
        ans += a[i];
    }
    if(cnt & 1){
        ans -= 2 * mn;
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