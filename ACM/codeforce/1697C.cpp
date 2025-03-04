// https://codeforces.com/problemset/problem/1697/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
char s[N], t[N];
int n;
void solve(){
    cin >> n;
    cin >> s + 1 >> t + 1;
    string S, T;
    vector<int> sa, sc, ta, tc;
    for (int i = 1; i <= n;i++){
        if(s[i]!='b')
            S += s[i];
        if(t[i]!='b')
            T += t[i];

        if(s[i]=='a')
            sa.push_back(i);
        if(s[i]=='c')
            sc.push_back(i);
        
        if(t[i]=='a')
            ta.push_back(i);
        if(t[i]=='c')
            tc.push_back(i);
    }
    if(S!=T){
        cout << "NO\n";
        return;
    }
    bool ans = true;
    for (int i = 0; i < sa.size();i++){
        if(sa[i]>ta[i])
            ans = false;
    }
    for (int i = 0; i < sc.size();i++){
        if(sc[i]<tc[i])
            ans = false;
    }
    cout << (ans ? "YES" : "NO") << '\n';
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