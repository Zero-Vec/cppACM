#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
void solve(){
    cin >> s;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < s.size();i++){
        if(s[i]=='3'){
            c1++, c2++;
        }
        else if(s[i]=='4'){
            c1 = 0, c2++;
        }
        else if(s[i]=='5'){
            if(c3==1){
                cout << "invalid" << '\n';
                return;
            }
            c3 = 1, c1 = 0, c2 = 0;
        }
        else{
            c3 = 2, c1 = 0, c2 = 0;
        }
        if(c1>=10||c2>=90){
            cout << "invalid" << '\n';
            return;
        }
    }
    cout << "valid" << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}