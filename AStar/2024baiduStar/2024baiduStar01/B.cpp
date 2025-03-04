#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 5;
const ll mod = 998244353;
bool isprime[N];
int prime[N];
int cnt;
int minp[N];
ll inv[N];
int n;
void init(int n)
{
    memset(isprime, 1, sizeof isprime);
    isprime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            prime[++cnt] = i;
            minp[i] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            isprime[i * prime[j]] = false;
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}
void invinit(int n){
    inv[1] = 1;
    for (int i = 2; i <= n;i++){
        //cout << mod - mod / i << "\n";
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}
int getnum(int p, int n){
    int ans = 0;
    while(n >= p){
        n /= p;
        ans++;
    }
    return ans;
}
ll mo(ll x){
    return (x % mod + mod) % mod;
}
void solve()
{
    int n;
    cin >> n;
    init(n);
    ll lcm = 1;
    for (int i = 1; i <= cnt;i++){
        int k = getnum(prime[i], n);
        for (int j = 0; j < k;j++)
            lcm = lcm * prime[i] % mod;
    }
    ll ans = 0;
    invinit(n);
    for (int i = 1; i <= n - 1;i++){
        ans = mo(ans + mo(lcm * mo((n - i) * (inv[i + 1]))));
    }
    //for (int i = 1; i <= n;i++)
        //cout << inv[i] << '\n';
    //cout << lcm;
    cout << ans;
    //cout<<getnum(2,9)<<'\n';
    //cout << getnum(3, 28);
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