#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll cnt[N], pre[N];
void init(){
    for (int i = 1; i < N;i++){
        int x = i;
        while(x){
            x /= 3;
            cnt[i]++;
        }
    }
    for (int i = 1; i < N;i++)
        pre[i] = pre[i - 1] + cnt[i];
}
void solve(){
    ll ans = 0;
    ll l, r;
    cin >> l >> r;
    ans = 2 * cnt[l];
    ans += pre[r] - pre[l];
    // for (int i = l + 1; i <= r; i++)
    //     ans += floor(log(i) / log(3)) + 1;
    cout << ans << '\n';
    // cout << pre[r] + pre[l] - pre[l - 1] * 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    init();
    cin >> t;
    while(t--)
        solve();
    return 0;
}