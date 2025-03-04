#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    //各个位数之和是3的倍数，则该数是3的倍数
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        for(auto j:s)
            ans += j - '0';
    }
    cout << (ans % 3 ? "NO" : "YES");
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