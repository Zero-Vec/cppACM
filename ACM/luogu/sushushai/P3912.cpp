#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N1 = 1e8 + 9;
const int N2 = 3e7;
bool isprime[N1];
int prime[N2];
int n, cnt;
void init(){
    memset(isprime, 1, sizeof isprime);
    isprime[1] = false;
    for (int i = 2;i<=n;i++){
        if(isprime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n;j++){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
                break;
        }
    }
}
void solve(){
    cin>>n;
    init();
    cout << cnt;
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