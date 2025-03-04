#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        ll x;
        cin >> x;
        ll ans = 0;
        for (int i = 0; i < n;i++){
            if(x&1)
                ans += 1ll << (n - i - 1);
            x >>= 1;
        }
        cout << ans << '\n';
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
void solve(){
    cin >> n >> m;
    while(m--){
        ll x;
        cin >> x;
        ll ans = 0;
        for (int i = 1; i <= n;i++){
            ans *= 2;
            if(x&1)
                ans++;
            x /= 2;
        }
        cout << ans << '\n';
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
*/