#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
void solve(){
    cin >> n >> m;
    int x, mx = 0, mn = 1e9;
    while(n--){
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout << (mx != m || mn != 1 ? "Yes" : "No");
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