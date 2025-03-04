#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, op, id, tid;
string s;
struct no1{
    int i, id, re;
};
struct no2{
    int i, re;
};
bool v[N];
queue<no1> q;
stack<no2> st[int(1e5)+9];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> op;
        if(op==1){
            no1 n1;
            cin >> tid >> s;
            n1.i = i, n1.id = tid, n1.re = (s[0] == 'C');
            q.push(n1);
            no2 n2;
            n2.i = i, n2.re = (s[0] == 'C');
            st[tid].push(n2);
        }
        else{
            if(id){
                while(st[id].size()&&v[st[id].top().i])
                    st[id].pop();
                if(st[id].size()){
                    no2 t = st[id].top();
                    st[id].pop();
                    cout << t.i << '\n';
                    v[t.i] = true;
                    if(t.re==0)
                        id = 0;
                    continue;
                }
            }
            while(q.size()&&v[q.front().i])
                q.pop();
            if(q.size()){
                no1 t = q.front();
                q.pop();
                cout << t.i << '\n';
                v[t.i] = true;
                if(t.re==1)
                    id = t.id;
                else
                    id = 0;
            }
            else{
                cout << "NOTHING HAPPENED" << '\n';
                id = 0;
            }
        }
    }
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