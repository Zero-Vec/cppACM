#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, m;
    cin >> n >> m;
    cout << (min(n, m) & 1 ? "Piper\n" : "YunYan\n");
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