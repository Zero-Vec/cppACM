#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
const int p = 998244353;
int n, a[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    bool tag = true;
    while(tag){
        tag = false;
        for (int i = n; i > 1;i--){
            if(a[i]>a[i-1]){
                tag = true;
                a[i]--, a[i - 1]++;
            }
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n;i++)
        ans = ans * a[i] % p;
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