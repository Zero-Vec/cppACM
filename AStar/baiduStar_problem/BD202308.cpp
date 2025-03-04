#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    ll a;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> a;
    }
    cout << (n & 1 ? "Xiaodu" : "Duduxiong");
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