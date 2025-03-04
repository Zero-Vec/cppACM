#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], b[N], c[N];
void solve(){
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> b[i];
        c[i] = b[i] - a[i];
    }
    sort(c + 1, c + 1 + n);
    for (int i = n; i >= n - k + 1; i--){
        if(c[i]<=0)
            break;
        sum += c[i];
    }
    cout << sum;
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