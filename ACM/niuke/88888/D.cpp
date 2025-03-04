#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e3 + 9;
ll n, k, b, x[N], y[N];
map<pair<ll, ll>, char> res;
void solve(){
    cin >> n >> k >> b;
    vector<ll> su, sd, s0;
    for (int i = 1; i <= 2 * n;i++){
        cin >> x[i] >> y[i];
        ll tmp = k * x[i] + b;
        if(tmp > y[i])
            su.push_back(i);
        else if(tmp == y[i])
            s0.push_back(i);
        else
            sd.push_back(i);
    }
    ll ans = 0;
    while(su.size() && sd.size()){
        res[{su.back(), sd.back()}] = 'Y';
        su.pop_back(), sd.pop_back();
        ans++;
    }
    while(su.size() && s0.size()){
        res[{su.back(), s0.back()}] = 'Y';
        su.pop_back(), s0.pop_back();
        ans++;
    }
    while (sd.size() && s0.size()){
        res[{sd.back(), s0.back()}] = 'Y';
        sd.pop_back(), s0.pop_back();
        ans++;
    }
    while(s0.size()){
        ll t1 = s0.back();
        s0.pop_back();
        ll t2 = s0.back();
        s0.pop_back();
        res[{t1, t2}] = 'Y';
        ans++;
    }
    while(su.size()){
        ll t1 = su.back();
        su.pop_back();
        ll t2 = su.back();
        su.pop_back();
        res[{t1, t2}] = 'N';
    }
    while (sd.size()){
        ll t1 = sd.back();
        sd.pop_back();
        ll t2 = sd.back();
        sd.pop_back();
        res[{t1, t2}] = 'N';
    }
    cout << ans << '\n';
    for(auto [x,y]:res)
        cout << x.first << " " << x.second << " " << y << '\n';
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