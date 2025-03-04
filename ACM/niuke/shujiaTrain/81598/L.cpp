#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char s[13][13];
char ans[13][13];
void solve(){
    bool tag = false;
    for (int i = 1; i <= 9;i++)
        for (int j = 1; j <= 9;j++){
            cin >> s[i][j];
            ans[i][j] = '*';
            if(!(i==1||j==1||i==9||j==9))
                if(s[i][j]=='8'&&!tag){
                    ans[i][j] = '8';
                    tag = true;
                }
        }
    for (int i = 1; i <= 9;i++){
        for (int j = 1; j <= 9;j++)
            cout << ans[i][j];
        cout << '\n';
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