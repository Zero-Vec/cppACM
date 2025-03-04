#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 9;
bool isprime[N];
int prime[N];
int cnt;
void init(int n)
{
    memset(isprime, 1, sizeof isprime);
    isprime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve(){
    init(1e7);
    int s;
    cin >> s;
    int i = 1;
    vector<int> ans;
    while(s!=1){
        while(s != 1 && s % prime[i] == 0)
            s /= prime[i], ans.push_back(prime[i]);
        i++;
    }
    //cout << s;
    for(auto j:ans)
        cout << j << '\n';
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