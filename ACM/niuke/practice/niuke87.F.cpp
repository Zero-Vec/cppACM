#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], pre[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    ll cnt,sum=0;
    cin >> cnt;
    ll or1 = a[n - 1];
    for (int i = n - 2; i > 0;i--){
        sum = max(sum, or1 + pre[i]);
        or1 = or1 | a[i];
    }
    cout << sum + cnt;
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