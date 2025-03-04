#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9, p = 1e9 + 7;
ll C[N][N], n, m;
void solve(){
    cin >> n >> m;
    for (int i = 0; i < N;i++)
        C[i][0] = 1, C[0][i] = 0;
    C[0][0] = 1;
    for (int i = 1; i < n;i++)
        for (int j = 1; j < m;j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    for (int i = 0; i < n;i++)
        for (int j = 0;j<m;j++)
            cout << C[i][j] << " \n"[j == m - 1];
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9, p = 1e9 + 7;
ll fac[N], n, m;
ll qmi(ll b,ll power){
    ll res = 1;
    while(power){
        if(power & 1)
            res = res * b % p;
        power >>= 1;
        b = b * b % p;
    }
    return res;
}
ll inv(ll x){
    return qmi(x, p - 2);
}
ll C(ll n, ll m){
    if(n<0||m<0||n<m)
        return 0;
    return fac[n] * inv(fac[m]) % p * inv(fac[n - m]) % p;
}
void solve(){
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i <= 1e3; i++)
        fac[i] = fac[i - 1] * i % p;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            cout << C(i, j) << " \n"[j == m - 1];
    // cout << C(0, 0);
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
*/