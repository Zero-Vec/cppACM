#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long a[N], d[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        d[i] = a[i] - a[i - 1];
    while(m--){
        int l, r, x;
        cin >> l >> r >> x;
        d[l] += x, d[r + 1] -= x;
    }
    for (int i = 1; i <= n;i++)
        a[i] = a[i - 1] + d[i];
    long long k = 0;
    for (int i = 1; i <= n;i++)
        cout << max(k, a[i]) << " ";
    return 0;
}