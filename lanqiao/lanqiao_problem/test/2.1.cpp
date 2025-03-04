#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size() - 1;i++){
        if(i&1){
            if(s[i]=='A')
                a++;
            else
                b++;
        }
        else{
            if(s[i]=='B')
                a++;
            else
                b++;
        }
    }
    cout << min(a, b) << '\n';
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