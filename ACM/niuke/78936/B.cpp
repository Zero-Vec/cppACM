#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N],b[N];
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int ans = 0;
    for (int i = n, j = m; i >= 1;i--)
        if(a[i]<=b[j])
            ans++, j--;
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