#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    string a = ".", b = ".";
    int cnt = 1;
    while(cin>>s&&s!="."){
        if(cnt==2)
            a = s;
        if(cnt==14)
            b = s;
        cnt++;
    }
    if(a!="."&&b!="."){
        cout << a << " and " << b << " are inviting you to dinner...";
    }
    else if(a!="."&&b=="."){
        cout << a << " is the only one for you...";
    }
    else{
        cout << "Momo... No one is for you ...";
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