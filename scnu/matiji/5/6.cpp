#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
const int N = 5e5 + 7;
int n, m, a[N], ans;
bool vis[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for (int i = 62; i >= 0;i--){
        int cnt = 0;
        for (int j = 1; j <= n;j++)
            if(!vis[j]&&!(a[j]&(1ll<<i)))
                ++cnt;
        if(cnt>=m&&!(a[n]&(1ll<<i))){
            for (int j = 1; j <= n;j++)
                if(a[j]&(1ll<<i))
                    vis[j] = 1;
        }
        else
            ans |= 1ll << i;
    }
    cout << ans << '\n';
}
signed main()
{
    //记得补题
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}