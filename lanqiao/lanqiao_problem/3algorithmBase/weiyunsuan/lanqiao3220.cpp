#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
const int p = 1e9 + 7;
ll a[N], pre[N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    ll ans = 1;
    for (int i = 1; i <= n;i++){
        for (int j = i; j <= n;j++){
            ll t = pre[i - 1] ^ pre[j];
            if(!t){
                cout << 0;
                return;
            }
            ans = ans % p * t % p;
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