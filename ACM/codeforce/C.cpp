#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], n, k;
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    if(n & 1){
        for (int i = 2; i <= n;i+=2){
            ans += a[i + 1] - a[i];
        }
        if(ans<=k){
            ans = a[1];
        }
        else{
            ans = ans - k + a[1];
        }
    }
    else{
        for (int i = 1; i <= n;i+=2){
            ans += a[i + 1] - a[i];
        }
        if(ans<=k)
            ans = 0;
        else
            ans = ans - k;
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