#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n, k;
void solve(){
    cin >> n >> k;
    int ans = 0;
    while(k--){
        int x, y;
        cin >> x >> y;
        int t = x;
        t = min(n - x + 1, t);
        t = min(y, t);
        t = min(n - y + 1, t);
        ans += t;
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