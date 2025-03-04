#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool isop(char c){
    return c == '&' || c == '|';
}
int priority(char op){
    if(op=='&'||op=='|')
        return 1;
    return -1;
}
void process_op(stack<int> &st,char op){//操作数的栈,和当前运算符
    int r = st.top();
    st.pop();
    int l = st.top();
    st.pop();
    switch(op){
    case '&':
        st.push(min(l, r));
        break;
    case '|':
        st.push(max(l, r));
        break;
    }
}

int evaluate(string &s){
    stack<int> st;//操作数
    stack<char> op;//操作符
    for (int i = 0; i < s.size();i++){
        if(s[i]=='(')
            op.push('(');
        else if(s[i]==')'){
            while(op.top()!='('){
                process_op(st, op.top());
                op.pop();
            }
            op.pop();
        }
        else if(isop(s[i])){
            char cur_op = s[i];
            while(op.size()&&priority(op.top())>=priority(cur_op)){
                process_op(st, op.top());
                op.pop();
            }
            op.push(cur_op);
        }
        else{
            int number = 0;
            while(i<s.size()&&isdigit(s[i]))
                number = number * 10 + s[i++] - '0';
            i--;
            st.push(number);
        }
    }
    while(op.size()){
        process_op(st, op.top());
        op.pop();
    }
    return st.top();
}
void solve(){
    string s;
    cin >> s;
    cout << evaluate(s);
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