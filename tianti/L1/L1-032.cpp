#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
char ch;
string s;
void solve(){
    /*
    string s;
    getline(cin,s);
    cout<<s.size()<<'\n';
    cout << s;
    */
    cin >> n >> ch;
    cin.ignore();
    getline(cin, s);
    /*
    cout << s.size() << '\n';
    cout << s;
    */
    int siz = s.size();
    if(siz==n){
        cout << s;
    }
    else if(siz<n){
        for (int i = 0; i < n - siz;i++)
            cout << ch;
        cout << s;
    }
    else{
        for (int i = siz - n; i < siz;i++)
            cout << s[i];
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