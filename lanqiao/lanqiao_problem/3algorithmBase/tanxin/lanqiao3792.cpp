#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, k, a[N];
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll cnt = 0, sum = 0;
    for (int i = 1; i <= n;i++){
        if(sum>k)
            break;
        sum += a[i], cnt++;
    }
    sum -= a[cnt];
    a[cnt] = (a[cnt] & 1 ? a[cnt] / 2 + 1 : a[cnt] / 2);
    if(sum+a[cnt]<=k)
        cout << cnt;
    else
        cout << cnt - 1;
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