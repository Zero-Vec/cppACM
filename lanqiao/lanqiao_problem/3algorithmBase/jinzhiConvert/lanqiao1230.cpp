#include<bits/stdc++.h>
using namespace std;
int a[15];
char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
void solve(){
    int n, m;
    cin >> n >> m;
    string s;//s表示n进制数
    cin >> s;
    long long x = 0;
    for (int i = 0; i < s.length();i++){
        if('0'<=s[i]&&s[i]<='9')
            a[i] = s[i] - '0';
        else
            a[i] = s[i] - 'A' + 10;
        x = x * n + a[i];
    }
    string ans;
    while(x){
        ans += ch[x % m];
        x /= m;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
int main()
{
    //任意进制转换
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}