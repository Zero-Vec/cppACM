#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int mn=1e5,mx=-1e5;
    int k1, x;
    cin >> k1;
    int ans = 0, gs = 0;
    for (int i = 0; i < 4;i++){
        cin >> x;
        if(x<=k1)
            gs++;
    }
    cout << 5 - gs - 1 << '\n';
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