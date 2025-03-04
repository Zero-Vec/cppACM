#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string t, s;
    cin >> t >> s;
    int ans = 0;
    for (int i = 1; i < s.size() - 1;i++){
        if(s[i]==t[i])continue;
        else{
            if(s[i-1]==s[i+1]&&s[i-1]!=s[i]){
                ans++;
                s[i] = t[i];
            }
            else
                break;
        }
    }
    cout << (s == t ? ans : -1) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}