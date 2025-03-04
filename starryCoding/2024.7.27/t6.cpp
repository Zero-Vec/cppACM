#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[10];
void solve(){
    ll n;
    cin >> n;
    ll ans = 1;
    while(n){
        int tmp = n % 10;
        n /= 10;
        ans *= a[tmp];
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    for (int i = 0; i <= 9;i++)
        for (int j = 0; j <= 9;j++)
            for (int k = 0; k <= 9;k++){
                int tmp = i + j + k;
                if(tmp>=10)
                    break;
                a[tmp]++;
            }
    cin >> t;
    while(t--)
        solve();
    return 0;
}