#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b, c, d;
    cin >> a >> b;
    c = a / 10, d = b * 10;
    cout << c << " " << d << " " << 10000 - c - d;
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