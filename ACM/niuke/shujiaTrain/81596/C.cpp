#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
const int p = 1000000007;
ll a[N], suf[N], pre[N];
void solve(){
    ll q, t, v;
    cin >> q;
    ll i = 0;
    while(q--){
        cin >> t >> v;
        if(i <= t)
            i = 0;
        else{
            for (int j = i - t + 1; j <= i;j++)
                suf[j] = 0, a[j] = 0;
            i -= t;
        }
        i++;
        a[i] = i * v % p;
        suf[i] = (suf[i + 1] + a[i]) % p;
        // for (int j = 1; j <= i;j++)
        //     cout << a[j] << ' ';
        // cout << i << ' ' << t;
        // cout << '\n';
        pre[i] = (pre[i - 1] + suf[i]) % p;
        cout << pre[i] << '\n';
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