#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isop(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
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

void process(string s){
    stack<int> st;
    bool change = false;
    for (int i = 0; i < s.size();i++){
        if(isop(s[i])){
            int r = st.top();
            st.pop();
            int l = st.top();
            st.pop();
            switch(s[i]){
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
            }
            change = true;
        }
        else{
            st.push(s[i] - '0');
            change = false;
        }
        //下面开始打印
        if(change){
            stack<int> tmp1, tmp2;
            tmp1 = st;
            while(!tmp1.empty())
                tmp2.push(tmp1.top()), tmp1.pop();
            while(!tmp2.empty())
                cout << tmp2.top() << " ", tmp2.pop();
            for (int j = i + 1; j < s.size();j++)
                cout << s[j] << " ";
            cout << '\n';
        }
    }
}

string toRPN(string s){//中缀转后缀
    stack<char> st;//结果
    stack<char> op;//操作符栈
    for (int i = 0; i < s.size();i++){
        if(s[i]=='('){
            op.push('(');
        }
        else if(s[i]==')'){
            while(op.top()!='('){
                st.push(op.top());
                op.pop();
            }
            op.pop();
        }
        else if(isop(s[i])){
            while(op.size() && priority(op.top()) >= priority(s[i])){
                st.push(op.top());
                op.pop();
            }
            op.push(s[i]);
        }
        else{
            st.push(s[i]);
        }
    }
    while(op.size()){
        st.push(op.top());
        op.pop();
    }
    string ans;
    int len = st.size();
    while(len--){
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    string s2 = toRPN(s);
    for (int i = 0; i < s2.size();i++)
        cout << s2[i] << " ";
    cout << '\n';
    process(s2);
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