#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll a[N], b[N], pre[N], n;
bool v[N];
ll root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int i,int j){
    int x = root(i), y = root(j);
    if(x != y){
        pre[x] = y;
        a[y] += a[x];
    }
}
void solve(){
    // 倒着处理 并查集维护
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = i;
    }
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    ll mx = -1, ans = 0;
    for (int i = n; i > 1;i--){
        if(v[b[i] - 1] && !v[b[i] + 1])
            merge(b[i] - 1, b[i]);
        else if(!v[b[i] - 1] && v[b[i] + 1])
            merge(b[i] + 1, b[i]);
        else if (v[b[i] - 1] && v[b[i] + 1])
            merge(b[i] - 1, b[i]), merge(b[i] + 1, b[i]);
        v[b[i]] = true;
        mx = max(mx, a[root(b[i])]);
        ans += mx;
    }
    cout << ans << '\n';
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