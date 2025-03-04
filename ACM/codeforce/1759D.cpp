// https://codeforces.com/problemset/problem/1759/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll k = 1, t = n, c2 = 0, c5 = 0;
    while (t % 2 == 0)
        c2++, t /= 2;
    while (t % 5 == 0)
        c5++, t /= 5;
    while (k * 2 <= m && c2 < c5)
        c2++, k *= 2;
    while (k * 5 <= m && c5 < c2)
        c5++, k *= 5;
    while (k * 10 <= m)
        k *= 10;
    cout << n * (m / k) * k << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int get0(ll x){
    int res = 0;
    while(x%10==0){
        res++;
        x /= 10;
    }
    return res;
}
void solve(){
    ll n, m;
    cin >> n >> m;
    int gs = 0;
    ll ans = n * m;
    for (int i = m; i >= 1;i--){
        if(get0(n*i)>gs){
            gs = get0(n * i);
            ans = n * i;
        }
    }
    cout << ans << '\n';
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
*/