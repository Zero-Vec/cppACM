#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e6+9;
bool st[N];
void solve(){
    string s;
    cin >> s;
    int ans = 0;
    if(s.size()==1){
        cout << ans;
        return;
    }
    for (int i = 0; i < s.size();i++){
        if(st[i])continue;
        if(!i){
            if((s[i]==s[i+1])||(s[i]=='?'||s[i+1]=='?')){
                ans++;
                st[i] = 1, st[i + 1] = 1;
            }
        }
        else if(i==s.size()-1){
            if(!st[i-1]){
                if ((s[i] == s[i - 1]) || (s[i] == '?' || s[i - 1] == '?')){
                    ans++;
                    st[i] = 1, st[i - 1] = 1;
                }
            }
        }
        else{
            if (!st[i - 1]){
                if ((s[i] == s[i - 1]) || (s[i] == '?' || s[i - 1] == '?')){
                    ans++;
                    st[i] = 1, st[i - 1] = 1;
                }
            }
            else{
                if ((s[i] == s[i + 1]) || (s[i] == '?' || s[i + 1] == '?')){
                    ans++;
                    st[i] = 1, st[i + 1] = 1;
                }
            }
        }
    }
    cout << ans;
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