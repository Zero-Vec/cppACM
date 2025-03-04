#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
int l, n;
int a[N];
void solve(){
    cin >> l >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    if(!n){
        cout << 0 << " " << 0;
        return;
    }
    sort(a + 1, a + 1 + n);
    int mi = 0, ma = 0;
    for (int i = 1; i <= n;i++){
        mi = max(min(a[i], l + 1 - a[i]), mi);
    }
    ma = max(l+1-a[1], a[n]);
    cout << mi << ' ' << ma;
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