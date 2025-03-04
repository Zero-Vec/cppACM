#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
ll sum = 0;
ll ans = 0;
void solve(){
    ll n;
    cin >> n;
    vector<ll> v;
    bool tag = false;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]!=1)
            tag = 1;
        sum += a[i];
    }
    if(!tag)
        cout << 1;
    else if(n==1){
        cout << 1;
    }
    else{
        for (ll i = 1; i <= sqrt(sum);i++){
            if(sum%i==0){
                v.push_back(i);
                if(i*i!=sum){
                    v.push_back(sum / i);
                }
            }
        }
        for(const auto num:v)
            if(num*n<=sum)
                ans++;
        cout << ans;
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