/*
给定一个正整数M，你需要构造出两个长度为N的序列A和B，其中1<=Ai,Bi<=M。你构造的序列需要满足以下要求：
1.Ai!=Bi(1<=i<=N)
2.A序列内的数各不相同，B序列内的数也各不相同。
输出能够构造出的A，B序列的数量，结果对1e9+7取模。
输入格式：输入一行，包含两个正整数N，M
输出格式：输入一个整数表示结果，对1e9+7取模
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
const int maxn = 5e5 + 9;
ll fac[maxn];
ll quick_power(ll base,ll power){
    ll result = 1;
    while(power){
        if(power&1){
            result = result * base % P;
        }
        power /= 2;
        base = base * base % P;
    }
    return result % P;
}
ll inv(ll x){
    return quick_power(x, P - 2);
}
ll C(ll m,ll n){
    if(m<0||n<0||m<n)
        return 0;
    return fac[m] * inv(fac[m - n]) % P * inv(fac[n]) % P;
}
void solve(){
    int n, m;
    cin >> n >> m;
    ll ans = C(m, n) * fac[n] % P;
    ll t = 0;
    for (int i = 1; i <= n;i++){
        t += (i & 1 ? 1 : -1) * C(n, i) % P * C(m - i, n - i) % P * fac[n - i] % P;
    }
    ans = ans * (((ans - t) % P + P) % P) % P;
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i < maxn;i++){
        fac[i] = fac[i - 1] * i % P;
    }
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}