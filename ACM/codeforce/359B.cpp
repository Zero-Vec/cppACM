// https://codeforces.com/problemset/problem/359/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N];
int n, k;
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= 2 * n;i++)
        a[i] = 2 * n - i + 1;
    for (int i = 1; i <= k;i++)
        swap(a[2 * i - 1], a[2 * i]);
    for (int i = 1; i <= 2 * n;i++)
        cout << a[i] << " ";
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