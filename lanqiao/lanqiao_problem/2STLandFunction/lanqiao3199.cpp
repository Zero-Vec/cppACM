#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
map<int, int> mp;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for(const auto d:mp){
        if(d.first<d.second){
            ans += d.second - d.first;
        }
        else if(d.first>d.second){
            ans += d.second;
        }
    }
    cout << ans;
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