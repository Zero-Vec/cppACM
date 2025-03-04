#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    a[0] = a[n + 1] = 1e9 + 1;
    ll ans = 0;
    for (int i = 0; i <= n;i++){
        ll x = min(a[i], a[i + 1]);
        if(x>1){
            ans += x - 1;
            a[i] -= x - 1;
            a[i + 1] -= x - 1;
        }
    }
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