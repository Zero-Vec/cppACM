#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    map<int, int> mp;
    for (int i = 1; i <= n;i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            mp[x]++;
        }
    }
    int idx = 0, cnt = 0;
    for(auto i:mp){
        if(i.second>=cnt){
            cnt = i.second;
            idx = i.first;
        }
    }
    cout << idx << " " << cnt;
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