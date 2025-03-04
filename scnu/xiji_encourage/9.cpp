#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 40;
string s[N];
string del(string s, char ch){
    string ans;
    for (int i = 0; i < s.size();i++)
        if(s[i] != ch)
            ans += s[i];
    return ans;
}
void solve(){
    // string a = "abc", b = "bca";
    // cout << (b > a);
    string t;
    char ch;
    cin >> ch;
    int i = 1;
    while(cin >> t && t !="@"){
        s[i] = del(t, ch);
        i++;
    }
    sort(s+1,s+i);
    for (int j = i - 1; j > 0;j--)
        cout << s[j] << '\n';
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