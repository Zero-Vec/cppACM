#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], b[N], n;
void solve(){
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        ans += a[i];
    }
    for (int j = 1; j <= 2;j++){
        vector<int> v(n + 1);
        ll mx = 0;
        for (int i = 1; i <= n;i++){
            if(v[a[i]]){
                mx = max(mx, a[i]);
                b[i] = mx;
            }
            else{
                v[a[i]]++;
                b[i] = mx;
            }
        }
        if(j==1){
            for (int i = 1; i <= n;i++)
                ans += b[i], a[i] = b[i];
        }
    }
    // for (int i = 1; i <= n;i++)
    //     cout << b[i] << " \n"[i == n];
    for (int i = 1; i <= n;i++)
        ans += (n - i + 1) * b[i];
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