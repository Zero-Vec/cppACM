#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    cin >> n;
    ll mx = 0, mn = 0;
    if(n<=2){
        cout << 0 << " " << n << '\n';
        return;
    }
    ll mxn = n - 2;
    mx = 2 + mxn / 7 * 2;
    if(mxn%7==6)
        mx++;
    mn = n / 7 * 2;
    if(n%7==6)
        mn++;
    cout << mn << " " << mx << '\n';
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