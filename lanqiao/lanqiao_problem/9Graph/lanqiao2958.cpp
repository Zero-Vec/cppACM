#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int x){
    while(x){
        int y = x % 10;
        x /= 10;
        if(y==2||y==4)
            return true;
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        if(check(i))continue;
        for (int j = 1; j <= n;j++){
            if(i==j||check(j)||i+j>=n)continue;
            int t = n - i - j;
            if(t!=i&&t!=j&&!check(t))
                ans++;
        }
    }
    cout << ans / 6;
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