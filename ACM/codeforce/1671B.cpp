// https://codeforces.com/problemset/problem/1671/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e6+9;
ll a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll cnt = 0;
    for (int i = 2; i <= n;i++)
        cnt += a[i] - a[i - 1] - 1;
    cout << (cnt <= 2 ? "YES" : "NO") << '\n';
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