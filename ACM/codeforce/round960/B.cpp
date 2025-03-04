#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], n, x, y;
void solve(){
    cin >> n >> x >> y;
    memset(a, 0, sizeof a);
    a[x] = a[y] = 1;
    for (int i = y + 1; i < x;i++)
        a[i] = 1;
    for (int i = y - 1; i >= 1; i--)
        if ((i - y + 2) & 1)
            a[i] = -1;
        else
            a[i] = 1;
    for (int i = x + 1; i <= n; i++)
        if ((i - x) & 1)
            a[i] = -1;
        else
            a[i] = 1;
    for (int i = 1; i <= n;i++)
        cout << a[i] << " \n"[i == n];
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