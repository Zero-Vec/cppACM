#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    map<char, char> mp;
    mp['c'] = 'y', mp['y'] = 'c', mp['a'] = 'z', mp['z'] = 'a', mp['b'] = 'x', mp['x'] = 'b';
    char ch;
    cin >> ch;
    cout << mp[ch] << '\n';
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