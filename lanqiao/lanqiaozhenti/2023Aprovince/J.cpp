#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e7 + 9;
int a[N];
void solve(){
    ll n;
    cin >> n;
    a[1] = 1;
    ll ans = 1;
    for (int i = 2; i <= n;i++){
        if(a[i])continue;
        a[i] = 1;
        ans++;
        for (int j = 2 * i; j <= n;j+=i){
            a[j] = ~a[j];
        }
    }
    cout << ans;
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