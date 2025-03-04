// https://codeforces.com/problemset/problem/1766/d
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 9, inf = 2e8;
bool isprime[N];
int prime[N];
int minp[N];
int cnt;
void init(int n){//欧拉筛
    memset(isprime, 1, sizeof isprime);
    isprime[1] = false;
    for (int i = 2; i <= n;i++){
        if(isprime[i]){
            prime[++cnt] = i;
            minp[i] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n;j++){
            isprime[i * prime[j]] = false;
            minp[i * prime[j]] = prime[j];
            if(i%prime[j]==0)
                break;
        }
    }
}
void solve(){
    int x, y;
    cin >> x >> y;
    y -= x;
    if(y==1){
        cout << -1 << '\n';
    }
    else{
        int p = minp[y];//y的最小质因子
        int ans = inf;
        while(y>1){
            ans = min(ans, (-x % p + p) % p);
            y /= p;
            p = minp[y];
        }
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init(1e7);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}