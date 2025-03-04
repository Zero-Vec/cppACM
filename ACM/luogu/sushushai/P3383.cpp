#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e8+9;
const int P = 3e7;
bool isprime[N];
int prime[P];
int cnt, n, q;
void init(){
    memset(isprime, 1, sizeof isprime);
    isprime[1]=false;
    for (int i = 2; i <= n;i++){
        if(isprime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n;j++){
            isprime[i * prime[j]] = false;
            if(i%prime[j]==0)
                break;
        }
    }
}
void solve(){
    cin >> n >> q;
    init();
    while(q--){
        int x;
        cin>>x;
        cout << prime[x] << "\n";
    }
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