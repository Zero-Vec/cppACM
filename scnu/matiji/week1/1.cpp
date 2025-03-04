#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 210;
double a[N], b[N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i] >> b[i];
    double ans = 0.0;
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            double x = a[i] * a[j] - b[i] * b[j];
            double y = a[i] * b[j] + b[i] * a[j];
            ans = max(ans, sqrt(x * x + y * y));
        }
    }
    cout << fixed << setprecision(18);
    cout << ans << "\n";
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