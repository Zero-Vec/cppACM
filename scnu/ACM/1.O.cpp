#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[60];
void solve(){
    int n;
    cin >> n;
    int minn = 1e7 + 1;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        minn = min(minn, a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        if(a[i]>minn){
            ans += a[i] - minn;
        }
    }
    cout << ans << '\n';
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