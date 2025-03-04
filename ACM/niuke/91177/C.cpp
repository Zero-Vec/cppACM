#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e5 + 9;
const ld pi = 3.14159265358979324;
struct circle
{
    ld x, y, r, d;
    bool operator< (const circle &u) const
    {
        return r * r * d <= u.r * u.r * u.d;
    }
} c[N];
// bool cmp(circle &a,circle &b){
//     return a.r*a.r*a.d<=b.r*b.r*b.d;
// }
ld k;
ll n;
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i].x >> c[i].y >> c[i].r, c[i].d = c[i].r - sqrt(c[i].x * c[i].x + c[i].y * c[i].y);
    sort(c + 1, c + 1 + n);
    ll cnt = 0;
    for (int i = 1; i <= n;i++){
        ld t = c[i].r * c[i].r * c[i].d;
        // cout << t << '\n';
        // cout << "r:  " << c[i].r << '\n';
        // cout << "d:  " << c[i].d << '\n';
        if(t > 0){
            cnt++;
        }
    }
    // cout << cnt << '\n';
    if(cnt <= k){
        cout << 0 << '\n';
        return;
    }
    ld sum = 0.0;
    ll res = 0;
    for (int i = 1; i <= n;i++){
        if(c[i].d > 0){
            res++;
            sum += c[i].r * c[i].r * c[i].d;
        }
        if(res == cnt - k)
            break;
    }
    cout << fixed << setprecision(18);
    cout << pi * sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}