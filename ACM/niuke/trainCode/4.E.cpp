#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll sum,ans;
map<int, int> mp;
void solve(){
    int n, k;
    cin >> n >> k;
    mp[0] = 1;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        sum = (sum + x) % k;
        if(mp[sum]){
            ans++;
            mp.clear();
            sum = 0;
            mp[0] = 1;
        }
        else{
            mp[sum] = 1;
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