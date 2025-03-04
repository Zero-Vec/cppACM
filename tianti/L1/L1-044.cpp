#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    int k;
    cin >> k;
    int cnt = 0;
    while(cin>>s&&s!="End"){
        if(cnt==k){
            cout << s << '\n';
            cnt = 0;
            continue;
        }
        if(s[0]=='C'){
            cout << "Bu" << '\n';
        }
        else if(s[0]=='J'){
            cout << "ChuiZi" << '\n';
        }
        else{
            cout << "JianDao" << '\n';
        }
        cnt++;
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