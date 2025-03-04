#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 9;
char s[N], p[N];
int nex[N];
void solve(){
    int m;
    cin >> m;
    int n = 2 * m;
    cin >> s + 1;
    cin >> p + 1;
    for (int i = 1; i <= m;i++){
        if(isupper(p[i]))p[i]=tolower(p[i]);
        else    p[i]=toupper(p[i]);
        s[i + m] = s[i];
    }
    for (int i = 2, j = 0; i <= m;i++){
        while(j&&p[i]!=p[j+1])j=nex[j];
        if(p[i]==p[j+1])j++;
        nex[i] = j;
    }
    int mn = 1e9;
    for (int i = 1, j = 0; i <= n;i++){
        while(j&&s[i]!=p[j+1])j=nex[j];
        if(s[i]==p[j+1])j++;
        if(j==m){
            mn = min({mn, i - m, 2 * m - i});
        }
    }
    if(mn==1e9){
        cout << "No";
    }
    else{
        cout << "Yes\n"<< mn;
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