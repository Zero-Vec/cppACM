/*
参考思路：https://blog.csdn.net/weixin_44279771/article/details/105575382
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int n, l, r, ta, tb;
struct C{
    int k, a, b;
} c[N], d[N];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i].a, c[i].k = i + 1;
    for (int i = 0; i < n; ++i)
        cin >> c[i].b;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (min(c[i].a, c[i].b) > min(c[j].a, c[j].b))
                swap(c[i], c[j]);
    r = n - 1;
    for (int i = 0; i < n; ++i){
        if (min(c[i].a, c[i].b) == c[i].a)
            d[l++] = c[i];
        else
            d[r--] = c[i];
    }
    for (int i = 0; i < n; ++i){
        ta += d[i].a;
        if (tb < ta)
            tb = ta;
        tb += d[i].b;
    }
    cout << tb << '\n';
    for (int i = 0; i < n; ++i)
        cout << d[i].k << ' ';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}