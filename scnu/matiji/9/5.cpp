#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int s2[N];
int cnt;
string s[N];

bool isop(string s){
    return s == "or" || s == "and" || s == "not";
}

int priority(string op){
    if(op=="or")
        return 1;
    if(op=="and")
        return 2;
    if(op=="not")
        return 3;
    return -1;
}

void process(stack<string> &st,string op){
    string l, r;
    r = st.top();
    st.pop();
    if(!st.empty())
        l = st.top();
    if(op=="not"){
        if(r=="true")
            st.push("false");
        else
            st.push("true");
    }
    if(op=="and"){
        st.pop();
        if(r=="true"&&l=="true")
            st.push("true");
        else
            st.push("false");
    }
    if(op=="or"){
        st.pop();
        if (r == "false"&&l=="false")
            st.push("false");
        else
            st.push("true");
    }
}

string evaluate(string *s,int cnt){
    stack<string> st;
    stack<string> op;
    for (int i = 0; i < cnt;i++){
        if(isop(s[i])){
            string cur_op = s[i];
            if(cur_op!="not")
                while(!op.empty() && priority(op.top()) >= priority(cur_op)){
                    process(st, op.top());
                    op.pop();
                }
            op.push(cur_op);
        }
        else{
            st.push(s[i]);
            while(!op.empty() && op.top() == "not"){
                process(st,op.top());
                op.pop();
            }
        }
    }
    while(!op.empty()){
        process(st, op.top());
        op.pop();
    }
    return st.top();
}

bool check(string *s,int cnt){
    if(s[0]=="or"||s[0]=="and"||s[cnt-1]=="or"||s[cnt-1]=="and"||s[cnt-1]=="not"){
        return 0;
    }
    for (int i = 0; i < cnt;i++){
        if(s[i]=="not"&&(s[i+1]=="or"||s[i+1]=="and"))
            return 0;
    }
    int cnt2 = 0;
    for (int i = 0; i < cnt;i++){
        if(s[i]=="or"||s[i]=="and")
            s2[cnt2++] = 1;
        else if(s[i]=="true"||s[i]=="false")
            s2[cnt2++] = 0;
        if(cnt2>=2&&((s2[cnt2-2]^1)!=s2[cnt2-1]))
            return 0;
    }
    return 1;
}
void solve(){
    while(cin>>s[cnt])
        cnt++;
    if(!check(s,cnt)){
        cout << "error";
        return;
    }
    cout << evaluate(s, cnt);
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