#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string a, b;
int op(string s){
    int ans = 0;
    for (int i = 0; i < s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            ans = ans * 10 + (s[i] - '0');
        else{
            ans = 0;
            break;
        }
    }
    return ans;
}
void solve(){
    cin >> a;
    getchar();
    getline(cin, b);
    int x = op(a), y = op(b);
    //cout << b << '\n';
    if(1<=x&&x<=1000)
        cout << x;
    else
        cout << '?';
    cout << " + ";
    if(1<=y&&y<=1000)
        cout << y;
    else
        cout << '?';
    cout << " = ";
    if ((1 <= x && x <= 1000) && (1 <= y && y <= 1000))
        cout << x + y;
    else
        cout << '?';
}
int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}