#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int mx = 0;
    mx = max({a + b + c, a * b * c, a * b + c, a + b * c, (a + b) * c, a * (b + c)});
    cout << mx << '\n';
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