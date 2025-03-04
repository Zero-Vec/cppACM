#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
char s[N], c1, c2;
int pre[N], k;
void solve(){
    cin >> k;
    cin >> s + 1;
    cin >> c1 >> c2;
    int len = strlen(s + 1);
    //cout << len;
    for (int i = 1; i <= len;i++){
        if(s[i]==c1)
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1];
    }
    ll ans = 0;
    for (int i = k; i <= len;i++){
        if(s[i]==c2)
            ans += pre[i - k + 1];
    }
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