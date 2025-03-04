#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//len-nex[len]表示模式串中的最短循环节长度
const int N = 1e6 + 9;
char s[N];
int nex[N];
void solve(){
    cin >> s + 1;
    int m = strlen(s + 1);
    nex[0] = nex[1] = 0;
    for (int i = 2, j = 0; i <= m;i++){
        while(j&&s[i]!=s[j+1])j=nex[j];
        if(s[i]==s[j+1])j++;
        nex[i] = j;
    }
    int n = m - nex[m];//n为最短循环节的长度
    if(m%n==0){
        cout << m / n;
    }
    else{
        cout << 1;
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