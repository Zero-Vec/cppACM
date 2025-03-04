#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
char s[N];
int n, l, r, ans, tmp;
void solve(){
    cin >> s + 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n;i++){
        if(s[i]==')')
            r++;
        else
            l++;
    }
    if(l==r){
        cout << 0 << '\n';
        return;
    }
    if(l > r){
        int id;
        for (int i = n; i >= 1;i--){
            if(s[i]=='(')
                tmp++;
            else
                tmp--;
            if(tmp > 0){
                id = i;
                tmp = 0;
                break;
            }
        }
        for (int i = id; i <= n;i++){
            if(s[i]=='(')
                tmp++;
            else
                tmp--;
            if(tmp >= 1 && s[i] == '(')
                ans++;
        }
    }
    else{
        int id;
        for (int i = 1; i <= n;i++){
            if(s[i]==')')
                tmp++;
            else
                tmp--;
            if(tmp > 0){
                id = i;
                tmp = 0;
                break;
            }
        }
        for (int i = id; i >= 1;i--){
            if(s[i]==')')
                tmp++;
            else
                tmp--;
            if(tmp >= 1 && s[i] == ')')
                ans++;
        }
    }
    cout << ans << '\n';
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
// TLE做法：
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
char s[N];
int n, ans;
char getchar(char a){
    if(a==')')
        return '(';
    else
        return ')';
}
bool check(char s[]){
    stack<char> st;
    bool tag = true;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.empty())
            {
                tag = false;
                break;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.size())
        tag = false;
    return tag;
}
void solve(){
    cin >> s + 1;
    //先判断是否匹配
    n = strlen(s + 1);
    if(check(s)){
        cout << 0 << '\n';
        return;
    }
    int l = 0, r = 0;
    for (int i = 1; i <= n;i++){
        if(s[i]==')')
            r++;
        else
            l++;
    }
    if(l>r){
        //翻左括号
        for (int i = 1; i <= n;i++){
            if(s[i]==')')continue;
            char t = s[i];
            s[i] = getchar(s[i]);
            if(check(s))
                ans++;
            s[i] = t;
        }
    }
    else{
        //翻右括号
        for (int i = 1; i <= n;i++){
            if(s[i]=='(')continue;
            char t = s[i];
            s[i] = getchar(s[i]);
            if(check(s))
                ans++;
            s[i] = t;
        }
    }
    cout << ans << '\n';
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