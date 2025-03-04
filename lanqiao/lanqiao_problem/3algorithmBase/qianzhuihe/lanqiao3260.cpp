#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll a[N], sum[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int n, k;
    while(t--){
        cin >> n >> k;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        ll ans = 0;
        for (int i = 1; i <= n;i++)
            sum[i] = sum[i - 1] + a[i];
        for (int i = 0; i <= k;i++){
            ans = max(ans, sum[n - i] - sum[2 * (k - i)]);
        }
        cout << ans << '\n';
    }
    return 0;
}