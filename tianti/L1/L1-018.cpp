#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    cin >> s;
    string k = s.substr(0, 2);
    string m = s.substr(3, 2);
    //cout << k;
    int hh = stoi(k);
    //cout << hh;
    if(hh<12||hh==12&&(m[0]=='0'&&m[1]=='0')){
        cout << "Only " << s << ".  Too early to Dang.";
    }
    else{
        int h = hh - 12;
        if (m[0] != '0' || m[1] != '0')h+=1;
        for (int i = 1; i <= h;i++)
            cout << "Dang";
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