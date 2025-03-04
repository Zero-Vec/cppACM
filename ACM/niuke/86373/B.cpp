#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll a, b, n;
    cin >> a >> b >> n;
    if(b*3>n){
        ll k = n / 3 * 2;
        if(b>=k){
            ll t = n * 2 - k * 3;
            cout << (t / 2 <= a ? "YES\n" : "NO\n");
        }
        else{
            ll t = n * 2 - b / 2 * 6;
            cout << (t / 2 <= a ? "YES\n" : "NO\n");
        }
    }
    else if(b*3==n){
        if(n & 1){
            b--;
            ll k = n * 2 - b * 3;
            cout << (k / 2 <= a ? "YES\n" : "NO\n");
        }
        else
            cout << (a * 2 >= n ? "YES\n" : "NO\n");
    }
    else{
        if(b&1)
            b--;
        ll k = n * 2 - b * 3;
        cout << (k / 2 <= a ? "YES\n" : "NO\n");
    }
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