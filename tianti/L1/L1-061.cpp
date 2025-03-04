#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    double h,w;
    cin>>w>>h;
    h *= h;
    double ans = w / h;
    cout << fixed << setprecision(1) << ans << '\n';
    if(ans>25)
        cout << "PANG";
    else
        cout << "Hai Xing";
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