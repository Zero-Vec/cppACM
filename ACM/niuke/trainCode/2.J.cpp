#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        ll ans = a[1] * 2 * (n - 1);
        for (int i = 2; i < n;i++){
            ans += min(4 * a[1], 2 * a[i]) * (n - i);
        }
        cout << 2 * ans << "\n";
    }
    return 0;
}