// https://codeforces.com/problemset/problem/1680/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
char s[N];
int p[N];
void solve(){
    cin >> s + 1;
    int n = strlen(s + 1);
    for (int i = 1; i <= n;i++)
        p[i] = p[i - 1] + (s[i] == '1');
    //枚举右端点r
    int ans = N;
    for (int i = 1; i <= n;i++){
        if(i>=p[n])
            ans = min(ans, p[n] - p[i] + p[i - p[n]]);
        else
            ans = min(ans, max(i - p[i], p[n] - p[i]));
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