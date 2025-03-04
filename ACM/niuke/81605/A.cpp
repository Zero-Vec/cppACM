#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char s[6];
void solve(){
    cin >> s + 1;
    int cy = 0, cn = 0;
    for (int i = 1; i <= 5;i++){
        if(s[i]=='Y')
            cy++;
        else if(s[i]=='N')
            cn++;
        else
            break;
    }
    if(cy>=4)
        cout << 1 << '\n';
    else if(cn>=2)
        cout << -1;
    else
        cout << 0;
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