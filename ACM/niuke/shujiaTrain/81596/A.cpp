#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
n是总的数字数目，k是当前讨论情况有多少个奇数，m是二进制的最大位数+1。
Ckn是选择奇数所占的位置，剩余的就是偶数的位置。
（2 ^ k - 1）^ m-1  2 ^ k-1是所有奇数在某一个特定位置的所有情况减去全是1的情况，这保证了可以在and之后得到0，m-1次是指从需要讨论第二位到m-1位。
2 ^(（n-k）（m-1）)   这个是讨论偶数的情况：n-k次是一共有n-k个偶数需要讨论， m-1次是指每个偶数需要讨论第二位到m-1位，每一位都是两个情况。
*/
const int N = 5e3 + 9;
ll p;
int n, m;
ll C[N][N];
ll quick_power(ll base,ll power){
    ll res = 1;
    while(power){
        if(power & 1)
            res = res * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return res;
}
ll mo(ll x){
    return (x % p + p) % p;
}
void solve(){
    cin >> n >> m >> p;
    for (int i = 0; i <= 5e3;i++)
        for (int j = 0; j <= i;j++){
            if(!j)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
        }
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        //枚举子序列中奇数个数
        ans = mo(ans + mo(mo(C[n][i] * quick_power(2, (n - i) * (m - 1))) * quick_power(quick_power(2, i) - 1, m - 1)));
    }
    cout << ans << '\n';
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