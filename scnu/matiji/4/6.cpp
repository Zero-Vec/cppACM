#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e6;
const int N = 5e4 + 9;
ll f[N];
ll gcd(ll a,ll b){
    return !b ? a : (gcd(b, a % b));
}
void solve(){
    int n, m;
    cin >> n >> m;
    ll k = gcd(n, m);
    f[1] = 1;
    for (int i = 2; i < N;i++)
        f[i] = (f[i - 1] + f[i - 2]) % p;
    cout << f[k];
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