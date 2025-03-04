#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        ans += x - 1;
    }
    cout << (ans & 1 ? "gui" : "sweet");
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