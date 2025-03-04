#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> citys;
map<string, vector<string>> mp;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        string d, c;
        cin >> d >> c;
        if(!mp.count(c)){
            citys.push_back(c);
        }
        mp[c].push_back(d);
    }
    for(const auto i:citys){
        cout << i << " " << mp[i].size() << "\n";
        for(const auto j:mp[i]){
            cout << j << "\n";
        }
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