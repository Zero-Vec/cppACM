#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.size();i++){
        if(s[i]=='6')
            cnt++;
        else{
            if(cnt<=3){
                for (int j = 1; j <= cnt;j++)
                    cout << '6';
            }
            else if(cnt>9){
                cout << "27";
            }
            else{
                cout << '9';
            }
            cnt = 0;
            cout << s[i];
        }
    }
    if(cnt){
        if (cnt <= 3){
            for (int j = 1; j <= cnt; j++)
                cout << '6';
        }
        else if (cnt > 9){
            cout << "27";
        }
        else{
            cout << '9';
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