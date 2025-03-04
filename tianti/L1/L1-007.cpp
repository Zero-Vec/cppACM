#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<char, string> mp;
void solve(){
    mp['0'] = "ling", mp['1'] = "yi", mp['2'] = "er", mp['3'] = "san", mp['4'] = "si", mp['5'] = "wu",
    mp['6'] = "liu", mp['7'] = "qi", mp['8'] = "ba", mp['9'] = "jiu";
    string s;
    cin >> s;
    if(s[0]=='-'){
        cout << "fu";
        for (int i = 1; i < s.size();i++){
            cout << " " << mp[s[i]];
        }
    }
    else{
        for (int i = 0; i < s.size(); i++){
            if(i==s.size()-1)
                cout << mp[s[i]];
            else
                cout << mp[s[i]] << " ";
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