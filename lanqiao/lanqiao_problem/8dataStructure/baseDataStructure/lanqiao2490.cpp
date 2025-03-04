#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
char st[N];
int top = 0;
string s;
void solve(){
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n;i++){
        if(s[i]=='('){
            st[++top] = '(';
        }
        else{
            if(!top){
                cout << "No";
                return;
            }
            else{
                top--;
            }
        }
    }
    cout << (top ? "No" : "Yes");
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
stack<char> st;
int n;
string s;
void solve(){
    cin >> n;
    cin >> s;
    for (int i = 0; i < n;i++){
        if(s[i]=='(')
            st.push('(');
        else{
            if(!st.size()){
                cout << "No";
                return;
            }
            st.pop();
        }
    }
    cout << (st.size() ? "No" : "Yes");
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
*/