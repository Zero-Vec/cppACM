#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
bool isprime[N];
int prime[N];
int cnt;
void init(){
    memset(isprime, 1, sizeof isprime);
    isprime[1] = false;
    for (int i = 2; i <= 1e5; i++){
        if (isprime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= 1e5; j++){
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    bool tag = 0;
    while(n--){
        int x;
        cin >> x;
        if(isprime[x]){
            ans++;
            if(x!=3)
                tag = 1;
        }
        if(x==3){
            ans++;
        }
    }
    if(ans&1){
        cout << 0 << '\n';
    }
    else{
        if(!ans)
            cout << -1 << "\n";
        else{
            if(tag)
                cout << 1 << '\n';
            else
                cout << -1 << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}