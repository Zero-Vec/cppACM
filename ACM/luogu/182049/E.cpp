#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int cnt = 0;
    for (int i = 1; i <= m;i++){
        int x;
        int t = 0;
        for (int i = 1; i <= n;i++){
            cin >> x;
            if(x==k)
                t++;
        }
        cnt += ((n + 1) / 2 <= t);
    }
    // cout << cnt << '\n';
    cout << (((m + 1) / 2) <= cnt ? "YES" : "NO");
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