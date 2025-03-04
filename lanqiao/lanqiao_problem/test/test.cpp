#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N], b[N], n, m;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int l = 1, r = 1, ans = 0;
    while(l<=n&&r<=m){
        if(abs(a[l]-b[r])<=1){
            ans++, l++, r++;
        }
        else if(a[l]>b[r])
            r++;
        else if (a[l]<b[r])
            l++;
    }
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