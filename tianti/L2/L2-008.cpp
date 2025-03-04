#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    getline(cin, s);
    int res = 1;
    for (int i = 0; i < s.size() - 1;i++){
        int ans = 1;
        int x = i - 1, y = i + 1;
        while(x>=0&&y<s.size()&&s[x]==s[y]){
            x--, y++, ans += 2;
        }
        res = max(ans, res);
    }
    for (int i = 0; i < s.size() - 1;i++){
        int ans=0;
        int x = i, y = i + 1;
        while (x >= 0 && y < s.size() && s[x] == s[y]){
            x--, y++, ans += 2;
        }
        res = max(ans, res);
    }
    cout << res;
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