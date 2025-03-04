#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll a[N], d[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        d[i] = a[i] - a[i - 1];
    while(q--){
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c, d[r + 1] -= c;
    }
    //前缀和还原数组
    for (int i = 1; i <= n;i++)
        a[i] = a[i - 1] + d[i];
    for (int i = 1; i <= n;i++)
        cout << a[i] << " ";
    return 0;
}