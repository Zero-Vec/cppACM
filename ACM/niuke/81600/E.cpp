#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], b[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll tmp = 0, cnt = 0, ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> b[i];
        if(a[i]==b[i])
            cnt++;
        else if(a[i]>b[i])
            ans++;
    }
    cout << ans + (cnt + 1) / 2 << '\n';
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