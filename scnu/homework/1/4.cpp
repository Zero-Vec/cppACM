#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2510;
vector<string> v[N];
void solve(){
    int n, k;
    cin>>n>>k;
    for (int i = 1; i <= n;i++){
        string name;
        int x;
        cin >> name >> x;
        while(x--){
            int t;
            cin >> t;
            v[t].push_back(name);
        }
    }
    for (int i = 1; i <= k;i++){
        sort(v[i].begin(), v[i].end());
        cout << i << " " << v[i].size() << '\n';
        for(auto name:v[i]){
            cout << name << '\n';
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