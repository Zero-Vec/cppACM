#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, m;
    cin >> n >> m;
    if(m == 1)
        cout << n + 1 << '\n';
    else if(m == 2)
        cout << n << '\n';
    else if(m == 3)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
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