#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=55;
ll coin[N], gold[N];
ll find(ll n, ll i){
    if(!i)
        return 0;
    if(!n)
        return 1;
    if(i==1)
        return 0;
    if(coin[n-1]+1>=i)
        return find(n - 1, i - 1);
    if(coin[n-1]+n+1>=i)
        return gold[n - 1] + i - coin[n - 1] - 1;
    if(coin[n-1]*2+n+1>=i)
        return gold[n - 1] + n + find(n - 1, i - n - 1 - coin[n - 1]);
    return gold[n];
}
void solve(){
    ll n,i;
    cin >> n >> i;
    coin[0] = gold[0] = 1;
    for (int j = 1; j <= n;j++){
        coin[j] = coin[j - 1] * 2 + j + 2;
        gold[j] = gold[j - 1] * 2 + j;
    }
    cout << find(n, i);
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