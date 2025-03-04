#include<iostream>
#include<cmath>
#include<string>
using namespace std;
using ll = long long;
string s[60];
void solve(){
    //cout << sizeof('z' - 'a');
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
    }
    int ans = 205;
    for (int i = 1; i <= n - 1;i++){
        for (int j = i + 1; j <= n;j++){
            int t = 0;
            for (int k = 0; k < m;k++){
                t += abs(s[i][k] - s[j][k]);
            }
            ans = min(ans, t);
        }
    }
    cout << ans << '\n';
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