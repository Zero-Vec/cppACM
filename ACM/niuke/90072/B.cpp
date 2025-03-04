#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
string s;
int n;
void solve(){
    cin >> n;
    cin >> s;
    s = ' ' + s;
    stack<char> st;
    for (int i = 1; i <= n;i++){
        st.push(s[i]);
        if(st.size() > 1){
            char ch1 = st.top();
            st.pop();
            char ch2 = st.top();
            st.pop();
            if((ch2 == 'f' && ch1 == 'c') || (ch2 == 't' && ch1 == 'b'))
                continue;
            st.push(ch2);
            st.push(ch1);
        }
    }
    cout << st.size() << '\n';
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
const int N = 1e6 + 9;
char s[N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
    stack<char> st;
    ll cnt = 0;
    for (int i = 1; i <= n;i++){
        if(s[i] != 'c' && s[i] != 'b'){
            st.push(s[i]);
        }
        else{
            if(st.size() == 0){
                continue;
            }
            else{
                if(s[i] == 'c'){
                    if(st.top() == 'f'){
                        cnt++;
                        st.pop();
                    }
                    else
                        st.push(s[i]);
                }
                else if(s[i] == 'b'){
                    if(st.top() == 't'){
                        cnt++;
                        st.pop();
                    }
                    else
                        st.push(s[i]);
                }
            }
        }
    }
    cout << n - 2 * cnt << '\n';
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