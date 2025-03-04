// https://codeforces.com/problemset/problem/1420/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll cnt[N],a[N];
int n;
int getid(ll x){
    int pos = -1;
    while(x){
        pos++;
        x >>= 1;
    }
    return pos;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n;i++){
        int pos=getid(a[i]);
        cnt[pos]++;
    }
    ll ans = 0;
    for (int i = 0; i < 64;i++){
        ans += (cnt[i] - 1) * cnt[i] / 2;
    }
    cout << ans << '\n';
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