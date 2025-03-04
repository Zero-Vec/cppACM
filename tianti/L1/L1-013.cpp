#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(int x){
    if(x==1)
        return 1;
    return f(x - 1) * x;
}
ll ans;
void solve(){
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++){
        ans += f(i);
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