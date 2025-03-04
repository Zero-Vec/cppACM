#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char s[110];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
    stack<char> st;
    bool ans = true;
    for (int i = 1; i <= n;i++){
        if(s[i]=='(')
            st.push(s[i]);
        else{
            if(st.size()){
                st.pop();
            }
            else
                ans = false;
        }
    }
    if(st.size()>0)
        ans = false;
    cout << (ans ? "Yes" : "No");
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