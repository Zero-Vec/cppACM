#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
ll a[N], pre[N];
int n, q;
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++){
        pre[i] = 1ll * (n - i) * (n - i - 1) / 2;
        pre[i] += pre[i - 1];
        //cout << pre[i] << '\n';
    }
    while(q--){
        ll k;
        cin >> k;
        int l = 0, r = n + 1;
        while(l+1!=r){
            int mid = (l + r) >> 1;
            if(pre[mid]>=k)
                r = mid;
            else
                l = mid;
        }
        cout << a[r] << "\n";
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