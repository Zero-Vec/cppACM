#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a,int b){
    return !b ? a : gcd(b, a % b);
}
void solve(){
    int n, m;
    cin >> n >> m;
    int ans = gcd(n, m);
    cout << ans << " " << n * m / ans;
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