#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 9;
bool v[N];
void solve(){
    ll n;
    cin >> n;
    memset(v, true, sizeof v);
    v[1] = false;
    for (ll i = 2; i <= n;i++){
        if(v[i])
            for (ll j = i * i; j <= n;j+=i)
                v[j] = false;
    }
    for (int i = 1; i <= n;i++)
        if(v[i])
            cout << i << " ";
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