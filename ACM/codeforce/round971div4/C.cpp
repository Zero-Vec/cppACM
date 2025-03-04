#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll x, y, k;
    cin >> x >> y >> k;
    ll xa = (x + k - 1) / k, ya = (y + k - 1) / k;
    if(ya >= xa)
        cout << ya * 2 << '\n';
    else
        cout << xa * 2 - 1 << '\n';
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