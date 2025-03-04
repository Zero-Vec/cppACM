#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    cin >> n;
    if(n == 1 || n == 3)
        cout << "YES\n", cout << 2 << " " << 3 << '\n';
    else if(n == 2)
        cout << "NO\n";
    else
        cout << "YES\n", cout << 2 << " " << n << '\n';
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