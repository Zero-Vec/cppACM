#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.size()-1;i++){
        for (int j = i + 1; j < s.size();j++){
            bool tag = 0;
            int l = i, r = j;
            while(l<r){
                if(s[l]==s[r]){
                    l++, r--;
                }
                else if(s[l]>s[r]){
                    tag = 1;
                    break;
                }
                else{
                    break;
                }
            }
            if(tag)
                ans++;
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