#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int x){
    while(x){
        int y = x % 10;
        x /= 10;
        if(y==2||y==0||y==1||y==9)
            return true;
    }
    return false;
}
void solve(){
    ll ans = 0;
    for (int i = 1; i <= 2019;i++)
        if(check(i))
            ans += i * i;
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