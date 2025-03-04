#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
char ans[N][N];
void solve(){
    int row;
    cin >> row;
    cin.ignore();
    string s;
    getline(cin, s);
    int col;
    if(s.size()%row==0)
        col = s.size() / row;
    else
        col = s.size() / row + 1;
    int cnt = 0;
    for (int j = col; j >= 1;j--){
        for (int i = 1; i <= row;i++){
            if(s[cnt]=='\0')
                ans[i][j] = ' ';
            else{
                ans[i][j] = s[cnt];
                cnt++;
            }
        }
    }
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++)
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