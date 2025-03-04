#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<int, int> mp;
void solve(){
    mp[1] = 3, mp[2] = 4, mp[3] = 5, mp[4] = 6, mp[5] = 7, mp[6] = 1, mp[7] = 2;
    int n;
    cin>>n;
    cout << mp[n];
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