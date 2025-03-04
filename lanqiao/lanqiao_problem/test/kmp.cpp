#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
char s[N],p[N];
int nex[N];
void solve(){
    cin >> p + 1;
    cin >> s + 1;
    nex[0] = nex[1] = 0;
    int n = strlen(s + 1), m = strlen(p + 1);
    //get nex数组
    for (int i = 2, j = 0; i <= m;i++){
        while(j&&p[i]!=p[j+1])j=nex[j];
        if(p[i]==p[j+1])j++;
        nex[i] = j;
    }
    //计算字串
    int ans = 0;
    for (int i = 1, j = 0; i <= n;i++){
        while(j&&s[i]!=p[j+1])j=nex[j];
        if(s[i]==p[j+1])j++;
        if(j==m)ans++;
    }
    cout << ans;
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