#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string merge(string s1,string s2){
    int l1 = s1.size(), l2 = s2.size();
    int minn = min(l1, l2);
    for (int i = minn; i >= 1;i--){
        string a = s1.substr(l1 - i);
        string b = s2.substr(0, i);
        if(a==b)
            return s1 + s2.substr(i);
    }
    return s1 + s2;
}
int stringLen(string a,string b,string c){
    int ans = merge(merge(a, b), c).size();
    return ans;
}
void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    if(a.find(b)!=-1)
        b = a;
    if (b.find(a) != -1)
        a = b;
    if (a.find(c) != -1)
        c = a;
    if (c.find(a) != -1)
        a = c;
    if (b.find(c) != -1)
        c = b;
    if (c.find(b) != -1)
        b = c;
    int ans = 1e9;
    ans = min(stringLen(a, b, c), ans);
    ans = min(stringLen(a, c, b), ans);
    ans = min(stringLen(b, a, c), ans);
    ans = min(stringLen(b, c, a), ans);
    ans = min(stringLen(c, b, a), ans);
    ans = min(stringLen(c, a, b), ans);
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