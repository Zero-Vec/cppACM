#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, k, t, b, d[N], a[N];
void solve(){
    cin >> n >> k;
    while(k--){
        cin >> t >> b;
        d[t] += 1, d[b + 1] -= 1;
    }
    for (int i = 1; i <= n;i++){
        a[i] = a[i - 1] + d[i];
    }
    sort(a + 1, a + 1 + n);
    cout << a[n / 2 + 1] << '\n';
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