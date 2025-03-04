#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    queue<string> V;
    queue<string> N;
    int m;
    cin >> m;
    while(m--){
        string op;
        cin >> op;
        if(op=="IN"){
            string name;
            cin >> name;
            char a;
            cin >> a;
            if(a=='V')
                V.push(name);
            else
                N.push(name);
        }
        else{
            char a;
            cin >> a;
            if (a == 'V')
                V.pop();
            else
                N.pop();
        }
    }
    while(V.size()){
        cout << V.front() << "\n";
        V.pop();
    }
    while(N.size()){
        cout << N.front() << "\n";
        N.pop();
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