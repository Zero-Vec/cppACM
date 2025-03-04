#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
ll ans1,ans2;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = abs(x);
    }
    if(n==1){
        cout << abs(a[1]);
        return;
    }
    //找出偶数索引的最大和奇数索引的最小
    int o = 0, j = 0;
    ll max1 = -1, min1 = 1e9 + 9;
    for (int i = 1; i <= n;i++){
        if(i&1){
            if(min1>a[i]){
                min1 = a[i];
                j = i;
            }
        }
        else{
            if(max1<a[i]){
                max1 = a[i];
                o = i;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        if(i&1)
            ans1 += a[i];
        else
            ans1 -= a[i];
    }
    swap(a[o], a[j]);
    for (int i = 1; i <= n; i++){
        if (i & 1)
            ans2 += a[i];
        else
            ans2 -= a[i];
    }
    cout << max(ans1, ans2);
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