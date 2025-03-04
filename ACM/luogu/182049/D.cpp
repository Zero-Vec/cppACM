#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int n, m;
int cnt[N], a[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0, res = -1;
    for (int i = 1; i <= m;i++)
        if(a[i]*cnt[i]>ans)
            ans = a[i] * cnt[i], res = i;
    cout << res;
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