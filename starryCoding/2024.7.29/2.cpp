#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 60;
int n, k, a[N];
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int mn = 1e9;
    for (int i = 1; i <= n - k + 1;i++){
        mn = min(a[i + k - 1] - a[i], mn);
    }
    cout << mn << '\n';
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