#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll x){
    if(x <= 1)
        return false;
    if(x == 2)
        return true;
    for (int i = 2;i <= sqrt(x);i++)
        if(x % i == 0)
            return false;
    return true;
}
ll getnum(ll x){
    ll ans = 0;
    while(x){
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
void solve(){
    ll n;
    cin >> n;
    if(check(n) && check(getnum(n)))
        cout << "yes\n";
    else
        cout << "no\n";
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