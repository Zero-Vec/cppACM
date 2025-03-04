#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll l, r;
void solve(){
    ll n, k;
    cin >> n >> k;
    if(k & 1){
        l = k / 2, r = k - l;
    }
    else{
        l = k / 2 - 1, r = k / 2 + 1;
    }
    if(r>n||l<1){
        cout << 0 << '\n';
        return;
    }
    // cout << l << " " << r << '\n';
    cout << min(n - r + 1, l) << '\n';
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