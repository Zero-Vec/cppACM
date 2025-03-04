#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N];
int pre[35][N];
void solve(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n;i++)cin>>a[i];
    for (int w = 0; w <= 30;w++){
        for (int i = 1; i <= n;i++){
            pre[w][i] = pre[w][i - 1] + (a[i] >> w & 1);
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i <= 30;i++){
            ans += (1 << i) * (pre[i][r] - pre[i][l - 1] ? 1 : 0);
        }
        cout << ans << '\n';
    }
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