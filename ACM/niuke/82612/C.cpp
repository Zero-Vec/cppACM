#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int getnum(int x){
    int ans = 0;
    while(x){
        ans++;
        x /= 10;
    }
    return ans;
}
void solve(){
    cin >> n;
    int len=getnum(n);
    if(len==1)
        cout << n << '\n';
    else{
        ll ans = 0;
        for (ll t = 1; t <= 1e18;t=t*10)
        {                               // 枚举m
            for (int i = 1; i < 10;i++){//枚举a
                for (int j = 0; j < 10;j++){
                    //枚举c
                    ll tmp = n - 1ll * i * t - j;
                    if(tmp>=0&&tmp%11==0&&tmp/11<t)
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }
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