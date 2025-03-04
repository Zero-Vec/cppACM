#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s, t;
void solve(){
    cin >> s >> t;
    int l = t.size();
    int i = 0, j = 0;
    for (i = 0; i < s.size();i++){
        if(s[i] == t[j]){
            j++;
        }
        if(j == l)
            break;
    }
    cout << (j == l ? "Lucky!" : "QAQ Unlucky!");
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