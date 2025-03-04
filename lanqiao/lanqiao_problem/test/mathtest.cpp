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
const int p = 1e9 + 7;
const int N = 5e5 + 9;
ll f[N];
ll quick_power(ll base,ll power){
    ll result = 1;
    while(power){
        if(power&1){
            result = result * base % p;
        }
        base = base * base % p;
        power /= 2;
    }
    return result % p;
}
ll inv(ll x){
    return quick_power(x, p - 2);
}
ll C(int m,int n){
    if(m<0||n<0||m<n)
        return 0;
    return f[m] * inv(f[m - n]) % p * inv(f[n]) % p;
}
void solve(){
    int n,m;
    cin >> n >> m;
    ll ans = C(m, n) * f[n] % p;
    ll t = 0;//B的不合法数
    for (int i = 1;i<=n;i++){
        t += (i & 1 ? 1 : -1) * C(n, i) % p * f[m - i] % p * inv(f[m - n]) % p;
    }
    ans = ans * (((ans - t) % p + p) % p) % p;
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    f[0] = f[1] = 1;
    for (int i = 2; i < N;i++){
        f[i] = f[i - 1] * i % p;
    }
    while (t--)
        solve();
    return 0;
}