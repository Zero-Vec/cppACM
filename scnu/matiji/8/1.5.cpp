#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 39;
bool tag[N];

bool isop(char c){
    return c == '+' || c == '-' || c == '*' || c == '^' || c == '/';
}

int priority(char op){
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    if(op=='^')
        return 3;
    return -1;
}

void process_op(stack<int> &st,char op){
    int r = st.top();
    st.pop();
    int l = st.top();
    st.pop();
    switch(op){
    case '+':
        st.push(l + r);
        break;
    case '-':
        st.push(l - r);
        break;
    case '*':
        st.push(l * r);
        break;
    case '/':
        st.push(l / r);
        break;
    case '^':
        st.push(pow(l, r));
        break;
    }
}

void init(string &s){
    stack<pair<char, int>> st;
    for (int i = 0; i < s.size();i++){
        if(st.size()&&st.top().first=='('&&s[i]==')'){
            tag[i] = tag[st.top().second] = true;
            st.pop();
        }
        else if(s[i]=='(')
            st.push({'(', i});
    }
}

int evaluate(string &s){
    stack<char> op;
    stack<int> st;
    for (int i = 0; i < s.size();i++){
        if(s[i]=='('){
            if(!tag[i])continue;
            op.push('(');
        }
        else if(s[i]==')'){
            if(!tag[i])continue;
            while(op.top()!='('){
                process_op(st, op.top());
                op.pop();
            }
            op.pop();
        }
        else if(isop(s[i])){
            char tmp = s[i];
            while(op.size()&&priority(op.top())>=priority(tmp)){
                process_op(st, op.top());
                op.pop();
            }
            op.push(tmp);
        }
        else{
            int number = 0;
            while(i<s.size()&&isdigit(s[i])){
                number = number * 10 + s[i] - '0';
                i++;
            }
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
    init(s);
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