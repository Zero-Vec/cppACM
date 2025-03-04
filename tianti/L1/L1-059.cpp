#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s[8];
    string t[8];
    char ch;
    for (int i = 1; i <= 7;i++)
        cin >> t[i];
    for (int i = 1; i <= 7;i++)
        cin >> s[i];
    int pos1 = t[7].find("ong");
    //cout << pos1;
    int pos2=s[7].find("ong");
    if(pos1!=-1&&pos2!=-1){
        s[5] = "qiao", s[6] = "ben", s[7] = "zhong.";
        for (int i = 1; i <= 7;i++)
            cout<<t[i]<<' ';
        for (int i = 1; i <= 7;i++)
            cout << s[i] << ' ';
        cout << '\n';
    }
    else{
        cout << "Skipped\n";
    }
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