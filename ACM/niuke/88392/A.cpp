#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    cout << (x + y <= n ? "YES" : "NO") << '\n';
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