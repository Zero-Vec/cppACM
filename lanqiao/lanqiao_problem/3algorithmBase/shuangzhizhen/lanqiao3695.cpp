#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
int n, L, R;
ll getnum(int x)
{
    ll cnt = 0;
    int l = 1, r = n;
    while (l < r)
    {
        if (a[l] + a[r] <= x)
        {
            cnt += r - l;
            l++;
        }
        else
            r--;
    }
    return cnt;
}
void solve()
{
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << getnum(R) - getnum(L - 1);
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N];
void solve(){
    int n,L,R;
    cin >> n >> L >> R;
    ll ans = 0;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++){
        int l = L - a[i], r = R - a[i];
        ans += upper_bound(a + i + 1, a + 1 + n, r) - lower_bound(a + i + 1, a + 1 + n, l);
    }
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
*/