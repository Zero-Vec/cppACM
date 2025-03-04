#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
ll n, k;
void solve(){
    cin >> n >> k;
    ll tmp = 1, ans = 0;
    for (int i = 0; i < 31;i++){
        if(1 & (k >> i)){
            ans = (ans + tmp) % p;
        }
        tmp = tmp * n % p;
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