#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x,y;
    cin>>x>>y;
    int s1 = 100 * y, s2 = 100 * (100 - x);
    cout << 5000 - (s1 + s2) / 2;
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