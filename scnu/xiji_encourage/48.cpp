#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void solve(){
    string key, s, ans;
    cin >> key;
    cin.ignore();
    getline(cin, s);
    map<char, char> mp[25];
    int len = key.size();
    for (int i = 0; i < len;i++)
        for (int j = 0; j < 26;j++)
            mp[i][dic[j]] = 'A' + (key[i] - 'A' + j) % 26;
    // for (int i = 0; i < 2;i++){
    //     for (int j = 0; j < 26;j++)
    //         cout<<mp[i][dic[j]];
    //     cout << '\n';
    // }
    for (int i = 0; i < s.size();i++){
        if(!isupper(s[i]))
            ans += s[i];
        else
            ans += mp[i % len][s[i]];
    }
    cout << ans << '\n';
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