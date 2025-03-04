#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, bool> m1;
map<string, int> m2, m3;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        string s;
        int x;
        cin >> s >> x;
        if(!m1[s]){
            m1[s] = true;
            m2[s] = 1000 + x;
        }
        else{
            m2[s] += x;
        }
        m3[s] = i;
    }
    int ans = 1e9;
    for(const auto f:m2){
        ans = min(ans, f.second);
    }
    int index = 110;
    string flower;
    for(const auto id:m3){
        if(m2[id.first]==ans){
            if(id.second<index){
                index = id.second;
                flower = id.first;
            }
        }
    }
    cout<<flower<<'\n'<<ans;
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