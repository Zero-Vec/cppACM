#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    map<int, int> mp;
    vector<int> a;
    int x;
    while(cin >> x && x != -1){
        a.push_back(x);
    }
    while(cin >> x && x != -1){
        mp[x] = 1;
    }
    for (int i = 0; i < a.size();i++)
        if(!mp[a[i]])
            cout << a[i] << " ";
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