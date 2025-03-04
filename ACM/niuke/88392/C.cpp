#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool judge(ll n) { return (n & (n - 1)) == 0; }
void solve()
{
    ll a;
    cin >> a;
    if (a == 1)
    {
        cout << 2 << " " << 3 << "\n";
        return;
    }
    ll ans = (a ^ (a - 1));
    if(ans < 1 || ans > 1e9){
        cout << a + 1 << " " << (a ^ (a + 1)) << '\n';
    }
    else{
        cout << a - 1 << " " << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool judge(ll n) { return (n & (n - 1)) == 0; }
void solve(){
    ll a;
    cin >> a;
    if(a==1){
        cout << 2 << " " << 3 << "\n";
        return;
    }
    if(judge(a)){
        cout << a + 1 << " " << (a ^ (a + 1)) << '\n';
    }
    else{
        cout << 1ll * pow(2, floor(log(a) + 1)) + 1 << " ";
        ll ans = 0, k = 1;
        for (int i = 0; i < floor(log(a) + 1);i++){
            if(i == 0){
                if(a & 1 == 0)
                    ans += k;
            }
            else{
                if(a & 1)
                    ans += k;
            }
            k = k * 2;
            a >>= 1;
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
*/
