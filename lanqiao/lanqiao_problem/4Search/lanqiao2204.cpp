#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000;
ll d[N];
/*
ll f(ll n){
    if(n<=2)
        return 1;
    if(d[n]!=-1)
        return d[n];
    d[n] = f(n - 1) + f(n - 2);
    return d[n];
}
*/
void solve(){
    /*
    memset(d, -1, sizeof d);
    for (ll i = 1; i < N;i++){
        cout << i << "    " << f(i) % 10 << "\n";
    }
    */
    ll t = 202202011200;
    //cout << t % 60;
    cout << t / 60 * 8 * 1ll;
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