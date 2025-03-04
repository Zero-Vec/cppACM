#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll t, a, k, ans = 0;
    cin >> t >> a >> k;
    ll ta = abs(a - t);
    if(a<=t&&t<=0)
        ans = abs(a) + ta;
    else if(t>=0&&a>=t)
        ans = abs(a) + ta;
    else if(a<=0&&t<=a)
        ans = abs(t);
    else if(a>=0&&t>=a)
        ans = abs(t);
    else if((t<=0&&a>=0)||a<=0&&t>=0)
        if(abs(k)<abs(a))
            ans = abs(t) + 2 * ta;
        else
            ans = abs(a) + ta;
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