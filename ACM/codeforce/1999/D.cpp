#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
char s[N], t[N], ans[N];
void solve(){
    cin >> s + 1;
    cin >> t + 1;
    int ls = strlen(s + 1), ts = strlen(t + 1);
    memset(ans, '\0', sizeof ans);
    int i, j;
    for (i = 1, j = 1; i <= ls;i++){
        if(j==ts+1){
            if(s[i]=='?')
                ans[i] = 'a';
            else
                ans[i] = s[i];
            continue;
            // break;
        }
        if(s[i]=='?'||s[i]==t[j]){
            ans[i] = t[j++];
        }
        else
            ans[i] = s[i];
    }
    cout << (j == ts + 1 ? "YES" : "NO") << '\n';
    if(j==ts+1){
        for (int k = 1; k <= ls;k++)
            cout << ans[k];
        cout << '\n';
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