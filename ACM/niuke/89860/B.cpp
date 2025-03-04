#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s, a, b, c, d;
    a = "www.nowcoder.com", b = "https://www.nowcoder.com";
    c = "ac.nowcoder.com", d = "https://" + c;
    cin >> s;
    if(s.find(a) == 0 || s.find(b) == 0){
        cout << "Nowcoder\n";
    }   
    else if(s.find(c) == 0 || s.find(d) == 0){
        cout << "Ac\n";
    }
    else{
        cout << "No\n";
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