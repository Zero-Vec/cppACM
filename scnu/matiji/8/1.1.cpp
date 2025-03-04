#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N], pre[N];
int l[N * 2], r[N * 2];
void solve(){
    int n;
    cin >> n;
    l[n] = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(!a[i])
            a[i] = -1;
        pre[i] = pre[i - 1] + a[i];
        int tmp = pre[i] + n;
        if(!l[tmp])
            l[tmp] = i;
        else
            r[tmp] = i;
    }
    int ans = 0;
    for (int i = 0; i < 2 * N;i++){
        ans = max(ans, r[i] - l[i]);
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