#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b;
    cin >> a >> b;
    ll ans = a;
    int s = a;
    while(s>=b){
        ans += s / b;
        int k = s / b;
        s %= b;
        s += k;
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