#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3;i++){
        a += s[i] - '0';
    }
    for (int i = 3; i < 6;i++){
        b += s[i] - '0';
    }
    cout << (a == b ? "YES\n" : "NO\n");
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