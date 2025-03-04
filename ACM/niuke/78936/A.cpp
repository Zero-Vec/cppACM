#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
int n;
void solve(){
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n + 1;i++){
        if(i&1)continue;
        ans += max(a[i - 1], a[i]);
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