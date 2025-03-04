#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 9;
map<string, int> mp;
int n, m, T;
string s[N];
void solve(){
    cin >> n >> m >> T;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
        mp[s[i]] = i;
    }
    while(T--){
        int x, y;
        cin >> x >> y;
        swap(s[x], s[y]);
        swap(mp[s[x]], mp[s[y]]);
    }
    while(m--){
        string tmp;
        cin >> tmp;
        cout << mp[tmp] << '\n';
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