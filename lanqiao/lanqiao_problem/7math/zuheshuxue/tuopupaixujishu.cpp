#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int maxn = 5e5 + 9;
ll ans[maxn];
void solve(){
    int n;
    cin >> n;
    cout << ans[n] << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll c = 2;
    ans[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        ans[i] = ans[i - 1] * i % P * c % P;
        c = c * 2 % P;
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}