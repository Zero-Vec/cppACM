#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
void solve(){
    cin >> n >> k;
    cout << n * (n - 1) / 2 - k;
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