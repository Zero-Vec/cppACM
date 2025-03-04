#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    char op;
    double tall;
    cin >> op >> tall;
    double ans;
    if(op=='M'){
        ans = tall / 1.09;
    }
    else{
        ans = tall * 1.09;
    }
    cout << fixed << setprecision(2) << ans << '\n';
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