#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
char s[N][5];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= 4;j++)
            cin >> s[i][j];
    for (int i = n; i >= 1;i--){
        for (int j = 1; j <= 4;j++){
            if(s[i][j] == '#'){
                cout << j << " ";
                break;
            }
        }
    }
    cout << '\n';
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