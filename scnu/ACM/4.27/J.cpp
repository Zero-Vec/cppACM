#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll n, m;
ll a[N], diff[N], pre[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(i!=1)
            diff[i] = a[i - 1] - a[i];
    }
    sort(diff + 1, diff + n + 1);
    for (int i = 1; i <= n;i++)
        pre[i] = pre[i - 1] + diff[i];
    cin >> m;
    int op, k;
    while(m--){
        cin >> op >> k;
        if(op==1)
            cout << pre[n - k + 1] << '\n';
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