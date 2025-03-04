#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    if(n==1||m==1)
        ans = n * m;
    else if(n==2){
        m -= 2;
        ll t = m / 4;
        ans += 4ll * (t + 1);
        if(m % 4 == 3)
            ans += 2;
    }
    else if(m==2){
        n -= 2;
        ll t = n / 4;
        ans += 4ll * (t + 1);
        if (n % 4 == 3)
            ans += 2;
    }
    else{
        ans = (n * m + 1) / 2;
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