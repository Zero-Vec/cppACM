#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
char s[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
    ll ans = 0;
    for (int i = 1; i <= n - 1;i++){
        int u, v;
        cin >> u >> v;
        if(s[u] == s[v])
            ans++;
    }
    cout << ans << '\n';
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