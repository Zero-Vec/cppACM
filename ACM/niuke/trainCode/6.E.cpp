#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
void solve(){
    string s;
    cin >> s;
    int y = stoi(s.substr(2)) / 2 + 1;
    string sk;
    cin >> sk;
    int cntR = 0, cntP = 0;
    int i;
    for (i = 0; i < sk.size();i++){
        if(sk[i]=='R')
            cntR++;
        if(sk[i]=='P')
            cntP++;
        if(cntR==y){
            cout << "kou!"<<"\n";
            cout << i + 1;
            return;
        }
        if(cntP==y){
            cout << "yukari!"<<"\n";
            cout << i + 1;
            return;
        }
    }
    cout << "to be continued." << '\n';
    cout << i;
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